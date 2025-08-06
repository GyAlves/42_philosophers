/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_set_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:52:11 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/08/06 19:24:18 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_table(t_dinner *dinner)
{
	int	counter;

	counter = 0;
	if (dinner->last_error != SUCCESS)
		return ;
	while (counter < dinner->number_of_philosophers)
	{
		fork_allocation(dinner, counter);
		if (dinner->last_error != SUCCESS)
			return ;
		counter++;
	}
	counter = 0;
	while (counter < dinner->number_of_philosophers)
	{
		philosopher_allocation(dinner, counter);
		if (dinner->last_error != SUCCESS)
			return ;
		counter++;
	}
}

void	set_up_dinner(t_dinner *dinner)
{
	dinner->last_error = SUCCESS;
	dinner->initialization_complete = 0;
	dinner->initialized_mutexes = 0;
	dinner->created_forks = 0;
	dinner->created_threads = 0;
	dinner->dinner_started_ms = get_time_in_ms();
	init_mutex(&dinner->logging_mutex, dinner);
	if (dinner->last_error != SUCCESS)
		return ;
	table_allocation(dinner);
	init_table(dinner);
	if (dinner->last_error == SUCCESS)
		dinner->initialization_complete = 1;
	else
		cleanup_dinner(dinner);
}

void	table_allocation(t_dinner *dinner)
{
	dinner->array_philosophers = malloc(sizeof(t_philosopher)
			* dinner->number_of_philosophers);
	if (!dinner->array_philosophers)
	{
		dinner->last_error = ERROR_MALLOC_PHILOSOPHERS;
		return ;
	}
	dinner->array_forks = malloc(sizeof(t_fork)
			* dinner->number_of_philosophers);
	if (!dinner->array_forks)
	{
		dinner->last_error = ERROR_MALLOC_FORKS;
		free(dinner->array_philosophers);
		return ;
	}
}

void	philosopher_allocation(t_dinner *dinner, int counter)
{
	t_philosopher	*philo;
	int				status;

	philo = &dinner->array_philosophers[counter];
	philo_init(dinner, counter);
	init_mutex(&philo->death_mutex, dinner);
	status = pthread_create(&philo->thread_id, NULL, \
							philosopher_routine, philo)
		if (status != 0)
	{
		dinner->last_error = ERROR_THREAD_CREATE;
		return ;
	}
	if (dinner->time_to_die_ms <= (dinner->time_to_eat_ms
			+ dinner->time_to_sleep_ms + 20))
		usleep(counter * 200);
	else if (dinner->time_to_die_ms < 500)
		usleep(counter * 50);
	else if (counter % 2 == 1 && dinner->time_to_die_ms < 1000)
		usleep(100);
	dinner->created_threads += 1;
}

void	philo_init(t_dinner *dinner, int counter)
{
	t_philosopher	*philo;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				philos_count;

	philos_count = dinner->number_of_philosophers;
	left_fork = &dinner->array_forks[counter];
	right_fork = &dinner->array_forks[(counter + 1) % philos_count];
	philo = &dinner->array_philosophers[counter];
	philo->id = counter;
	philo->status = PHILOSOPHER_THINKING;
	philo->last_meal_ms = dinner->dinner_started_ms;
	philo->number_of_meals = 0;
	philo->is_dead = 0;
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
	philo->dinner = dinner;
}
