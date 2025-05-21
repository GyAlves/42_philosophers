/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:35:53 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/05/21 19:51:55 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "dinner.h"

int	input_parser(int argc, char **argv, t_dinner *dinner)
{
	if (!are_parameters_valid(argc, argv))
		return (0);

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
	
	return (1);
}

int	are_parameters_valid(int argc, char **argv)
{
	if (!is_valid_philosopher_count(argv[1]))
		return (check_and_report("Invalid number of philosophers"));
	if (!is_valid_time_value(argv[2]))
		return (check_and_report("Invalid time to die value"));
	if (!is_valid_time_value(argv[3]))
		return (check_and_report("Invalid time to eat value"));
	if (!is_valid_time_value(argv[4]))
		return (check_and_report("Invalid time to sleep value"));
	if (argc == 6 && !is_valid_meal_count(argv[5]))
		return (check_and_report("Invalid number of meals value"));
	return (1);
}