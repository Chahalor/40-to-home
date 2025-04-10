/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:27:49 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/10 19:28:01 by nduvoid          ###   ########.fr       */
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

void		info(const t_state info, const t_philo *restrict philo,
	const int time);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	mein_sleep(t_philo *philo, const int time);

// _data.c

int			get_data(const t_info request);
t_global	*store_global(t_global *global);
void		lock_print(void);
void		unlock_print(void);

#endif	/* _PHILOSOPHER_H */