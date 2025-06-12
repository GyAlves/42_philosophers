/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:48:17 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/12 19:50:53 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    cleanup_threads(t_dinner *dinner)
{
    int         counter;
    pthread_t   thread_id;

    counter = 0;
    while (counter < dinner->created_threads)
    {
        thread_id = dinner->array_philosophers[counter].thread_id;
        if (pthread_join(thread_id, NULL) != 0)
        {
            pthread_cancel(thread_id);
            pthread_join(thread_id, NULL);
        }
        counter++;
    }
}

void    cleanup_dinner(t_dinner *dinner)
{
    if (dinner->created_threads > 0)
        dinner->dinner_ended = 1;

    cleanup_threads(dinner);
    if (dinner->created_forks > 0)
        mutex_init_error(dinner->created_forks, dinner->array_forks);
        
    pthread_mutex_destroy(&dinner->logging_mutex);
        
    if(dinner->array_philosophers)
    {
        free(dinner->array_philosophers);
        dinner->array_philosophers = NULL;
    }
    if (dinner->array_forks)
    {
        free(dinner->array_forks);
        dinner->array_forks = NULL;
    }
    dinner->created_threads = 0;
    dinner->created_forks = 0;    
}