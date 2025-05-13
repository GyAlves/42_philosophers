/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:03:59 by galves-a          #+#    #+#             */
/*   Updated: 2025/05/12 22:06:48 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

#include "philo.h"

typedef struct s_fork
{
    int id;
    int status;
    int owner_id;
    pthread_mutex_t mutex;
    
} t_fork;

# define FORK_AVAILABLE 1
# define FORK_TAKEN 0

#endif