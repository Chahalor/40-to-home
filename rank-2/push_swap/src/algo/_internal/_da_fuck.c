/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _da_fuck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:59:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/26 14:30:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
# include <stdlib.h>

// Global
#include "libft.h"

// Modules
#include "stack.h"
#include "_algo.h"
#include "debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

int	find_centil(const t_stack *stack, t_stack *cpy, const int magic)
{
	int	i;
	int	result;

	i = -1;
	while (++i < stack->size - 1)
	{
		if (cpy->array[i].value == stack->array[magic].value)
		{
			result =  cpy->array[i].value;
			return ((void)destroyer(cpy), result);
		}
	}
	destroyer(cpy);
	return (0);
}

int	get_centile(const t_stack *stack, const int magic)
{
	int		index;
	t_stack	*cpy;

	if (!stack || stack->size == 0)
		return (0);
	index = (magic / 100) * (stack->size - 1);
	if (!is_sorted(stack))
	{
		cpy = copy_stack(stack);
		interaction(SORT, &cpy, (t_stack **)stack);
		return (find_centil(stack, cpy, magic));
	}
	else
		return (stack->array[index].value);
}

void	first_stage(t_stack **stack_a, t_stack **stack_b, const t_magic magic_nb)
{
	int		i;
	int		percentil;
	t_nb	to_push;

	percentil = get_centile(*stack_a, magic_nb.val1);
	i = 0;
	while (i < (*stack_a)->size - 1 && (*stack_a)->array[i].value > percentil)
		++i;
	to_push = (*stack_a)->array[i];
	while (i-- > 0)
		interaction(RA - (i < (*stack_a)->size / 2), stack_a, stack_b);
	percentil = get_centile(*stack_a, magic_nb.val2);
	if (to_push.value > percentil)
	{
		interaction(PB, stack_a, stack_b);
		interaction(RB, stack_a, stack_b);
	}
	else
		interaction(PB, stack_a, stack_b);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	index_max;

	while ((*stack_b)->size > 0)
	{
		index_max = get_max_pos(*stack_b);
		if (index_max > (*stack_b)->size / 2)
			while (index_max++ < (*stack_b)->size)
				interaction(RB, stack_a, stack_b);
		else
			while (index_max-- > 0)
				interaction(RRB, stack_a, stack_b);
		interaction(PA, stack_a, stack_b);
	}
}

int	_da_fuck(t_stack **stack_a, t_stack **stack_b)
{
	const t_magic magic_nb = get_magic(*stack_a);
	
	while ((*stack_a)->size > 0)
		first_stage(stack_a, stack_b, magic_nb);
	push_to_a(stack_a, stack_b);
	return (1);
}

#pragma endregion	/* Functions */