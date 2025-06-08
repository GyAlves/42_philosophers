/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:29:38 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/08 17:53:26 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    table_allocation(t_dinner *dinner)
{
    dinner->array_philosophers = malloc(sizeof(t_philosopher) * dinner->number_of_philosophers);
    if (!dinner->array_philosophers)
    {
        dinner->last_error = ERROR_MALLOC_PHILOSOPHERS;
        return ;
    }
    dinner->array_forks = malloc(sizeof(t_fork) * dinner->number_of_philosophers);
    if (!dinner->array_forks)
    {
        dinner->last_error = ERROR_MALLOC_FORKS;
        free(dinner->array_philosophers);
        return ;
    }
}

void    philosopher_allocation(t_dinner *dinner, int counter)
{
    dinner->array_philosophers[counter].id = counter;
    dinner->array_philosophers[counter].status = PHILOSOPHER_THINKING;
    dinner->array_philosophers[counter].last_meal_ms = 0;
    dinner->array_philosophers[counter].number_of_meals = 0;
    dinner->array_philosophers[counter].left_fork = &dinner->array_forks[counter];
    dinner->array_philosophers[counter].right_fork = &dinner->array_forks[(counter + 1) % dinner->number_of_philosophers];
    dinner->array_philosophers[counter].dinner = dinner;
    
    if (pthread_create(&dinner->array_philosophers[counter].thread_id, NULL, philosopher_routine, &dinner->array_philosophers[counter]) != 0)
    {
        dinner->last_error = ERROR_THREAD_CREATE;
        return ;
    }
    dinner->created_threads += 1;
}