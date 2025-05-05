/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:54:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/05 12:49:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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

/* Modules  */
# include "parsing.h"
# include "states.h"
# include "semaphores.h"

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

typedef struct s_philo	t_philo;	/* The philosopher type */

/* ************************************************************************** */
/*                                  Enums                                     */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_philo
{
	unsigned int	id;				/* The philosopher id              */
	int				nb_meals;		/* The number of meals taken       */
	t_time			last_meal;		/* The last meal time              */
	t_status		status;			/* The philosopher status          */
	sem_t			*forks;			/* The semaphore  for all forks    */
	sem_t			*lock;			/* The semaphore for the lock      */
	t_philo_data	data;			/* The philosopher data            */
	void			(*eat)(t_philo *philo);		/* The eat function    */
	void			(*sleep)(t_philo *philo);	/* The sleep function  */
	void			(*think)(t_philo *philo);	/* The think function  */
	void			(*die)(t_philo *philo);		/* The die function    */
	void			(*info)(const t_philo *philo, const int info);
};

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

int	circle_of_life(
		t_philo *philo
		);

int	init_all(
		t_semaphores *restrict semaphores,
		t_philo *restrict *restrict philosophers,
		const t_args args
		);

void	destroy_philos(
		t_philo *restrict *restrict philosophers
		);

#endif	// PHILOSOPHERS_H