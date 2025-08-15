/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:27:21 by galves-a          #+#    #+#             */
/*   Updated: 2025/08/15 19:21:15 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_for_threads(t_dinner *dinner)
{
	int	i;

	pthread_join(dinner->death_monitor_thread, NULL);
	i = 0;
	while (i < dinner->number_of_philosophers)
	{
		pthread_join(dinner->array_philosophers[i].thread_id, NULL);
		i++;
	}
}

static void	initialize_dinner(t_dinner *dinner)
{
	dinner->array_philosophers = NULL;
	dinner->array_forks = NULL;
	dinner->created_threads = 0;
	dinner->created_forks = 0;
}

int	main(int argc, char **argv)
{
	t_dinner	dinner;

	initialize_dinner(&dinner);
	if (argc < 5 || argc > 6)
	{
		print_usage();
		return (1);
	}
	if (!input_parser(argc, argv, &dinner))
		return (1);
	set_up_dinner(&dinner);
	if (dinner.last_error != SUCCESS)
	{
		cleanup_dinner(&dinner);
		return (1);
	}
	pthread_create(&dinner.death_monitor_thread, NULL, death_monitor, &dinner);
	wait_for_threads(&dinner);
	cleanup_dinner(&dinner);
	return (0);
}