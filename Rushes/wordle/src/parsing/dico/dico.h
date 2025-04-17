/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:03:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 16:24:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICO_H
# define DICO_H

# pragma once

/* ************************************************************************** */
/*                                 Headers                                    */
/* ************************************************************************** */

/* Systeme */
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

/* Global */
# include "config.h"
# include "types.h"

/* Internal */
	//...

/* ************************************************************************** */
/*                                 Defines                                    */
/* ************************************************************************** */

# define	MAP_SIZE	8192	/* the size of the hash table for the dico */

/* ************************************************************************** */
/*                                 Typedefs                                   */
/* ************************************************************************** */

typedef enum e_dico_error	t_dico_error;	/* list all possible error with the dico    */

typedef struct s_dico2		t_dico;			/* list all the dico info                 */
typedef struct s_word		t_word;			/* list all the word in the dico         */
typedef struct s_dico2		t_dico2;		/* list all the dico info V2            */

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
	char			*path;	/* the path to the dico file               */
	t_uint			size;	/* the number of word in the dico          */
	t_dico_error	error;	/* if any error occure will using the dico */
};

struct s_word
{
	char			*word;	/* the word in the dico                         */
	struct s_word	*next;	/* the next word in the dico                   */
};			/* the hash table for the dico                */

struct s_dico2
{
	t_word			*table[MAP_SIZE];	/* the hash table for the dico                */
	char			*path;				/* the path to the dico file                 */
	t_uint			size;				/* the number of word in the dico           */
	t_dico_error	error;				/* if any error occure will using the dico */
};


/* ************************************************************************** */
/*                                 Prototypes                                 */
/* ************************************************************************** */

t_dico2	*load_dico(
	const char *restrict filepath
);

void	free_dico(
	t_dico2 *restrict dico
);

void	insert_word(
	t_dico2 *restrict dico,
	const char *restrict word
);

t_bool	word_exists(
	t_dico2 *restrict dico,
	const char *restrict word
);

t_dico2	*get_dico_info(
	const char *path
);

#endif	// DICO_H