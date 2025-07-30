/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:03:26 by galves-a          #+#    #+#             */
/*   Updated: 2025/07/30 20:36:29 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include "dinner.h"

struct s_dinner;

typedef struct s_philosopher
{
	int				id;
	int				status;
	int				is_dead;
	long long		last_meal_ms;
	int				number_of_meals;
	pthread_t		thread_id;
	pthread_mutex_t	death_mutex;

	struct s_fork	*left_fork;
	struct s_fork	*right_fork;
	struct s_dinner	*dinner;
}	t_philosopher;

# define PHILOSOPHER_EATING 1
# define PHILOSOPHER_THINKING 2
# define PHILOSOPHER_SLEEPING 3

int		is_philosopher_dead(t_philosopher *philo);
int		read_death_mutex(t_philosopher *philo);
void	write_death_mutex(t_philosopher *philo, int death_mutex_value);
int		philo_vitals(t_philosopher *philo);
int		all_philosophers_satisfied(struct s_dinner *dinner);
void	philo_init(t_dinner *dinner, int counter);
void	philosopher_allocation(t_dinner *dinner, int counter);
void	*philosopher_routine(void *arg);

#endif
