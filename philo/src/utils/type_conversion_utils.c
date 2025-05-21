/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversion_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:25:42 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/05/20 21:00:38 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        if (string[counter] == '0' || (string[counter] < '0' || string[counter] > '9'))
            return (0);
        counter++;
    }

    return (1);
}

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