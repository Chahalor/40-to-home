/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:02:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/20 12:26:19 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# pragma once

/* -----| Header |----- */
// System
//...

// Global
//...

// Modules
# include "parsing.h"

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */
//...

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */

//stack.c

void	interaction(const t_instruct instruct, t_stack **stack_a,
	t_stack **stack_b);
void	*destroyer(t_stack *stack);
t_stack	*new(const char name, const int size);
t_stack	*args_to_stack(const char name, const t_args *args);

//information.c

t_bool	is_sorted(const t_stack *stack);
int		get_max_pos(const t_stack *stack);
int		get_right_index(const t_nb nb, const t_stack *stack);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* STACK_H */