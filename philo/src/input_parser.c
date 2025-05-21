/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:35:53 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/05/21 19:10:35 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "dinner.h"

void    input_parser(int argc, char **argv, t_dinner *dinner)
{
	if (!are_parameters_valid(argc, argv))
		return ;

	dinner->number_of_philosophers = ft_atoi(argv[1]);
	dinner->time_to_die_ms = ft_atoll(argv[2]);
	dinner->time_to_eat_ms = ft_atoll(argv[3]);
	dinner->time_to_sleep_ms = ft_atoll(argv[4]);

	dinner->dinner_ended = 0;
	dinner->dinner_started_ms = 0;

	if (argc == 6)
		dinner->number_of_meals = ft_atoi(argv[5]);
	else
		dinner->number_of_meals = -1;
}

int	are_parameters_valid(int argc, char **argv)
{
	if (!is_valid_philosopher_count(argv[1]))
	{
		printf("Error: Invalid number of philosophers\n");
		print_usage();
		return (0);
	}
	if (!is_valid_time_value(argv[2]))
	{
		printf("Error: Invalid time to die value\n");
		print_usage();
		return (0);
	}
	if (!is_valid_time_value(argv[3]))
	{
		printf("Error: Invalid time to eat value\n");
		print_usage();
		return (0);
	}
	if (!is_valid_time_value(argv[4]))
	{
		printf("Error: Invalid time to sleep value\n");
		print_usage();
		return (0);
	}
	if (argc == 6 && !is_valid_meal_count(argv[5]))
	{
		printf("Error: Invalid number of meals value\n");
		print_usage();
		return (0);
	}
	return (1);
}