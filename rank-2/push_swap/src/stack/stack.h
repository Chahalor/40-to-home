/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:02:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:04:43 by nduvoid          ###   ########.fr       */
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
# include "../args/parsing.h"

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
t_stack	*copy_stack(const t_stack *stack);

//information.c

t_bool	is_sorted(const t_stack *stack);
int		get_min_pos(const t_stack *stack);
int		get_max_pos(const t_stack *stack);
int		get_right_index(const t_nb nb, const t_stack *stack);
int		reverse_get_index(const t_nb nb, const t_stack *stack);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* STACK_H */