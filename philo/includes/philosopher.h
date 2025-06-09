/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:03:26 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/09 09:26:50 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h> 
typedef struct s_philosopher
{
    int id;
    int status;
    pthread_t thread_id;
    long long last_meal_ms;
    int number_of_meals;
    struct s_fork *left_fork;
    struct s_fork *right_fork;
    struct s_dinner *dinner;
    
} t_philosopher;

# define PHILOSOPHER_EATING 1
# define PHILOSOPHER_THINKING 2
# define PHILOSOPHER_SLEEPING 3

#endif
