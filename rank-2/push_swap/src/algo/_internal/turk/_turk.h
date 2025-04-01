/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _turk.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 09:46:21 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/01 13:34:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TURK_H
# define _TURK_H

# pragma once

/* -----| Header |----- */
	// System
# include <limits.h>

	// Global
# include "libft.h"
# include "config.h"
# include "types.h"

	// Modules
# include "stack.h"
# include "utils.h"
# include "debug.h"

/* -----| Define |----- */

# define REVERSE_MAX 10

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef struct s_inst_set	t_inst_set;

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */

struct s_inst_set
{
	int		ra;
	int		rb;
	int		rr;
	size_t	weight;
};

/* -----| Prototype |----- */

/// _turk.c
extern void	sort_3(t_stack **stack_a, t_stack **stack_b);

// pass.c
void		final_pass(t_stack **a, t_stack **b);
int			pass(t_stack **a, t_stack **b, const int original_size);
void		exec_set(t_stack **a, t_stack **b, t_inst_set set);

// solver_a.c
void		sort_a(t_stack **a, t_stack **b);

// solver_b.c
t_inst_set	get_best_set(t_stack **a, t_stack **b);
t_inst_set	get_rr(t_inst_set set);

// utils.c
int			ft_abs(const int n);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* _TURK_H */