/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_set_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:52:11 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/04 21:54:37 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_table(t_dinner *dinner)
{
    int counter;

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

void    set_up_dinner(t_dinner *dinner)
{
    dinner->last_error = SUCCESS;
    dinner->initialization_complete = 0;
    dinner->initialized_mutexes = 0;
    dinner->created_forks = 0;
    dinner->created_threads = 0;

    table_allocation(dinner);
    init_table(dinner);

    if (dinner->last_error == SUCCESS)
    {
        dinner->initialization_complete = 1;
        dinner->dinner_started_ms = get_time_in_ms();
    }
    else
        cleanup_dinner(dinner);
}