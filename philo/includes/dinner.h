/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:04:06 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/04 21:44:56 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINNER_H
# define DINNER_H

# include "philosopher.h"
# include "error_handling.h"
# include "fork.h"

typedef struct s_dinner
{
    int number_of_philosophers;
    int number_of_meals;
    int dinner_ended;
    
    long long time_to_die_ms;
    long long time_to_eat_ms;
    long long time_to_sleep_ms;
    long long dinner_started_ms;

    pthread_mutex_t logging_mutex;
    pthread_t       death_monitor_thread;
    
    t_philosopher   *array_philosophers;
    t_fork          *array_forks;

    t_error_status_code last_error;
    int initialization_complete;
    int initialized_mutexes;
    int created_forks;
    int created_threads;
    
} t_dinner;

/* Functions */
void    *philosopher_routine(void* arg);
void    *death_monitor(void *arg);
void    init_table(t_dinner *dinner);
void    table_allocation(t_dinner *dinner);
void    set_up_dinner(t_dinner *dinner);
void    fork_allocation(t_dinner *dinner, int counter);
void    philosopher_allocation(t_dinner *dinner, int counter);

#endif