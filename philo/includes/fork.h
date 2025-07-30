/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:03:59 by galves-a          #+#    #+#             */
/*   Updated: 2025/07/30 20:29:30 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <pthread.h>

struct s_philosopher;

typedef struct s_fork
{
	int				id;
	int				status;
	int				owner_id;
	pthread_mutex_t	mutex;
}	t_fork;

# define FORK_AVAILABLE 1
# define FORK_TAKEN 0

/* Functions */
int		hold_forks(struct s_philosopher *philo);
void	lock_fork(t_fork *fork, int philo_id);
void	release_forks( struct s_philosopher *philo);
void	unlock_fork(t_fork *fork);

#endif