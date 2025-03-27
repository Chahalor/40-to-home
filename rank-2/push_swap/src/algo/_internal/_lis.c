/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _lis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:51:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/27 12:49:26 by nduvoid          ###   ########.fr       */
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

/** */
__attribute__((cold))
t_lis	get_lis(const t_stack *stack)
{
	t_lis	lis;
	int		i;

	lis.start = 0;
	lis.size = 0;
	i = -1;
	while (++i < stack->size)
	{
		if (stack->array[i].index < stack->array[i + 1].index)
			lis.size++;
		else
			lis = (t_lis){.start = i + 1, .size = 0};
	}
	return (lis);
}

/** */
__attribute__((cold))
void	push_not_lis(t_stack **stack_a, t_stack **stack_b, t_lis bigest_lis)
{
	int	i;

	i = -1;
	while (++i < (*stack_a)->size)
	{	// we can check the cheapest way to put the element in stack_b
		if (i < bigest_lis.start || i > bigest_lis.start + bigest_lis.size)
			interaction(PB, stack_a, stack_b);
		else
			interaction(RA, stack_a, stack_b);
	}
}

int	_lis(t_stack **stack_a, t_stack **stack_b)
{
	const t_lis	bigest_lis = get_lis(*stack_a);	// something like that {.start, .size}
	int			i;
	t_instruct	instuct;

	
	push_not_lis(stack_a, stack_b, bigest_lis);
	while ((*stack_b)->size > 0)
	{
		i = get_max_pos(*stack_b);
		instuct = RB + 4 * (i > (*stack_b)->size / 2);
		while (i-- > 0)
			interaction(instuct, stack_a, stack_b);
		interaction(PA, stack_a, stack_b);
	}
	if (get_min_pos(*stack_a) != 0)
	{
		i = get_min_pos(*stack_a);
		instuct = RA + 4 * (i > (*stack_a)->size / 2);
		while (i-- > 0)
			interaction(instuct, stack_a, stack_b);
	}
	return (0);
}

#pragma endregion	/* Functions */