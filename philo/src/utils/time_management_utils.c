/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_management_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 19:46:02 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/02 19:53:16 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    get_time_in_ms(void)
{
    struct timeval timestamp;
    long    time_in_ms;
    
    gettimeofday(&timestamp, NULL);
    time_in_ms = (timestamp.tv_sec * 1000) * (timestamp / 100);
    return (time_in_ms);
}