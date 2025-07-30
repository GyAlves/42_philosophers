/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/07/30 20:53:28 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philosopher_death(t_dinner *dinner, t_philosopher *philo)
{
	if (is_philosopher_dead(philo))
	{
		pthread_mutex_lock(&philo->death_mutex);
		if (!philo->is_dead && !dinner->dinner_ended)
		{
			philo->is_dead = 1;
			dinner->dinner_ended = 1;
			pthread_mutex_unlock(&philo->death_mutex);
			logging_philo_death_status(dinner, philo->id,
				get_time_in_ms() - dinner->dinner_started_ms);
			return (1);
		}
		pthread_mutex_unlock(&philo->death_mutex);
	}
	return (0);
}

static int	check_philos_satisfied(t_dinner *dinner)
{
	if (all_philosophers_satisfied(dinner))
	{
		dinner->dinner_ended = 1;
		pthread_mutex_lock(&dinner->logging_mutex);
		printf("All philosophers have eaten enough times\n");
		pthread_mutex_unlock(&dinner->logging_mutex);
		return (1);
	}
	return (0);
}

void	*death_monitor(void *arg)
{
	t_dinner		*dinner;
	t_philosopher	*philo;
	int				counter;

	dinner = (t_dinner *)arg;
	while (!dinner->dinner_ended)
	{
		counter = 0;
		while (counter < dinner->number_of_philosophers)
		{
			philo = &dinner->array_philosophers[counter];
			if (check_philosopher_death(dinner, philo))
				return (dinner);
			counter++;
		}
		if (check_philos_satisfied(dinner))
			break ;
		if (dinner->time_to_die_ms < 1000)
			usleep(500);
		else
			usleep(1000);
	}
	return (dinner);
}
