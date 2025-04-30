/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:36:29 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/30 09:48:41 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATES_H
# define STATES_H

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
	//...

/* ************************************************************************** */
/*                                  Typedefs                                  */
/* ************************************************************************** */

typedef enum e_request			t_request;		/* The request enum         */

typedef struct s_global_data	t_global_data;	/* The global data struct */

/* ************************************************************************** */
/*                                  Enums                                     */
/* ************************************************************************** */

enum e_request
{
	request_get_run,		/* request to get the run status                */
	request_get_finished ,	/* request to get the number of finish philo   */
	request_add_finished,	/* request to add a finished philosopher      */
	request_start,			/* request to start the simulation           */
	request_stop,			/* request to stop the simulation           */
	request_destroy,		/* request to clean the global manager     */
	request_init,			/* request to init the the global manager */
	request_lock_print,		/* request to lock the print mutex       */
	request_unlock_print,	/* request to unlock the print mutex    */
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_global_data
{
	t_bool		run		: 1;	/* The run status of the simulation */
	int			nb_finished;	/* The number of finished philosophers */
	t_mutex		print_lock;		/* The print mutex                  */
};

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

int	global_storage(
		t_request request
		);

#endif	/* STATES_H */