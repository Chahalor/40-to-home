/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:58:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 09:18:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# pragma once

/* ************************************************************************** */
/*                                  Headers                                   */
/* ************************************************************************** */

/* Systemes */
	//...

/* Globals  */
# include "config.h"
# include "type.h"
# include "formating.h"

/* Internal */
	//...

/* Modules  */
# include "utils.h"

/* ************************************************************************** */
/*                                  Defines                                   */
/* ************************************************************************** */

# define MAX_ERROR		16	/* The maximum error code */

/* ************************************************************************** */
/*                                  typedefs                                  */
/* ************************************************************************** */

typedef struct s_error	t_error;	/* The error type */

/* ************************************************************************** */
/*                                  Enums                                     */
/* ************************************************************************** */

enum e_error_request
{
	er_request_new			= 0,	/* request to create a new error        */
	er_request_print		= 1,	/* request to print an error            */
	er_request_rm			= 2,	/* request to remove an error           */
	er_request_print_all	= 3,	/* request to print all error           */
	er_request_new_print	= 4,	/* request to create and print an error */
};

/* ************************************************************************** */
/*                                  Structs                                   */
/* ************************************************************************** */

struct s_error
{
	char	*localisation;	/* The location of the error          */
	char	*message;		/* The error message                 */
	char	*info;			/* More information about the error */
	int		error;			/* The error code                  */
	int		id;
};

/* ************************************************************************** */
/*                                  Prototypes                                */
/* ************************************************************************** */

int	error_manager(
	int request,		/* the request to manage */
	void *data			/* the data to manage   */
);

#endif	// ERRORS_H