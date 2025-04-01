/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:29:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/01 11:54:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# pragma once

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

/** */
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
	e_invalide = -1,	/* invalide algorithme */
	e_turkish,			/* turkish sort */
	e_turk,				/* turkish sort 2 (tkt) */
	e_random,			/* random sort */
	e_miracle,			/* miracle sort */
};

/** */
enum e_instruct
{
	PA = 0,		/* push the first element of B to A*/
	PB = 1,		/* push the first element of A to B*/
	SA = 2,		/* swap the first two elements of A*/
	SB = 3,		/* swap the first two elements of B*/
	SS = 4,		/* swap the first two elements of A and B*/
	RB = 5,		/* rotate the stack B*/
	RA = 6,		/* rotate the stack A*/
	RR = 7,		/* rotate the stack A and B*/
	RRA = 8,	/* reverse rotate the stack A*/
	RRB = 9,	/* reverse rotate the stack B*/
	RRR = 10,	/* reverse rotate the stack A and B*/
	SORT = 11,	/* ask to sort the first stack */
	NONE = 12	/* no action */
};

/* -----| Union |----- */
//...

/* -----| Struct |----- */

/** */
struct s_args
{
	int			argc;			/* the bumber of args passed to the programme */
	const char	**argv;			/* all args passed to the programmes */
	t_nb		*stack;			/* the parsed and alloced stack */
	int			len_stack;		/*the length of the stack (no way) */
	t_algo		algo;			/* the algo choose by the user */
	t_error		error;			/* the error code */
	t_bool		help	: 1;	/* the help flag (0 or 1) */
};

/** */
struct s_nb
{
	int	value;	// the nb value in the stack
	int	index;	// the index of the nb in the sorted stack
};

/** */
struct s_stack
{
	t_nb	*array;		// the array of nb
	char	name;		// the name of the stack
	int		size;		// the number of nb in the stack
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