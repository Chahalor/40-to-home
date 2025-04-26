/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:26:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/26 12:52:50 by nduvoid          ###   ########.fr       */
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
# include "formating.h"

/* Internal */
# include "philosophers.h"

/* Modules  */
# include "utils.h"

/* ************************************************************************** */
/*                                  typedefs                                  */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

// _life.c

extern void	_eat(
				t_philo *philo
				);

extern void	_sleep(
				t_philo *philo
				);

extern void	_think(
				t_philo *philo
				);

extern void	_die(
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