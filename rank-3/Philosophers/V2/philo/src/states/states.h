/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:36:29 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 13:27:43 by nduvoid          ###   ########.fr       */
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
	request_init	= 0,	/* The request to init the the global manager */
	request_get_run	= 1,	/* The request to get the run status         */
	request_stop	= 2,	/* The request to stop the simulation       */
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_global_data
{
	t_bool		run		: 1;	/* The run status of the simulation */
};

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

int	global_manager(
		t_request request
		);

#endif	/* STATES_H */