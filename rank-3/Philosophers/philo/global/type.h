/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:56:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/08 16:11:29 by nduvoid          ###   ########.fr       */
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
	thinking,
	eating,
	sleeping,
	dead
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
	int	nb_philo;		/**/
	int	time_to_die;	/**/
	int	time_to_eat;	/**/
	int	time_to_sleep;	/**/
	int	nb_meals;		/**/
};

#pragma pack(pop)

struct s_args
{
	int				argc;			/**/
	const char		**argv;			/**/
	t_philo_data	data;			/**/
	int				error;			/**/
	int				help	: 1;	/**/
	int				debug	: 1;	/**/
};

struct s_global
{
	t_philo_data	data;			/**/
	t_philo			**philos;		/**/
	t_mutex			print_lock;		/**/
	t_mutex			data_lock;	/**/
};

struct s_philo
{
	t_mutex		*left_fork;		/**/
	t_mutex		*right_fork;	/**/
	t_mutex		*lock;			/**/
	t_thread	thread;			/**/
	int			id;				/**/
	int			nb_meals;		/**/
	int			last_meal;		/**/
	int			state;			/**/
	int			color;			/**/
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

//...

#endif	/* TYPE_H */