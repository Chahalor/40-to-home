/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:54:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/01 11:48:03 by nduvoid          ###   ########.fr       */
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
# include "states.h"
# include "semaphore.h"

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

//...

#endif	// PHILOSOPHERS_H