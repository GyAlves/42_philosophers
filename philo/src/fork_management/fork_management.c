/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:48:52 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/12 19:15:30 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	hold_forks(t_philosopher *philo)
{
	if (philo->dinner->dinner_ended || read_death_mutex(philo))
		return ;
	if (philo->id % 2 == 0)
	{
		lock_fork(philo->left_fork, philo->id);
		if (philo->dinner->dinner_ended || read_death_mutex(philo))
		{
			unlock_fork(philo->left_fork);
			return ;
		}
		lock_fork(philo->right_fork, philo->id);
	}
	else
	{
		lock_fork(philo->right_fork, philo->id);
		if (philo->dinner->dinner_ended || read_death_mutex(philo))
		{
			unlock_fork(philo->right_fork);
			return ;
		}
		lock_fork(philo->left_fork, philo->id);
	}
}

void	lock_fork(t_fork *fork, int philo_id)
{
	pthread_mutex_lock(&fork->mutex);
	fork->owner_id = philo_id;
	fork->status = FORK_TAKEN;
}

void	fork_allocation(t_dinner *dinner, int counter)
{
	dinner->array_forks[counter].id = counter;
	dinner->array_forks[counter].status = 0;
	dinner->array_forks[counter].owner_id = -1;
	init_mutex(&dinner->array_forks[counter].mutex, dinner);
	if (dinner->last_error != SUCCESS)
		return ;
	dinner->created_forks += 1;
}

void	release_forks(t_philosopher *philo)
{
	unlock_fork(philo->right_fork);
	unlock_fork(philo->left_fork);
}

void	unlock_fork(t_fork *fork)
{
	fork->owner_id = -1;
	fork->status = FORK_AVAILABLE;
	pthread_mutex_unlock(&fork->mutex);
}