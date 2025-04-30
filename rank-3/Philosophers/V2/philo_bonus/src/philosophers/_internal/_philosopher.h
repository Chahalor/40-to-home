/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:26:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 13:54:10 by nduvoid          ###   ########.fr       */
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
# include "states.h"
# include "semaphore.h"

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

// _init.c

//...

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

#endif	/* _PHILOSOPHER_H */