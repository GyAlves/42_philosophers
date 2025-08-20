/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:30:16 by galves-a          #+#    #+#             */
/*   Updated: 2025/08/15 19:21:15 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	logging_philo_status(t_dinner *dinner, char *message, int philo_id)
{
	long long	timestamp;

	if (dinner->dinner_ended)
		return ;
	timestamp = get_time_in_ms() - dinner->dinner_started_ms;
	pthread_mutex_lock(&dinner->logging_mutex);
	if (!dinner->dinner_ended)
		printf("%lld %d %s", timestamp, philo_id, message);
	pthread_mutex_unlock(&dinner->logging_mutex);
}

void	logging_philo_death_status(t_dinner *dinner, int philo_id,
		long long time_of_death)
{
	pthread_mutex_lock(&dinner->logging_mutex);
	printf("%lld %d died\n", time_of_death, philo_id);
	pthread_mutex_unlock(&dinner->logging_mutex);
}