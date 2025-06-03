/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:46:02 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/03 18:07:26 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long   get_time_in_ms(void)
{
    struct timeval timestamp;
    long    time_in_ms;
    
    gettimeofday(&timestamp, NULL);
    time_in_ms = (timestamp.tv_sec * 1000) + (timestamp.tv_usec / 1000);
    return (time_in_ms);
}