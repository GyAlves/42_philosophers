/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/08 22:58:49 by gyasminalve      ###   ########.fr       */
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
        while (philo_counter <= dinner->number_of_philosophers)
        {
            
            philo_counter++;
        }
        /*
            - Loop over the array of philosophers
                - Verify the last time the philo ate 
                - Verify if anyone has exceeded time to die
                    - Set the flag dinner_ended to true and leave the cycle ? 
        */
    }

    return (dinner);
}