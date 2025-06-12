/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_set_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:52:11 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/12 19:19:17 by galves-a         ###   ########.fr       */
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
	dinner->array_philosophers[counter].id = counter;
	dinner->array_philosophers[counter].status = PHILOSOPHER_THINKING;
	dinner->array_philosophers[counter].last_meal_ms
		= dinner->dinner_started_ms;
	dinner->array_philosophers[counter].number_of_meals = 0;
	dinner->array_philosophers[counter].is_dead = 0;
	dinner->array_philosophers[counter].left_fork
		= &dinner->array_forks[counter];
	dinner->array_philosophers[counter].right_fork
		= &dinner->array_forks[(counter + 1) % dinner->number_of_philosophers];
	dinner->array_philosophers[counter].dinner = dinner;
	init_mutex(&dinner->array_philosophers[counter].death_mutex, dinner);
	if (pthread_create(&dinner->array_philosophers[counter].thread_id, NULL,
			philosopher_routine, &dinner->array_philosophers[counter]) != 0)
	{
		dinner->last_error = ERROR_THREAD_CREATE;
		return ;
	}
	dinner->created_threads += 1;
}