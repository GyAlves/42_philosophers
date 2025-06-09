/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:27:21 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/08 21:23:27 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_dinner	dinner;
                   
    if (argc < 5 || argc > 6)
	{
		print_usage();
		return (1);
	}

	if (!input_parser(argc, argv, &dinner))
        return (1);

    set_up_dinner(&dinner);
    if (dinner.last_error != SUCCESS)
        return (1);
    
    pthread_create(&dinner.death_monitor_thread, NULL, death_monitor, &dinner);
    
    int i = 0;
    while (i < dinner.number_of_philosophers)
    {
        pthread_join(dinner.array_philosophers[i].thread_id, NULL);
        i++;
    }
    pthread_join(dinner.death_monitor_thread, NULL);
    return (0);
}