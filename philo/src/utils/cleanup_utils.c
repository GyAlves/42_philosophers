/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:48:17 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/04 02:00:18 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dinner.h"

void    cleanup_threads(t_dinner *dinner)
{
    int counter;

    counter = 0;
    while (counter < dinner->created_threads)
    {
        
    }
}

void    cleanup_dinner(t_dinner *dinner)
{
    // Clean up Forks
    mutex_init_error(dinner->created_forks, dinner->array_forks);

    // Clean up Threads
    

    // Free the forks and philosophers memory
}