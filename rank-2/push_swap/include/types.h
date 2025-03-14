/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:29:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/14 15:25:34 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#pragma once

/* -----| Header |----- */
// System
//...

// Libs
//...

// Local
//...

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef unsigned int	t_uint;

typedef int				t_stack;

typedef enum e_choose	t_choose;
typedef enum e_bool		t_bool;
typedef enum e_error	t_error;
typedef enum e_algo		t_algo;
typedef enum e_pos		t_pos;

typedef struct s_nb		t_nb;
typedef struct s_args	t_args;

/* -----| Enum |----- */

enum e_choose
{
	STACK_A,
	STACK_B,
};

enum e_bool
{
	FALSE,
	TRUE,
};

/** */
enum e_error
{
	succes = 0,
	invalid_argument,
	invalid_number,
	malloc_failed,
};

/** */
enum e_algo
{
	turkish,
	random,
	miracle,
};

enum	e_pos
{
	top,
	bottom,
};

/* -----| Union |----- */
//...

/* -----| Struct |----- */

/** */
struct s_args
{
	int			argc;
	const char	**argv;
	const char	*stack;
	t_algo		algo;
	t_error		error;
	t_bool		help	: 1;
};

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* TYPES_H */