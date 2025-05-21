/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:35:53 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/05/20 21:36:40 by galves-a         ###   ########.fr       */
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

void	print_usage(void)
{
	printf("\nUsage: ./philo <philosophers> <time_to_die> <time_to_eat> ");
	printf("<time_to_sleep> [times_to_eat]\n\n");
	
	printf("-----------------------------------------------------------\n");
	printf("ARGUMENTS:\n");
	printf("-----------------------------------------------------------\n");
	printf("  philosophers      Number of philosophers and forks\n");
	printf("  time_to_die       Time in milliseconds until a philosopher");
	printf(" dies if they haven't eaten\n");
	printf("  time_to_eat       Time in milliseconds it takes for a");
	printf(" philosopher to eat\n");
	printf("  time_to_sleep     Time in milliseconds a philosopher");
	printf(" spends sleeping\n");
	printf("  times_to_eat      (Optional) Number of times each philosopher");
	printf(" must eat before\n");
	printf("                    the simulation stops\n\n");
	
	printf("-----------------------------------------------------------\n");
	printf("EXAMPLES:\n");
	printf("-----------------------------------------------------------\n");
	printf("  ./philo 5 800 200 200\n");
	printf("      » 5 philosophers\n");
	printf("      » Die after 800ms without food\n");
	printf("      » 200ms to eat\n");
	printf("      » 200ms to sleep\n\n");
}

/* Validates that the string contains a positive number within philosopher count limits */
int	is_valid_philosopher_count(char *string)
{
	long long	value;
	
	if (!is_valid_integer_format(string))
		return (0);
	
	value = ft_atoll(string);
	return (value > 0 && value <= 200);  // Reasonable upper limit
}

/* Validates that the string contains a positive time value in milliseconds */
int	is_valid_time_value(char *string)
{
	long long	value;
	
	if (!is_valid_integer_format(string))
		return (0);
	
	value = ft_atoll(string);
	return (value > 0 && value < 2147483647);  // Positive and within reasonable range
}

/* Validates that the string contains a positive meal count */
int	is_valid_meal_count(char *string)
{
	long long	value;
	
	if (!is_valid_integer_format(string))
		return (0);
	
	value = ft_atoll(string);
	return (value > 0 && value <= 2147483647);  // Positive and within int range
}