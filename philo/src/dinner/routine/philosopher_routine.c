/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:54:53 by galves-a          #+#    #+#             */
/*   Updated: 2025/08/19 22:15:47 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->dinner->number_of_philosophers == 1)
	{
		logging_philo_status(philo->dinner, "is thinking\n", philo->id);
		logging_philo_status(philo->dinner, "has taken a fork\n", philo->id);
		while (!philo->dinner->dinner_ended && !read_death_mutex(philo))
			usleep(1000);
		return (philo);
	}
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
	if (philo->dinner->number_of_philosophers > 4)
		usleep(1000);
	return (1);
}

int	philosopher_eat(t_philosopher *philo)
{
	if (philo->dinner->dinner_ended || read_death_mutex(philo))
		return (0);
	if (!hold_forks(philo))
		return (0);
	if (philo->dinner->dinner_ended || read_death_mutex(philo))
	{
		release_forks(philo);
		return (0);
	}
	philo->status = PHILOSOPHER_EATING;
	logging_philo_status(philo->dinner, "is eating\n", philo->id);
	pthread_mutex_lock(&philo->death_mutex);
	philo->last_meal_ms = get_time_in_ms();
	pthread_mutex_unlock(&philo->death_mutex);
	safe_usleep(philo->dinner->time_to_eat_ms, philo);
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
	safe_usleep(philo->dinner->time_to_sleep_ms, philo);
	return (1);
}