/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:30:16 by galves-a          #+#    #+#             */
/*   Updated: 2025/08/15 19:21:15 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	check_and_report(const char *message)
{
	printf("Error: %s\n", message);
	print_usage();
	return (0);
}

void	logging_philo_status(t_dinner *dinner, char *message, int philo_id)
{
	long long	timestamp;

	if (dinner->dinner_ended)
		return ;
	timestamp = get_time_in_ms() - dinner->dinner_started_ms;
	pthread_mutex_lock(&dinner->logging_mutex);
	if (!dinner->dinner_ended)
		printf("%lld %d %s", timestamp, philo_id, message);
	pthread_mutex_unlock(&dinner->logging_mutex);
}

void	logging_philo_death_status(t_dinner *dinner, int philo_id,
		long long time_of_death)
{
	pthread_mutex_lock(&dinner->logging_mutex);
	printf("%lld %d died\n", time_of_death, philo_id);
	pthread_mutex_unlock(&dinner->logging_mutex);
}