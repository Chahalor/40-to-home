/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _process.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:28:24 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/09 10:29:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PROCESS_H
# define _PROCESS_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* Systemes */
	//...

/* Globals  */
# include "config.h"
# include "type.h"

/* Internal */
	//...

# include "process.h"

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

typedef struct s_check	t_check;

/* ************************************************************************** */
/*                                  Enums                                     */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_check
{
	sem_t	*finished;
	sem_t	*run;
	int		nb_philo;
};

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

extern int	_look_for_death(
				t_philo *philo
				);

void		*_check_meals(
				void *arg
				);

// _launch.c

extern void	_set_thread(
				t_philo *philo,
				const int nb_philo,
				pid_t *all_pid
				);

#endif /* _PROCESS_H */