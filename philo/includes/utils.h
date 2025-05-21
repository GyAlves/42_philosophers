/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:30:05 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/05/21 19:52:50 by galves-a         ###   ########.fr       */
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
void	    print_usage(void);
long long   ft_atoll(char *string);
#endif