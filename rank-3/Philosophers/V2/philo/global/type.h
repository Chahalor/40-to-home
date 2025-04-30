/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:56:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 16:39:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* Systemes */
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

/* globals */
	//...

/* Modules */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

typedef pthread_mutex_t		t_mutex;		/* The mutex type              */
typedef pthread_t			t_thread;		/* The thread type            */
typedef unsigned int		t_time;			/* time to store the time    */

typedef enum e_expect		t_expect;		/* The expected value enum     */
typedef enum e_bool			t_bool;			/* The boolean type           */
typedef enum e_status		t_status;		/* The status type           */

typedef struct s_philo_data	t_philo_data;	/* The philosopher data struct */

/* ************************************************************************** */
/*                                   Enumes                                   */
/* ************************************************************************** */

enum e_expect
{
	unexpected	= 0,	/* this condition is unexpected to be true */
	expected	= 1		/* this condition is expected to be true  */
};

enum e_bool
{
	false,				/* this is false */
	true,				/* this is true */
};

enum e_status
{
	thinking,			/* the philosopher is thinking           */
	eating,				/* the philosopher is eating            */
	sleeping,			/* the philosopher is sleeping         */
	died,				/* the philosopher is dead            */
	finish,				/* the philosopher is finishing      */
	init,				/* the philosopher is initializing  */
	forks,				/* the philosopher is taking forks */
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_philo_data
{
	int				nb_philo;		/* number of philo                      */
	unsigned int	time_to_die;	/* the time to die from stavation       */
	int				time_to_eat;	/* the time they take to eat            */
	int				time_to_sleep;	/* the time they need to sleep          */
	int				nb_meals;		/* the number of meal they have to take */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

//...

#endif	/* TYPE_H */