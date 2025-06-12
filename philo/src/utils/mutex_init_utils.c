/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:19:16 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/04 01:12:22 by gyasminalve      ###   ########.fr       */
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