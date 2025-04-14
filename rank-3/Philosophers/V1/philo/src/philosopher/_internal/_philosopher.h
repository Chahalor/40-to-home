/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:27:49 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/14 09:37:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILOSOPHER_H
# define _PHILOSOPHER_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* Systemes */
# include <pthread.h>

/* Global */
# include "type.h"
# include "config.h"

/* Modules */
# include "formating.h"

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                   Enums                                    */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

// _philosopher.c

extern int	init_philos(t_philo **philo, t_mutex **fork,
	register const t_philo_data data);
extern int	init_forks(t_mutex **fork, const int nb_philo);

// _day.c

void	info(const t_state info, const t_philo *restrict philo,
	const int time);
void	_eat(t_philo *philo);
void	_think(t_philo *philo);
void	_sleep(t_philo *philo, const int time);
void	_death(t_philo *philo,t_global *global);

// _data.c

int			get_data(const t_info request);
t_global	*store_global(t_global *global);
void		lock_print(void);
void		unlock_print(void);

// _launch.c

void		terminator(t_philo **philo, const int nb_philo);
extern int	launch_thread(t_global *global, t_thread *main);

#endif	/* _PHILOSOPHER_H */