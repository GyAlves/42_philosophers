/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/08/15 19:35:47 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*death_monitor(void *arg)
{
	t_dinner	*dinner;
	int			i;

	dinner = (t_dinner *)arg;
	while (!dinner->dinner_ended)
	{
		i = 0;
		while (i < dinner->number_of_philosophers && !dinner->dinner_ended)
		{
			if (is_philosopher_dead(&dinner->array_philosophers[i]))
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
			}
			i++;
		}
		if (all_philosophers_satisfied(dinner))
		{
			dinner->dinner_ended = 1;
			pthread_mutex_lock(&dinner->logging_mutex);
			printf("All philosophers have eaten enough times\n");
			pthread_mutex_unlock(&dinner->logging_mutex);
			usleep(10000);
			break;
		}
		usleep(1000);
	}
	return (dinner);
}