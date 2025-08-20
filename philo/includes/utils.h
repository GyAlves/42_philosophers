/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:30:05 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/12 19:15:30 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		is_valid_integer_format(char *string);
int		ft_atoi(char *string);
int		is_valid_philosopher_count(char *string);
int		is_valid_time_value(char *string);
int		is_valid_meal_count(char *string);
int		check_and_report(const char *message);
void	init_mutex(pthread_mutex_t *mutex, t_dinner *dinner);
void	print_usage(void);
void	cleanup_threads(t_dinner *dinner);
void	cleanup_dinner(t_dinner *dinner);
long long	get_time_in_ms(void);
void	safe_usleep(unsigned long duration_ms, t_philosopher *philo);
long long	ft_atoll(char *string);
void	logging_philo_status(t_dinner *dinner, char *message, int philo_id);
void	logging_philo_death_status(t_dinner *dinner, int philo_id,
		long long time_of_death);
#endif