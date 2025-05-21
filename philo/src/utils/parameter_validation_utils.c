/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_validation_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:22:44 by galves-a          #+#    #+#             */
/*   Updated: 2025/05/21 18:51:43 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_philosopher_count(char *string)
{
	long long	value;
	
	if (!is_valid_integer_format(string))
		return (0);
	
	value = ft_atoll(string);
	return (value > 0 && value <= 200);
}

int	is_valid_time_value(char *string)
{
	long long	value;
	
	if (!is_valid_integer_format(string))
		return (0);
	
	value = ft_atoll(string);
	return (value > 0 && value < 2147483647);
}

int	is_valid_meal_count(char *string)
{
	long long	value;
	
	if (!is_valid_integer_format(string))
		return (0);
	
	value = ft_atoll(string);
	return (value > 0 && value <= 2147483647);
}

int		is_valid_integer_format(char *string)
{
    int counter;

    counter = 0;
    if(string[counter] == '-' || string[counter] == '+')
    {
        if (string[counter] == '-')
            return (0);
        else
            counter++;
    }
    if(string[counter] == '\0')
        return (0);

    while(string[counter])
    {
        if ((string[counter] < '0' || string[counter] > '9'))
            return (0);
        counter++;
    }

    return (1);
}