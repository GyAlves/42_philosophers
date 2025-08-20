/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:42:43 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/08/19 21:53:40 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philosopher_dead(t_philosopher *philo)
{
	long long	current_time;
	long long	time_since_last_meal;

	current_time = get_time_in_ms();
	time_since_last_meal = current_time - philo->last_meal_ms;
	
	// Only protect if they're eating AND started eating before the deadline
	if (philo->status == PHILOSOPHER_EATING && 
		time_since_last_meal <= philo->dinner->time_to_die_ms + 10)
		return (0);
		
	return (time_since_last_meal > philo->dinner->time_to_die_ms);
}

int	read_death_mutex(t_philosopher *philo)
{
	int	philo_death_status;

	pthread_mutex_lock(&philo->death_mutex);
	philo_death_status = philo->is_dead;
	pthread_mutex_unlock(&philo->death_mutex);
	return (philo_death_status);
}

void	write_death_mutex(t_philosopher *philo, int death_mutex_value)
{
	pthread_mutex_lock(&philo->death_mutex);
	philo->is_dead = death_mutex_value;
	pthread_mutex_unlock(&philo->death_mutex);
}

int	philo_vitals(t_philosopher *philo)
{
	if (philo->dinner->dinner_ended)
		return (0);
		
	if (is_philosopher_dead(philo))
	{
		pthread_mutex_lock(&philo->death_mutex);
		if (!philo->is_dead && !philo->dinner->dinner_ended)
		{
			philo->is_dead = 1;
			philo->dinner->dinner_ended = 1;
			pthread_mutex_unlock(&philo->death_mutex);
			logging_philo_death_status(philo->dinner, philo->id,
				get_time_in_ms() - philo->dinner->dinner_started_ms);
		}
		else
		{
			pthread_mutex_unlock(&philo->death_mutex);
		}
		return (0);
	}
	return (1);
}

int	all_philosophers_satisfied(t_dinner *dinner)
{
	int	counter;

	if (dinner->number_of_meals == -1)
		return (0);
	counter = 0;
	while (counter < dinner->number_of_philosophers)
	{
		if (dinner->array_philosophers[counter].number_of_meals
			< dinner->number_of_meals)
			return (0);
		counter++;
	}
	return (1);
}