/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:54:53 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/12 19:25:58 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (!philo->dinner->dinner_ended && !read_death_mutex(philo))
	{
		if (!philosopher_think(philo))
			break ;
		if (!philosopher_eat(philo))
			break ;
		if (!philosopher_sleep(philo))
			break ;
	}
	return (philo);
}

int	philosopher_think(t_philosopher *philo)
{
	if (!philo_vitals(philo))
		return (0);
	if (philo->status != PHILOSOPHER_THINKING)
		philo->status = PHILOSOPHER_THINKING;
	logging_philo_status(philo->dinner, "is thinking\n", philo->id);
	usleep(30000);
	return (1);
}

int	philosopher_eat(t_philosopher *philo)
{
	if (!philo_vitals(philo))
		return (0);
	hold_forks(philo);
	if (philo->dinner->dinner_ended || read_death_mutex(philo))
	{
		release_forks(philo);
		return (0);
	}
	philo->status = PHILOSOPHER_EATING;
	philo->last_meal_ms = get_time_in_ms();
	logging_philo_status(philo->dinner, "is eating\n", philo->id);
	usleep(philo->dinner->time_to_eat_ms * 1000);
	philo->number_of_meals++;
	release_forks(philo);
	return (1);
}

int	philosopher_sleep(t_philosopher *philo)
{
	if (!philo_vitals(philo))
		return (0);
	philo->status = PHILOSOPHER_SLEEPING;
	logging_philo_status(philo->dinner, "is sleeping\n", philo->id);
	usleep(philo->dinner->time_to_sleep_ms * 1000);
	return (1);
}