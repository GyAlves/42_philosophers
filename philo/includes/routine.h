/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:55:42 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/11 19:58:50 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

/* Functions */
void    *philosopher_routine(void* arg);
void    philosopher_think(t_philosopher *philo);
void    philosopher_eat(t_philosopher *philo);
void    philosopher_sleep(t_philosopher *philo);
int     is_philosopher_dead(t_philosopher *philo);


#endif