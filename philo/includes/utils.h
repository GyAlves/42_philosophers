/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:30:05 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/06/04 18:46:06 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* Functions */
int		    is_valid_integer_format(char *string);
int	        ft_atoi(char *string);
int	        is_valid_philosopher_count(char *string);
int	        is_valid_time_value(char *string);
int	        is_valid_meal_count(char *string);
int         is_valid_integer_format(char *string);
int	        check_and_report(const char *message);
void        init_mutex(pthread_mutex_t *mutex, t_dinner *dinner);
void	    print_usage(void);
void        cleanup_threads(t_dinner *dinner);
void        cleanup_dinner(t_dinner *dinner);
long long   get_time_in_ms(void);
long long   ft_atoll(char *string);
void        logging_philo_status(t_dinner *dinner, char *message, int philo_id);
#endif