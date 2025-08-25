/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/08/20 19:10:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*handle_philosopher_death(t_dinner *dinner, int i)
{
	pthread_mutex_lock(&dinner->array_philosophers[i].death_mutex);
	if (!dinner->array_philosophers[i].is_dead && !dinner->dinner_ended)
	{
		dinner->array_philosophers[i].is_dead = 1;
		dinner->dinner_ended = 1;
		pthread_mutex_unlock(&dinner->array_philosophers[i].death_mutex);
		logging_philo_death_status(dinner, dinner->array_philosophers[i].id,
			get_time_in_ms() - dinner->dinner_started_ms);
		return (dinner);
	}
	pthread_mutex_unlock(&dinner->array_philosophers[i].death_mutex);
	return (NULL);
}

static int	check_philosophers_status(t_dinner *dinner)
{
	int	i;
	void	*result;

	i = 0;
	while (i < dinner->number_of_philosophers && !dinner->dinner_ended)
	{
		if (is_philosopher_dead(&dinner->array_philosophers[i]))
		{
			result = handle_philosopher_death(dinner, i);
			if (result)
				return (1);
		}
		i++;
	}
	return (0);
}

static void	handle_all_satisfied(t_dinner *dinner)
{
	dinner->dinner_ended = 1;
	pthread_mutex_lock(&dinner->logging_mutex);
	printf("All philosophers have eaten enough times\n");
	pthread_mutex_unlock(&dinner->logging_mutex);
	usleep(10000);
}

void	*death_monitor(void *arg)
{
	t_dinner	*dinner;

	dinner = (t_dinner *)arg;
	while (!dinner->dinner_ended)
	{
		if (check_philosophers_status(dinner))
			return (dinner);
		if (all_philosophers_satisfied(dinner))
		{
			handle_all_satisfied(dinner);
			break;
		}
		usleep(5);
	}
	return (dinner);
}
