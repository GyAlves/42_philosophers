/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:48:52 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/07/30 18:34:38 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	hold_forks(t_philosopher *philo)
{
	if (philo->dinner->dinner_ended || read_death_mutex(philo))
		return (0);
	if (philo->dinner->number_of_philosophers == 1)
	{
		return (0);
	}
	if (philo->id % 2 == 0)
	{
		if (!hold_odd_fork(philo))
			return (0);
	}
	else
	{
		if (!hold_even_fork(philo))
			return (0);
	}
	return (1);
}

int	hold_odd_fork(t_philosopher *philo)
{
	lock_fork(philo->left_fork, philo->id);
	if (philo->dinner->dinner_ended || read_death_mutex(philo))
	{
		unlock_fork(philo->left_fork);
		return (0);
	}
	lock_fork(philo->right_fork, philo->id);
	return (1);
}

int	hold_even_fork(t_philosopher *philo)
{
	lock_fork(philo->right_fork, philo->id);
	if (philo->dinner->dinner_ended || read_death_mutex(philo))
	{
		unlock_fork(philo->right_fork);
		return (0);
	}
	lock_fork(philo->left_fork, philo->id);
	return (1);
}
