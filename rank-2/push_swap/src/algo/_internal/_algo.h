/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _algo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:55:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/27 12:45:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ALGO_H
# define _ALGO_H

# pragma once

/* -----| Header |----- */
// System
# include <stdlib.h>

// Global
# include "types.h"
# include "libft.h"

// Modules
//...

/* -----| Define |----- */
//...

/* -----| Macro |----- */

# define NB_CHUNK	5

/* -----| Typedef |----- */

typedef struct s_actions	t_actions;
typedef struct s_magic		t_magic;
typedef struct s_lis		t_lis;

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */

struct s_actions
{
	struct s_action
	{
		t_instruct	instuct;
		int			number;
	}				multiple;
	struct s_action	only_a;
	struct s_action	only_b;
};

struct s_magic
{
	double	val1;
	double	val2;
};

struct s_lis
{
	int		start;
	int		size;
};

/* -----| Prototype |----- */

int				_turkish(t_stack **stack_a, t_stack **stack_b);
int				_da_fuck(t_stack **stack_a, t_stack **stack_b);
int				_lis(t_stack **stack_a, t_stack **stack_b);

// _utils.c

extern int		max(int a, int b);
extern int		min(int a, int b);
extern t_magic	get_magic(const t_stack *stack);
t_stack			**quick_acces(t_stack **stack, const char who);
void			sort_3(t_stack **stack_a, t_stack **stack_b);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* _ALGO_H */