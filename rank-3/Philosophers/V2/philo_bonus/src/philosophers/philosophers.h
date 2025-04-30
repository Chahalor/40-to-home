/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:54:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/29 11:53:56 by nduvoid          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

typedef struct s_philo		t_philo;	/* The philosopher type */
typedef struct s_watcher	t_watcher;	/* The watcher type    */

/* ************************************************************************** */
/*                                  Enums                                     */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_philo
{
	unsigned int		id;				/* The philosopher id              */
	int					nb_meals;		/* The number of meals taken       */
	t_time				last_meal;		/* The last meal time              */
	t_status			status;			/* The philosopher status          */
	t_mutex				*left_fork;		/* The left fork mutex             */
	t_mutex				*right_fork;	/* The right fork mutex            */
	t_mutex				*lock;			/* mutex to lock philo data acces  */
	t_philo_data		data;			/* The philosopher data            */
	void				(*eat)(t_philo *philo);		/* The eat function    */
	void				(*sleep)(t_philo *philo);	/* The sleep function  */
	void				(*think)(t_philo *philo);	/* The think function  */
	void				(*die)(t_philo *philo);		/* The die function    */
	void				(*finish)(t_philo *philo);	/* The finish function */
	void				(*info)(const t_philo *philo, const int info);
};

struct s_watcher
{
	t_philo			*philosophers;	/* The philosophers list */
	t_philo_data	data;			/* The simulation data   */
};

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

void	destroy_mutex(
			t_mutex *restrict *restrict forks,
			const int nb_forks
			);

void	destroy_philos(
			t_philo *restrict *restrict philosophers
			);

int		init_all(
			t_mutex **forks,
			t_philo *restrict *restrict philosophers,
			t_philo_data data,
			const int display
			);

// void	info(
// 			const int id,
// 			const char *msg
// 			);

// life.c

void	*circle_of_life(
			void *arg
			);

// watcher.c

void	*big_brother(
			void *arg
			);

#endif	// PHILOSOPHERS_H