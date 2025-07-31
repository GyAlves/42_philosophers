/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:44:38 by galves-a          #+#    #+#             */
/*   Updated: 2025/07/31 19:50:41 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init_error(int mutexes_count, t_fork *forks)
{
	int	counter;
	int	status;

	counter = 0;
	while (counter < mutexes_count)
	{
		status = pthread_mutex_destroy(&forks[counter].mutex);
		if (status != 0 && status != 16)
		{
			printf("Error destroying fork mutex: %d\n", status);
			return ;
		}
		counter++;
	}
	return ;
}
