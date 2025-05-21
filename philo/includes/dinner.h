/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:04:06 by galves-a          #+#    #+#             */
/*   Updated: 2025/05/20 20:49:11 by galves-a         ###   ########.fr       */
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

#endif