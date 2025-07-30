/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:02:51 by galves-a          #+#    #+#             */
/*   Updated: 2025/07/30 20:36:24 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include "fork.h"
# include "philosopher.h"
# include "dinner.h"
# include "utils.h"
# include "input_parser.h"
# include "error_handling.h"
# include "routine.h"

typedef struct s_fork			t_fork;
typedef struct s_philosopher	t_philosopher;
typedef struct s_dinner			t_dinner;

#endif