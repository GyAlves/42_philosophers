/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/11 22:10:29 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *death_monitor(void *arg)
{
    int         philo_counter;
    t_dinner    *dinner;

    dinner = (t_dinner*)arg;

    while (!dinner->dinner_ended)
    {
        philo_counter = 0;
        while (philo_counter < dinner->number_of_philosophers)
        {
            if (read_death_mutex(&dinner->array_philosophers[philo_counter]))
            {
                dinner->dinner_ended = 1;
                break;
            }
            philo_counter++;
        }
    }
    return (dinner);
}