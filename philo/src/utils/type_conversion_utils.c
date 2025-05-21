/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversion_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:25:42 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/05/21 17:24:16 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *string)
{
	int	result;
	int	sign;
	int	counter;

	result = 0;
	counter = 0;
	sign = 1;
	if (string[counter] == '+' || string[counter] == '-')
	{
		if (string[counter] == '-')
			sign = -1;
		counter++;
	}
	while (string[counter] >= '0' && string[counter] <= '9')
	{
		result = result * 10 + (string[counter] - '0');
		counter++;
	}
	return (result * sign);
}

long long   ft_atoll(char *string)
{
	long long   result;
	int	sign;
	int	counter;

	result = 0;
	counter = 0;
	sign = 1;
	if (string[counter] == '+' || string[counter] == '-')
	{
		if (string[counter] == '-')
			sign = -1;
		counter++;
	}
	while (string[counter] >= '0' && string[counter] <= '9')
	{
		result = result * 10 + (string[counter] - '0');
		counter++;
	}
	return (result * sign);
}