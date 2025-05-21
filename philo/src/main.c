/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:27:21 by galves-a          #+#    #+#             */
/*   Updated: 2025/05/21 17:02:43 by galves-a         ###   ########.fr       */
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
	
	input_parser(argc, argv, &dinner);

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