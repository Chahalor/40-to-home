/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 09:01:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"
#include "stack.h"
#include "parsing.h"
#include "utils.h"
#include <stdbool.h>

/**
 * @brief	Perform the action on the stack.
 * 
 * @param	instruct	The instruction to perform.
 * @param	stack_a		Pointer to the first stack.
 * @param	stack_b		Pointer to the second stack.
 * 
 * @return	void
 */
__attribute__((hot))
void	interaction(const t_instruct instruct, t_stack **stack_a,
	t_stack **stack_b)
{
	static int (*const	actions[])() = {
	[PA] = push, [PB] = push, [SA] = swap, [SB] = swap,
	[SS] = swap_both, [RA] = rotate, [RB] = rotate,
	[RR] = rotate_both, [RRA] = reverse_rotate, [RRB] = reverse_rotate,
	[RRR] = reverse_rotate_both, [SORT] = _sort_stack, [NONE] = none};
	static const char	*actions_to_print[] = {
	[PA] = "pa\n", [PB] = "pb\n", [SA] = "sa\n", [SB] = "sb\n",
	[SS] = "ss\n", [RA] = "ra\n", [RB] = "rb\n", [RR] = "rr\n",
	[RRA] = "rra\n", [RRB] = "rrb\n", [RRR] = "rrr\n"};
	int					output;

	if (*stack_a == NULL || *stack_b == NULL || instruct < PA
		|| instruct > SORT)
		return ;
	else if (instruct == PA || instruct == RB || instruct == RRB)
		output = actions[instruct](stack_b, stack_a);
	else
		output = actions[instruct](stack_a, stack_b);
	if (instruct < SORT && output)
		write(1, actions_to_print[instruct], 3 + (instruct > RR));
}

/**
 * @brief	Destroy the stack and free the memory.
 * 
 * @param	stack	The stack to destroy.
 * 
 * @return	NULL.
 */
__attribute__((cold))
void	*destroyer(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->array != NULL && stack->max_size > 0)
		free(stack->array);
	free(stack);
	return (NULL);
}

/**
 * @brief	Creates a new stack.
 * 
 * @param	name	The name of the stack.
 * @param	size	The size of the array of the stack.
 * 
 * @return	The new stack.
 */
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

/**
 * @brief	Converts the args to a stack.
 * 
 * @param	name	The name of the stack.
 * @param	args	The args to convert.
 * 
 * @return	The converted stack.
 */
__attribute__((cold, malloc))
t_stack	*args_to_stack(const char name, const t_args *args)
{
	t_stack	*stack;

	if (args->len_stack == 0 || args->stack == NULL)
		return (NULL);
	stack = new(name, 0);
	if (__builtin_expect(stack == NULL, unexpected))
		return (NULL);
	stack->max_size = args->len_stack;
	stack->size = args->len_stack;
	stack->array = args->stack;
	get_index(stack->array, stack->max_size);
	return (stack);
}

/**
 * @brief	Creates a copy of the stack.
 * 
 * @param	stack	The stack to copy.
 * 
 * @return	The copied stack.
 */
__attribute__((hot, malloc))
t_stack	*copy_stack(const t_stack *stack)
{
	t_stack	*cpy;

	cpy = new(stack->name, stack->max_size - 1);
	if (cpy == NULL)
		exiting(malloc_failed, RED "Error" RESET \
			":copy_stack(): malloc failed\n");
	cpy->size = stack->size;
	cpy->max_size = stack->max_size;
	ft_memcpy(cpy->array, stack->array, sizeof(t_nb) * stack->size);
	return (cpy);
}
