/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:27:21 by galves-a          #+#    #+#             */
/*   Updated: 2025/06/03 18:54:29 by gyasminalve      ###   ########.fr       */
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

    if(!set_up_dinner(&dinner))
        return (1);

    // Print dinner struct after initialization
    printf("Dinner struct after initialization:\n");
    printf("  number_of_philosophers: %d\n", dinner.number_of_philosophers);
    printf("  number_of_meals: %d\n", dinner.number_of_meals);
    printf("  dinner_ended: %d\n", dinner.dinner_ended);
    printf("  time_to_die_ms: %lld\n", dinner.time_to_die_ms);
    printf("  time_to_eat_ms: %lld\n", dinner.time_to_eat_ms);
    printf("  time_to_sleep_ms: %lld\n", dinner.time_to_sleep_ms);
    printf("  dinner_started_ms: %lld\n", dinner.dinner_started_ms);
    return (0);
}