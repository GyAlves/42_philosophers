/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:54:53 by galves-a          #+#    #+#             */
/*   Updated: 2025/08/15 19:35:47 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	int				cycle_time;
	int				time_margin;

	philo = (t_philosopher *)arg;
	philo->last_meal_ms = get_time_in_ms();
	if (philo->dinner->number_of_philosophers == 1)
	{
		logging_philo_status(philo->dinner, "is thinking\n", philo->id);
		logging_philo_status(philo->dinner, "has taken a fork\n", philo->id);
		while (!philo->dinner->dinner_ended && !read_death_mutex(philo))
			usleep(1000);
		return (philo);
	}
	cycle_time = philo->dinner->time_to_eat_ms + philo->dinner->time_to_sleep_ms;
	time_margin = philo->dinner->time_to_die_ms - cycle_time;
	if (philo->dinner->number_of_philosophers % 2 == 1 && philo->id == philo->dinner->number_of_philosophers - 1)
		usleep(philo->dinner->time_to_eat_ms * 1000);
	else if (philo->id % 2 == 1 && time_margin >= 20)
		usleep(philo->dinner->time_to_eat_ms * 1000 / 2);
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
	if (!philo_vitals(philo))
		return (0);
	if (!hold_forks(philo))
		return (0);
	if (philo->dinner->dinner_ended || read_death_mutex(philo))
	{
		release_forks(philo);
		return (0);
	}
	if (!philo_vitals(philo))
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
	int	sleep_time;
	int	check_interval;

	if (!philo_vitals(philo))
		return (0);
	philo->status = PHILOSOPHER_SLEEPING;
	logging_philo_status(philo->dinner, "is sleeping\n", philo->id);
	sleep_time = philo->dinner->time_to_sleep_ms * 1000;
	check_interval = 1000;
	while (sleep_time > 0 && !philo->dinner->dinner_ended)
	{
		usleep(check_interval < sleep_time ? check_interval : sleep_time);
		sleep_time -= check_interval;
	}
	return (1);
}