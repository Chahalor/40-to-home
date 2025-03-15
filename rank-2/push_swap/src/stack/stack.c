/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/15 14:03:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"
#include "instruct/instruct.h"
#include "stack.h"

void	interaction(const t_instruct instruct, t_stack *stack_a,
	t_stack *stack_b)
{
	if (instruct == PA)
		push(stack_a, stack_b);
	else if (instruct == PB)
		push(stack_b, stack_a);
	else if (instruct == SA)
		swap(stack_a);
	else if (instruct == SB)
		swap(stack_b);
	else if (instruct == SS)
		swap_both(stack_a, stack_b);
	else if (instruct == RA)
		rotate(stack_a);
	else if (instruct == RB)
		rotate(stack_b);
	else if (instruct == RR)
		rotate_both(stack_a, stack_b);
	else if (instruct == RRA)
		reverse_rotate(stack_a);
	else if (instruct == RRB)
		reverse_rotate(stack_b);
	else if (instruct == RRR)
		reverse_rotate_both(stack_a, stack_b);
}

/** */
__attribute__((cold))
void	*destroyer(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	free(stack->array);
	free(stack);
	return (NULL);
}

/** */
__attribute__((cold, malloc))
t_stack	*new(const char name, const int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) + sizeof(t_nb) * size);
	if (stack == NULL)
		return (NULL);
	stack->array = (t_nb *)(stack + 1);
	stack->size = size;
	stack->name = name;
	return (stack);
}
