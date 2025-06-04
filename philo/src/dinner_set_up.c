/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_set_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:52:11 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/03 23:58:08 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philosopher_routine(void* arg)
{
    return (arg);
}

void    init_table(t_dinner *dinner)
{
    int counter;

    counter = 0;
    while (counter < dinner->number_of_philosophers)
    {
        dinner->array_forks[counter].id = counter;
        dinner->array_forks[counter].status = 0;
        dinner->array_forks[counter].owner_id = -1;
        if (init_mutex(&dinner->array_forks[counter].mutex) != 0)
        {
            mutex_init_error(counter, dinner->array_forks);
            return ;
        }

        dinner->array_philosophers[counter].id = counter;
        dinner->array_philosophers[counter].status = PHILOSOPHER_THINKING;
        dinner->array_philosophers[counter].last_meal_ms = 0;
        dinner->array_philosophers[counter].number_of_meals = 0;
        dinner->array_philosophers[counter].left_fork = &dinner->array_forks[counter];
        dinner->array_philosophers[counter].right_fork = &dinner->array_forks[(counter + 1) % dinner->number_of_philosophers];
        dinner->array_philosophers[counter].dinner = dinner;
        pthread_create(&dinner->array_philosophers[counter].thread_id, NULL, philosopher_routine, &dinner->array_philosophers[counter]);

        counter++;
    }
}

int table_allocation(t_dinner *dinner)
{
    dinner->array_philosophers = malloc(sizeof(t_philosopher) * dinner->number_of_philosophers);
    if (!dinner->array_philosophers)
    {
        printf("Failed to allocated memory for philosophers");
        return(0);
    }
    dinner->array_forks = malloc(sizeof(t_fork) * dinner->number_of_philosophers);
    if (!dinner->array_forks)
    {
        printf("Failed to allocated memory for forks");
        free(dinner->array_philosophers);
        return(0);
    }
    return (1);
}

int set_up_dinner(t_dinner *dinner)
{
    if(!table_allocation(dinner))
        return (0);
    init_table(dinner);
    init_mutex(&dinner->logging_mutex);
    
    if (init_mutex(&dinner->array_forks[0].mutex) != 0)
    {
        mutex_init_error(1, dinner->array_forks);
        return (0);
    }
    dinner->dinner_started_ms = get_time_in_ms();
    printf("Current time in milliseconds: %lld\n", dinner->dinner_started_ms);

    //clean up function
    return (1);
}
