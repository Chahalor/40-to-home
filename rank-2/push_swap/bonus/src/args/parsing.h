/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:24:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 09:41:21 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# pragma once

/* -----| Header |----- */
// Systeme
//...

// Libs
//...

// Local
# include "stack.h"

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef struct s_nb		t_nb;
typedef struct s_args	t_args;

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */

/**
 * * @brief	Structure to store the number and its index in the stack.
*/
struct s_nb
{
	int	value;	// the nb value in the stack
	int	index;	// the index of the nb in the sorted stack
};

/**
 * * @brief	Structure to store the arguments passed to the programme.
 * 
 * * @param	argc	The number of arguments passed to the programme.
 * * @param	argv	The arguments passed to the programme.
 * * @param	stack	The parsed and alloced stack.
 * * @param	len_stack	The length of the stack.
 * * @param	error	The error code.
 * * @param	help	The help flag (0 or 1).
*/
struct s_args
{
	int			argc;			/* the bumber of args passed to the programme */
	const char	**argv;			/* all args passed to the programmes */
	t_nb		*stack;			/* the parsed and alloced stack */
	int			len_stack;		/*the length of the stack (no way) */
	int			error;			/* the error code */
	int			help	: 1;	/* the help flag (0 or 1) */
};

/* -----| Prototype |----- */

t_args	parse_args(const int argc, const char *argv[]);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* PARSING_H */