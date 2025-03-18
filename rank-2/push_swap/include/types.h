/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:29:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/18 16:17:40 by nduvoid          ###   ########.fr       */
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

typedef enum e_bool		t_bool;
typedef enum e_error	t_error;
typedef enum e_expect	t_expect;
typedef enum e_algo		t_algo;
typedef enum e_instruct	t_instruct;

typedef struct s_nb		t_nb;
typedef struct s_stack	t_stack;
typedef struct s_args	t_args;

/* -----| Enum |----- */

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

enum e_expect
{
	unexpected,
	expected,
};

/** */
enum e_algo
{
	e_invalide = -1,
	e_turkish,
	e_random,
	e_miracle,
};

/** */
enum e_instruct
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RB,
	RA,
	RR,
	RRA,
	RRB,
	RRR,
	NONE
};

/* -----| Union |----- */
//...

/* -----| Struct |----- */


/** */
struct s_args
{
	int			argc;
	const char	**argv;
	int			*stack;
	int			len_stack;
	t_algo		algo;
	t_error		error;
	t_bool		help	: 1;
};

struct s_nb
{
	int	value;	// the nb value in the stack
	int	index;	// the index of the nb in the sorted stack
};

struct s_stack
{
	t_nb	*array;		// the array of nb
	char	name;		// the name of the stack
	int		size;		// the size of the stack
	int		max_size;	// the max size of the stack
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