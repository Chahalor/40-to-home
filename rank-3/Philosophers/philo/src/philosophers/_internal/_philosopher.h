/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:26:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 09:48:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILOSOPHER_H
# define _PHILOSOPHER_H

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
# include "philosophers.h"

/* Modules  */
# include "interface.h"
# include "states.h"

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

// _init.c

t_mutex		*_init_mutex(
				register int nb_mutex
				);

t_philo		*_init_philo(
				register const int nb_philos,
				t_mutex *restrict *restrict mutex_pool,
				const t_philo_data data,
				const int display
				);

// _life.c

void		_eat(
				t_philo *philo
				);

void		_sleep(
				t_philo *philo
				);

void		_think(
				t_philo *philo
				);

void		_die(
				t_philo *philo
				);

// _utils.c

extern void	_set_mutex(
				t_philo *philo,
				t_mutex **first,
				t_mutex **second
				);

extern void	_lock_forks(
				t_philo *philo,
				t_mutex **first,
				t_mutex **second
				);

#endif	/* _PHILOSOPHER_H */