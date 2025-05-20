/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:35:53 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/05/20 15:09:34 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    input_parser(int argc, char **argv)
{
	are_parameters_valid(argc, argv);

    // Convert each argument to an integer and assign to the appropriate variable
        // Since the ms type of variables could be long, can i use atoi to convert them ?
    
    // Verify if optional argument is present and convert it. 
}

int are_parameters_valid(int argc, char **argv)
{
	int counter;

	counter = 1;
	while(counter < argc)
	{
		if (!is_valid_integer_format(argv[counter]))
		{
			printf("Error: Invalid argument format: %s\n", argv[counter]);
			return (0);
		}
		counter++;
	}
	return (1);
}

void	print_usage(void)
{
	printf("\nError: Invalid number of arguments\n\n");
	printf("Usage: ./philo <philosophers> <time_to_die> <time_to_eat> ");
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