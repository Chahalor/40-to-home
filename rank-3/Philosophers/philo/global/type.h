/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:56:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/10 20:05:14 by nduvoid          ###   ########.fr       */
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

typedef pthread_mutex_t		t_mutex;
typedef pthread_t			t_thread;

typedef enum e_expect		t_expect;
typedef enum e_bool			t_bool;
typedef enum e_state		t_state;
typedef enum e_info			t_info;
typedef enum e_say			t_say;

typedef struct s_args		t_args;
typedef struct s_global		t_global;
typedef struct s_philo_data	t_philo_data;
typedef struct s_philo		t_philo;

/* ************************************************************************** */
/*                                   Enumes                                   */
/* ************************************************************************** */

enum e_expect
{
	unexpected	= 0,
	expected	= 1
};

enum e_bool
{
	false,
	true
};

enum e_state
{
	thinking = 0,
	eating = 1,
	sleeping = 2,
	dead = 3,
	take_fork = 4,
	finish = 5
};

enum e_info
{
	setup = -1,
	time_to_die,
	time_to_eat,
	time_to_sleep,
	nb_meals,
	state,
	start_time,
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

# pragma pack(push, 1)

struct s_philo_data
{
	int				nb_philo;		/* number of philo                      */
	unsigned int	time_to_die;	/* the time to die from stavation       */
	int				time_to_eat;	/* the time they take to eat            */
	int				time_to_sleep;	/* the time they need to sleep          */
	int				nb_meals;		/* the number of meal they have to take */
	unsigned int	start_time;		/* the timer of the simu begining       */
	t_bool			running	: 1;	/* if the simu still running            */
};

#pragma pack(pop)

struct s_args
{
	int				argc;				/* The number of args           */
	const char		**argv;				/* The pointer to the args      */
	t_philo_data	data;				/* The simulation data          */
	int				error;				/* The errno inside the parsing */
	t_bool			help		: 1;	/* if -h/--help flag detected   */
	t_bool			debug		: 1;	/* if -d/--debug flag detected  */
	t_bool			data_get	: 1;	/* if we parsed the simu data   */
};

struct s_global
{
	t_philo_data	data;			/* all simulation limits      */
	t_philo			**philos;		/* the philosophers list      */
	t_mutex			print_lock;		/* lock the print acces       */
	t_mutex			data_lock;		/* lock the rad/write of data */
};

struct s_philo
{
	t_mutex			*left_fork;		/* the left fork                         */
	t_mutex			*right_fork;	/* the rigth fork (no way)               */
	t_mutex			*lock;			/* useless @todo: rm       */
	t_thread		thread;			/* the actual thread of the philo        */
	t_state			state;			/* it actual state (eating,sleeping,...) */
	int				id;				/* the unique id of the philo            */
	int				nb_meals;		/* the number of time he eat             */
	unsigned int	last_meal;		/* the time of its last meal             */
	int				color;			/* the pilo colors                       */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

//...

#endif	/* TYPE_H */