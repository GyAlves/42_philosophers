/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:15:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/12 19:26:10 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *death_monitor(void *arg)
{
    t_dinner    *dinner;

    dinner = (t_dinner*)arg;

    while (!dinner->dinner_ended)
    {
        if (all_philosophers_satisfied(dinner))
        {
            dinner->dinner_ended = 1;
            pthread_mutex_lock(&dinner->logging_mutex);
            printf("All philosophers have eaten enough times\n");
            pthread_mutex_unlock(&dinner->logging_mutex);
            break;
        }
        usleep(100);
    }
    return (dinner);
}