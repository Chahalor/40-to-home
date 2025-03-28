/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:02:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/28 09:14:02 by nduvoid          ###   ########.fr       */
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

typedef enum e_instruct	t_instruct;

typedef struct s_stack	t_stack;

/* -----| Enum |----- */

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
struct s_stack
{
	t_nb	*array;		// the array of nb
	char	name;		// the name of the stack
	int		size;		// the number of nb in the stack
	int		max_size;	// the max size of the stack
};

/* -----| Prototype |----- */

//stack.c

void	interaction(const t_instruct instruct, t_stack **stack_a,
	t_stack **stack_b);
void	*destroyer(t_stack *stack);
t_stack	*new(const char name, const int size);
t_stack	*args_to_stack(const char name, const t_args *args);
t_stack	*copy_stack(const t_stack *stack);

//information.c

int		is_sorted(const t_stack *stack);
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