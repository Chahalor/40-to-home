/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:40:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/11 15:47:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* --- Systeme ---*/
# include <pthread.h>

/* --- Global --- */
# include "config.h"

/* --- Modules --- */
	//...

/* ************************************************************************** */
/*                                 Typedef                                    */
/* ************************************************************************** */

typedef pthread_t		t_thread;
typedef pthread_mutex_t	t_mutex;

typedef enum e_expected	t_expected;
typedef enum e_bool		t_bool;

typedef struct s_data	t_data;
typedef struct s_args	t_args;

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_expected
{
	unexpected	= 0,
	expected	= 1,
};

enum e_bool
{
	false	= 0,
	true	= 1,
};

/* ************************************************************************** */
/*                                 Struct                                     */
/* ************************************************************************** */

struct s_data
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_meals;
};

struct s_args
{
	int			argc;
	const char	**argv;
	t_data		data;
	int			error;
	t_bool		help	: 1;
	t_bool		debug	: 1;
};

#endif	/* TYPE_H */