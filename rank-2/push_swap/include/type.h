/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:29:27 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/13 14:25:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

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

typedef int				t_stack;

typedef enum e_choose	t_choose;
typedef enum e_bool		t_bool;
typedef enum e_error	t_error;
typedef enum e_algo		t_algo;
typedef enum e_pos		t_pos;

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
	succes,
	invalid_argument,
	invalid_number,
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
	bottom,,
}

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

struct s_stack
{
	void		(*const swap)(void);
	void		(*const push)(t_stack **, const t_pos);
	void		(*const rotate)(int);
	int			size;
	int			*array;
	const char	*name;	// "a" or "b", use for print the action
};
stack_a.swap()

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* TYPE_H */