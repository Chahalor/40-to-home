/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:28:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/27 20:02:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PARSING_H
# define _PARSING_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* System */
# include <stdlib.h>

/* Global */
# include "config.h"

/* Modules */
# include "parsing.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define USAGE	"Usage: "
# define USAGE_INFO "philo [options] <nb_philo> <time_to_die> <time_to_eat>\
 <time_to_sleep> <nb_meals>\n"
# define SUSAGE_INFO "%s [options] <nb_philo> <time_to_die> <time_to_eat>\
 <time_to_sleep> <nb_meals>\n"

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                   Enumes                                   */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// _parsing.c

int				ft_strncmp(
					const char *s1,
					const char *s2,
					const size_t n
					);

int				ft_atoi(
					const char *nptr
					);

extern int		is_nbr(
					const char *str
					);

// _info.c

extern void		_show_usage(
					const char *prog
					);

extern void		_show_help(void);

// _data.c

extern t_bool	_is_valide_args(
					const char *restrict *restrict argv,
					const int i,
					const int argc
					);

#endif	/* _PARSING_H */