/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:19:16 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/03 17:41:01 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_mutex(pthread_mutex_t *mutex)
{
    int result;

    result = pthread_mutex_init(mutex, NULL);
    if (result != 0)
    {
        printf("Failed to initialize mutex");
        return (result);
    }
    return (0);
}