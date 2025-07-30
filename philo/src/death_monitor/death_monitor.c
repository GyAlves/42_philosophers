/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/07/30 19:17:24 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			if (is_philosopher_dead(philo))
			{
				pthread_mutex_lock(philo.death_mutex);
				if (!philo.is_dead && !dinner->dinner_ended)
				{
					philo.is_dead = 1;
					dinner->dinner_ended = 1;
					pthread_mutex_unlock(philo.death_mutex);
					logging_philo_death_status(dinner, philo.id,
						get_time_in_ms() - dinner->dinner_started_ms);
					return (dinner);
				}
				pthread_mutex_unlock(philo.death_mutex);
			}
			counter++;
		}
		if (all_philosophers_satisfied(dinner))
		{
			dinner->dinner_ended = 1;
			pthread_mutex_lock(&dinner->logging_mutex);
			printf("All philosophers have eaten enough times\n");
			pthread_mutex_unlock(&dinner->logging_mutex);
			break;
		}
		usleep(dinner->time_to_die_ms < 1000 ? 500 : 1000);
	}
	return (dinner);
}
