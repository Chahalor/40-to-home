/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:12 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/13 15:42:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* -----| Library |----- */

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>	//rm

/* -----| Header Files |----- */

# include "libft.h"
# include "mlx.h"

/* -----| Defines |----- */

# ifndef DEBUG
#  define DEBUG 0
# endif // DEBUG

# define ALLOW_NEGATIVE 0
# define ALLOW_FLOAT 0

/* -----| Enums |----- */

typedef enum e_error
{
	NO_ERROR,
	OPEN_ERROR,
	READ_ERROR,
	MALLOC_ERROR,
	PARSE_ERROR,
}	t_error;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

/* -----| Typedef |----- */

# if ALLOW_FLOAT && ALLOW_NEGATIVE 
	typedef double t_type;
# elif ALLOW_FLOAT
	typedef float t_type;
# elif ALLOW_NEGATIVE
	typedef int t_type;
# else
	typedef unsigned int t_type;
# endif // ALLOW_FLOAT && ALLOW_NEGATIVE
/* -----| Structures |----- */

/** @todo */
typedef struct map
{
	t_type	**map;
	t_type	width;
	t_type	height;
}	t_map;

/* -----| Prototypes |----- */

// reading the map

t_map	*parse_file(char *file);

// window
//...

// parsing

t_map	*parse_file(char *file);
t_map	*realloc_map(t_map *map);

// utils

void	exiting(int code, char *message);
t_type	fdf_atoi(const char *nptr);

#if DEBUG
// debug

void	print_map(t_map *map);

#endif // DEBUG

#endif // FDF_H