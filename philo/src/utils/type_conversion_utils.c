/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_conversion_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:25:42 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/05/20 15:04:05 by gyasminalve      ###   ########.fr       */
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
        if (string[counter] < '0' || string[counter] > '9')
            return (0);
        counter++;
    }

    return (1);
}