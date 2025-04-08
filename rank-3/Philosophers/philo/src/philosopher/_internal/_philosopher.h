/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:27:49 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/08 15:08:31 by nduvoid          ###   ########.fr       */
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

// _philosopher.c

extern int	init_philos(t_philo **philo,
	t_mutex **fork, const register t_philo_data data);
extern void	destroy_forks(t_mutex **forks, register int i);
extern int	init_forks(t_mutex **fork, const int nb_philo);

// _day.c
extern void	sleep(t_philo *philo);
extern void	eat(t_philo *philo);
extern void	think(t_philo *philo);
extern void	die(t_philo *philo);

#endif	/* _PHILOSOPHER_H */