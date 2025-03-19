/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/19 13:53:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"
#include "stack.h"
#include "parsing.h"
#include <stdbool.h>

/** */
__attribute__((hot))
void	interaction(const t_instruct instruct, t_stack *stack_a,
	t_stack *stack_b)
{
	static void (*const actions[])() = {
		[PA] = push, [PB] = push, [SA] = swap, [SB] = swap,
		[SS] = swap_both, [RA] = rotate, [RB] = rotate,
		[RR] = rotate_both, [RRA] = reverse_rotate, [RRB] = reverse_rotate,
		[RRR] = reverse_rotate_both};
	static const char *actions_to_print[] = {
		[PA] = "pa\n", [PB] = "pb\n", [SA] = "sa\n", [SB] = "sb\n",
		[SS] = "ss\n", [RA] = "ra\n", [RB] = "rb\n", [RR] = "rr\n",
		[RRA] = "rra\n", [RRB] = "rrb\n", [RRR] = "rrr\n"};

	if (stack_a == NULL || stack_b == NULL || instruct < PA	|| instruct > RRR)
		return ;
	// if (instruct == PB || instruct == SB || instruct == RB || instruct == RRB)
	if (instruct % 2 == 1)
		actions[instruct](stack_b, stack_a);
	else
		actions[instruct](stack_a, stack_b);
	write(1, actions_to_print[instruct], ft_strlen(actions_to_print[instruct]));
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

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	if (size > 0)
		stack->array = (t_nb *)malloc(sizeof(t_nb) * size);
	if (stack->array == NULL && size > 0)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->max_size = size;
	stack->name = name;
	return (stack);
}

__attribute__((cold, malloc))
t_stack *args_to_stack(const char name, const t_args *args)
{
	t_stack		*stack;
	
	stack = new(name, 0);
	if (__builtin_expect(stack == NULL, unexpected))
		return (NULL);
	stack->max_size = args->len_stack;
	stack->size = args->len_stack;
	stack->array = args->stack;
	get_index(stack->array, stack->max_size);
	return (stack);
}
