/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:19:16 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/07/30 17:24:15 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(pthread_mutex_t *mutex, t_dinner *dinner)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		dinner->last_error = ERROR_MUTEX_INIT_FORK;
		return ;
	}
}