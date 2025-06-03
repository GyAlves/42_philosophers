/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:44:38 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/03 17:44:51 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    mutex_init_error(int mutexes_count, t_fork *forks)
{
    int counter;

    counter = 0;
    printf("Error: Failed to initialize mutex. Freeing allocated forks\n");
    while (counter < mutexes_count)
    {
        if (pthread_mutex_destroy(&forks[counter].mutex) != 0)
        {
            printf("Error destroying fork mutex");
            return ;
        }
        counter++;
    }
    free(forks);
    printf("Forks memory freed");
    return ;
}