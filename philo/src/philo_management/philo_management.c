/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:42:43 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/11 21:53:27 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_philosopher_dead(t_philosopher *philo)
{
    int is_dead;

    is_dead = 0;
    if (philo->number_of_meals == 0)
        is_dead = (get_time_in_ms() - philo->dinner->dinner_started_ms) > philo->dinner->time_to_die_ms;
    else
        is_dead = (get_time_in_ms() - philo->last_meal_ms) > philo->dinner->time_to_die_ms;
    
    return (is_dead);
}

int read_death_mutex(t_philosopher *philo)
{
    int philo_death_status;

    pthread_mutex_lock(&philo->death_mutex);
    philo_death_status = philo->is_dead;
    pthread_mutex_unlock(&philo->death_mutex);
    return (philo_death_status);
}

void    write_death_mutex(t_philosopher *philo, int death_mutex_value)
{
    pthread_mutex_lock(&philo->death_mutex);
    philo->is_dead = death_mutex_value;
    pthread_mutex_unlock(&philo->death_mutex);
}

int philo_vitals(t_philosopher *philo)
{
    if (is_philosopher_dead(philo))
    {
        write_death_mutex(philo, 1);
        logging_philo_status(philo->dinner, "died", philo->id);
        return (0);
    }
    return (1);
}