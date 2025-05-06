/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:26:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 15:31:51 by nduvoid          ###   ########.fr       */
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
# include "parsing.h"
# include "interface.h"
# include "semaphores.h"

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

// _init.c

extern t_philo	*_init_philo(
				register const int nb_philos,
				t_semaphores *restrict sema,
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

extern void	_lock_forks(
				t_philo *philo
				);

extern void	_exit_process(
				t_philo *restrict philos,
				sem_t *restrict print_lock
				);

#endif	/* _PHILOSOPHER_H */