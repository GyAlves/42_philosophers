/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_set_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:52:11 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/02 18:11:59 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philosopher_routine(void)
{
    return ;
}

void    init_table(t_dinner *dinner)
{
    int counter;

    counter = 0;
    while (counter < dinner->number_of_philosophers)
    {
        /* Forks Init */
        dinner->array_forks[counter].id = counter;
        dinner->array_forks[counter].status = 0;
        dinner->array_forks[counter].owner_id = -1;
        pthread_mutex_init(&dinner->array_forks[counter].mutex, NULL);

        /* Philosophers Init */
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

void table_allocation(t_dinner *dinner)
{
    dinner->array_philosophers = malloc(sizeof(t_philosopher) * dinner->number_of_philosophers);
    if (!dinner->array_philosophers)
    {
        perror("Failed to allocate memory for philosophers");
        exit();
    }
    dinner->array_forks = malloc(sizeof(t_fork) * dinner->number_of_philosophers);
    if (!dinner->array_forks)
    {
        perror("Failed to allocate memory for forks");
        free(dinner->array_philosophers);
        exit();
    }
}

void    set_up_dinner(t_dinner *dinner)
{
    table_allocation(dinner);
    init_table(dinner);
    
    // init logging mutex
}
