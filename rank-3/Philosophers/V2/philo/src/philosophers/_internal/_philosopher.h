/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _philosopher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:26:57 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/23 14:59:01 by nduvoid          ###   ########.fr       */
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
# include "utils.h"

/* ************************************************************************** */
/*                                  typedefs                                  */
/* ************************************************************************** */

typedef	struct s_watcher	t_watcher;	/* The watcher type */

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_watcher
{
	t_philo			*philosophers;	/* The philosophers list */
	t_philo_data	data;			/* The simulation data   */
};

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

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

#endif	/* _PHILOSOPHER_H */