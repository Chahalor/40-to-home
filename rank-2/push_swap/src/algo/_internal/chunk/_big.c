/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _big.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:37:32 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 17:48:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
	//...

// Global
	//...

// Modules
#include "_chunk.h"

#pragma endregion	/* Header */
#pragma region "Functions"

__attribute__((always_inline, used))
static inline int	_find_pos(t_stack **stack, const int val)
{
	const int		min = (*stack)->array[get_min_pos(*stack)].value;
	const int		max = (*stack)->array[get_max_pos(*stack)].value;
	register int	i;
	register int	j;

	if (val < min || val > max)
	{
		i = 0;
		while (i != (*stack)->size)
			if ((*stack)->array[i++].value == min)
				return (i);
	}
	i = -1;
	while (++i != (*stack)->size)
	{
		j = (i + 1) % (*stack)->size;
		if ((*stack)->array[j].value < val && val < (*stack)->array[j].value)
			return (j);
	}
	return (0);
}

__attribute__((hot))
t_cost	_best(t_stack **stack_a, t_stack **stack_b)
{
	t_cost			best;
	t_cost			cost;
	unsigned int	pos_a;
	int				i;

	pos_a = _find_pos(stack_a, (*stack_b)->array[0].value);
	best = (t_cost)
	{
		(*stack_b)->array[0].value, 
		pos_a,
		0,
		get_rotation_cost(pos_a, (*stack_a)->size),
		get_rotation_cost(0, (*stack_b)->size),
		0
	};
	best.total = (best.cost_a * (-1 * (best.cost_a > 0)) \
				+ best.cost_b * (-1 * (best.cost_b > 0)));
	i = -1;
	while (++i < (*stack_b)->size)
	{
		pos_a = _find_pos(stack_a, (*stack_b)->array[i].value);
		cost = (t_cost)
		{
			.val = (*stack_b)->array[i].value,
			.pos_a = pos_a,
			.pos_b = i,
			.cost_a = get_rotation_cost(pos_a, (*stack_a)->size),
			.cost_b = get_rotation_cost(i, (*stack_b)->size),
			0
		};
		cost.total = (cost.cost_a * (-1 * (cost.cost_a > 0)) \
					+ cost.cost_b * (-1 * (cost.cost_b > 0)));
		if (cost.total < best.total)
			best = cost;
	}
	return (best);
}

#pragma endregion	/* Functions */