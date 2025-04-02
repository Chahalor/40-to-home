/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _chunck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:19:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 13:49:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
	//...

// Global
	//...

// Modules
#include "stack.h"
#include "_algo.h"
#include "chunk/_chunk.h"

#pragma endregion	/* Header */
#pragma region "Functions"

__attribute__((always_inline, used))
void	small(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size <= 3)
		return (sort_3(stack_a, stack_b));
	else
		return (_four_or_five(stack_a, stack_b));
}

__attribute__((always_inline, used))
void	split(t_stack **stack_a, t_stack **stack_b)
{
	const int		size = (*stack_a)->size;
	unsigned int	block;
	register int	start;
	register int	end;

	block = _block_size((*stack_a)->size);
	end = block;
	start = 0;
	while (start < size)
	{
		while (TRUE)
		{
			if (!_block(stack_a, stack_b, start, end))
				break ;
			interaction(PB, stack_a, stack_b);
			if ((*stack_b)->size > 3 && (*stack_b)->array[0].value \
				< start + ((end - start) / 2))
				interaction(RB, stack_a, stack_b);
		}
		start += block;
		end += block;
	}
}

__attribute__((always_inline, used))
void	big(t_stack **stack_a, t_stack **stack_b)
{
	t_cost	cost;

	while ((*stack_b)->size > 0)
	{
		cost = _best(stack_a, stack_b);
		while (cost.cost_a-- > 0 && cost.cost_b-- > 0)
		{
			interaction(RA, stack_a, stack_b);
			interaction(RB, stack_a, stack_b);
		}
		while (cost.cost_a++ < 0 && cost.cost_b++ < 0)
		{
			interaction(RRA, stack_a, stack_b);
			interaction(RRB, stack_a, stack_b);
		}
		while (cost.cost_a-- > 0)
			interaction(RA, stack_a, stack_b);
		while (cost.cost_a++ < 0)
			interaction(RRA, stack_a, stack_b);
		while (cost.cost_b-- > 0)
			interaction(RB, stack_a, stack_b);
		while (cost.cost_b++ < 0)
			interaction(RRB, stack_a, stack_b);
		interaction(PA, stack_a, stack_b);
	}
}

/** */
__attribute__((always_inline, used))
void	correct(t_stack **stack, t_stack **stack_b)
{
	register int	min;
	register int	i;

	min = 0;
	i = -1;
	while (++i != (*stack)->size)
		if ((*stack)->array[i].value < (*stack)->array[min].value)
			min = i;
	if (min <= (*stack)->size / 2)
		while (min--)
			interaction(RA, stack, stack_b);
	else
		while (min++ < (*stack)->size)
			interaction(RRA, stack, stack_b);
}

int	_chunk(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size <= 5)
		small(stack_a, stack_b);
	else
	{
		split(stack_a, stack_b);
		big(stack_a, stack_b);
		correct(stack_a, stack_b);
	}
	print_stack(*stack_a);
	print_stack(*stack_b);
	return (0);
}

#pragma endregion	/* Functions */