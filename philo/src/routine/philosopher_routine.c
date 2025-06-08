/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:54:53 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/08 19:12:44 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philosopher_routine(void* arg)
{
    t_philosopher   *philo;

    philo = (t_philosopher*)arg;

    while(1)
    {
        philosopher_think(philo);
        philosopher_eat(philo);
        philosopher_sleep(philo);
    }
    return (philo);
}

void    philosopher_think(t_philosopher *philo)
{
    if (philo->status != PHILOSOPHER_THINKING)
        philo->status = PHILOSOPHER_THINKING;
        
    logging_philo_status(philo->dinner, "is now thinking\n", philo->id);
    usleep(30000);
}

void    philosopher_eat(t_philosopher *philo)
{
    hold_forks(philo);
    
    philo->status = PHILOSOPHER_EATING;
    logging_philo_status(philo->dinner, "is now eating\n", philo->id);
    usleep(philo->dinner->time_to_eat_ms * 1000);
    
    release_forks(philo);
}

void    philosopher_sleep(t_philosopher *philo)
{
    philo->status = PHILOSOPHER_SLEEPING;
    logging_philo_status(philo->dinner, "is now sleeping\n", philo->id);
    usleep(philo->dinner->time_to_sleep_ms * 1000);
}
