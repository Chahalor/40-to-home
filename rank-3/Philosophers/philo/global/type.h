/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:56:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/10 15:35:39 by nduvoid          ###   ########.fr       */
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

typedef struct s_rgb		t_rgb;
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
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_rgb
{
	int	r	: 8;
	int	g	: 8;
	int	b	: 8;
};

# pragma pack(push, 1)

struct s_philo_data
{
	int				nb_philo;		/**/
	unsigned int	time_to_die;	/**/
	int				time_to_eat;	/**/
	int				time_to_sleep;	/**/
	int				nb_meals;		/**/
	t_bool			running	: 1;	/**/
};

#pragma pack(pop)

struct s_args
{
	int				argc;				/**/
	const char		**argv;				/**/
	t_philo_data	data;				/**/
	int				error;				/**/
	t_bool			help		: 1;	/**/
	t_bool			debug		: 1;	/**/
	t_bool			data_get	: 1;	/**/
};

struct s_global
{
	t_philo_data	data;			/**/
	t_philo			**philos;		/**/
	t_mutex			print_lock;		/**/
	t_mutex			data_lock;		/**/
};

struct s_philo
{
	t_mutex			*left_fork;		/**/
	t_mutex			*right_fork;	/**/
	t_mutex			*lock;			/**/
	t_thread		thread;			/**/
	t_state			state;			/**/
	int				id;				/**/
	int				nb_meals;		/**/
	unsigned int	last_meal;		/**/
	int				color;			/**/
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

//...

#endif	/* TYPE_H */