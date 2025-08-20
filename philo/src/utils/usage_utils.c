/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:19:41 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/08/20 16:19:44 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_usage_header(void)
{
	printf("\nUsage: ./philo <philosophers> <time_to_die> <time_to_eat> ");
	printf("<time_to_sleep> [times_to_eat]\n\n");
	printf("--------------------------------------------------");
	printf("---------\n");
	printf("ARGUMENTS:\n");
	printf("--------------------------------------------------");
	printf("---------\n");
}

static void	print_usage_arguments(void)
{
	printf("  philosophers      Number of philosophers and forks\n");
	printf("  time_to_die       Time in milliseconds until a ");
	printf("philosopher dies if they haven't eaten\n");
	printf("  time_to_eat       Time in milliseconds it takes for a ");
	printf("philosopher to eat\n");
	printf("  time_to_sleep     Time in milliseconds a philosopher ");
	printf("spends sleeping\n");
	printf("  times_to_eat      (Optional) Number of times each ");
	printf("philosopher must eat before\n");
	printf("                    the simulation stops\n\n");
}

static void	print_usage_examples(void)
{
	printf("--------------------------------------------------");
	printf("---------\n");
	printf("EXAMPLES:\n");
	printf("--------------------------------------------------");
	printf("---------\n");
	printf("  ./philo 5 800 200 200\n");
	printf("      » 5 philosophers\n");
	printf("      » Die after 800ms without food\n");
	printf("      » 200ms to eat\n");
	printf("      » 200ms to sleep\n\n");
}

void	print_usage(void)
{
	print_usage_header();
	print_usage_arguments();
	print_usage_examples();
}

int	check_and_report(const char *message)
{
	printf("Error: %s\n", message);
	print_usage();
	return (0);
}