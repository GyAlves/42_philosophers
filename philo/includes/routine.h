/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:55:42 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/12 19:15:30 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

/* Functions */
void    *philosopher_routine(void* arg);
int     philosopher_think(t_philosopher *philo);
int     philosopher_eat(t_philosopher *philo);
int     philosopher_sleep(t_philosopher *philo);
int     is_philosopher_dead(t_philosopher *philo);


#endif