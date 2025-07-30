/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_management_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:16:06 by galves-a          #+#    #+#             */
/*   Updated: 2025/07/30 18:33:09 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"
#include "fork.h"
#include "utils.h"

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
	if (philo->dinner->number_of_philosophers == 1)
	{
		return ;
	}
	unlock_fork(philo->right_fork);
	unlock_fork(philo->left_fork);
}

void	unlock_fork(t_fork *fork)
{
	fork->owner_id = -1;
	fork->status = FORK_AVAILABLE;
	pthread_mutex_unlock(&fork->mutex);
}
