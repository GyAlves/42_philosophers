/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:43:09 by galves-a          #+#    #+#             */
/*   Updated: 2025/07/30 17:56:49 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "fork.h"

typedef enum error_status_code
{
	SUCCESS,
	ERROR_MALLOC_PHILOSOPHERS,
	ERROR_MALLOC_FORKS,
	ERROR_MUTEX_INIT_FORK,
	ERROR_MUTEX_INIT_LOGGING,
	ERROR_THREAD_CREATE,
	ERROR_INVALID_PARAMS
}	t_error_status_code;

/* Functions */
void	mutex_init_error(int mutexes_count, t_fork *forks);

#endif