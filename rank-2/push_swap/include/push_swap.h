/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:08:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/13 13:24:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# pragma once

/* -----| Header |----- */
// System
# include <errno.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// libs
# include "libft.h"

// local
//...

/* -----| Define |----- */

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define BLUE	"\033[34m"
# define YELLOW	"\033[33m"
# define RESET	"\033[0m"

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef unsigned int	t_uint;

typedef enum e_bool		t_bool;
typedef enum e_error	t_error;
typedef enum e_algo		t_algo;

typedef struct s_args	t_args;

/* -----| Enum |----- */

enum e_bool
{
	false,
	true,
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

#endif	/* PUSH_SWAP_H */