/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/08 19:15:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *death_monitor(void *arg)
{
    t_dinner    *dinner;
    int         i;
    long long   current_time;
    long long   time_since_last_meal;

    dinner = (t_dinner*)arg;
    while (!dinner->dinner_ended)
    {
        i = 0;
        while (i < dinner->number_of_philosophers)
        {
            current_time = get_time_in_ms();
            time_since_last_meal = current_time - dinner->array_philosophers[i].last_meal_ms;
            
            if (time_since_last_meal > dinner->time_to_die_ms)
            {
                dinner->dinner_ended = 1;
                logging_philo_status(dinner, "died\n", dinner->array_philosophers[i].id);
                return (NULL);
            }
            i++;
        }
        usleep(1000); // Check every 1ms for accuracy
    }
    return (NULL);
}