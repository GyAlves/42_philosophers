/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:46:02 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/12 19:15:30 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_in_ms(void)
{
	struct timeval	timestamp;
	long long		time_in_ms;

	gettimeofday(&timestamp, NULL);
	time_in_ms = (timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000);
	return (time_in_ms);
}

void	safe_usleep(unsigned long duration_ms, t_philosopher *philo)
{
	unsigned long	start;
	unsigned long	elapsed;

	start = get_time_in_ms();
	while ((elapsed = get_time_in_ms() - start) < duration_ms)
	{
		if (philo->dinner->dinner_ended || read_death_mutex(philo))
			return ;
		usleep(5);
	}
}