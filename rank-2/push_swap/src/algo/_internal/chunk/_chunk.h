/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _chunk.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:49:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 12:59:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHUNK_H
# define _CHUNK_H

# pragma once

/* -----| Header |----- */
// System
	// ...

// Global
# include "types.h"
# include "libft.h"

// Modules
# include "stack.h"
# include "_algo.h"
# include "debug.h"

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef struct s_cost	t_cost;

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

struct s_cost
{
	int	index;
	int	range;
	int	sorted;
};

/* -----| Prototype |----- */

// _small.c

void			sort_3(t_stack **stack_a, t_stack **stack_b);
void			four_or_five(t_stack **stack_a, t_stack **stack_b);

// _big.c

void			push_to_b(t_stack **stack_a, t_stack **stack_b);

// _bloc.c

unsigned int	_block_size(const unsigned int len);
unsigned char	_block(t_stack **stack, t_stack **stack_b, const int start,
					const int end);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* _CHUNK_H */