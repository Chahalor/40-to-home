/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:03:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/15 10:45:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICO_H
# define DICO_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme */
	//...

/* Global */
#include "config.h"
#include "types.h"

/* Internal */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

//...

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef enum e_dico_error	t_dico_error;	/* list all possible arreor with the dico */

typedef struct s_dico		t_dico;			/* list all the dico info                 */

/* ************************************************************************** */
/*                                 Enums                                      */
/* ************************************************************************** */

enum e_dico_error
{
	DICO_INVALID_WORD = -5,		/* An invalide word is found in the dico */
	DICO_NO_WAY_TO_OPEN = -4,	/* The dico file can't be opened        */
	DICO_EMPTY = -3,			/* The dico file is empty              */
	DICO_NO_PATH = -2,			/* The dico file path is not set      */
	DICO_NO_FILE = -1,			/* The dico file doesn't exist       */
	DICO_NO_ERROR = 0,			/* No error                         */
};

/* ************************************************************************** */
/*                                 Structs                                    */
/* ************************************************************************** */

struct s_dico
{
	char			*path;		/* the path to the dico file               */
	t_uint			size;		/* the number of word in the dico          */
	t_dico_error	error;		/* if any error occure will using the dico */
};

/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_dico	dico_read_info(
	const char *path
);

#endif	// DICO_H