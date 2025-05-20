/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:02:51 by galves-a          #+#    #+#             */
/*   Updated: 2025/05/19 21:40:45 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* Libs */
#include <pthread.h>

/* Structs */
typedef struct s_fork t_fork;
typedef struct s_philosopher t_philosopher;
typedef struct s_dinner t_dinner;

/* Headers */
# include "fork.h"
# include "philosopher.h"
# include "dinner.h"

#endif