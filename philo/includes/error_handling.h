/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:43:09 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/04 01:13:17 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

#include "fork.h"

typedef enum    error_status_code
{
    SUCCESS,
    ERROR_MALLOC_PHILOSOPHERS,
    ERROR_MALLOC_FORKS,
    ERROR_MUTEX_INIT_FORK,
    ERROR_MUTEX_INIT_LOGGING,
    ERROR_THREAD_CREATE,
    ERROR_INVALID_PARAMS
} t_error_status_code;

/* Functions */
void    mutex_init_error(int mutexes_count, t_fork *forks);

#endif