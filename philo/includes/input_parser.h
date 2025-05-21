/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:40:57 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/05/21 19:38:38 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PARSER_H
# define INPUT_PARSER_H

/* Functions */
int    input_parser(int argc, char **argv, t_dinner *dinner);
int		are_parameters_valid(int argc, char **argv);
void	print_usage(void);
int		is_valid_philosopher_count(char *string);
int		is_valid_time_value(char *string);
int		is_valid_meal_count(char *string);

#endif