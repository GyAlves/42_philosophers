/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:04:06 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/03 17:57:44 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DINNER_H
# define DINNER_H

# include "philosopher.h"
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
    
    t_philosopher   *array_philosophers;
    t_fork          *array_forks;
    
} t_dinner;

/* Functions */
void    *philosopher_routine(void* arg);
void    init_table(t_dinner *dinner);
void    table_allocation(t_dinner *dinner);
void    set_up_dinner(t_dinner *dinner);

#endif