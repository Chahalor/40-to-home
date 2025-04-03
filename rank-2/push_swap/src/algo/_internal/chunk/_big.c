/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _big.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:37:32 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 12:56:27 by nduvoid          ###   ########.fr       */
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

/** */
__attribute__((always_inline, used, leaf))
static inline int	ft_range(t_stack **stack_a)
{
	if ((*stack_a)->size > 100)
		return (32);
	else
		return (11);
}

/** */
__attribute__((always_inline, used, leaf))
static inline int	sorted(t_stack **stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < (*stack_a)->size / 2)
	{
		if ((*stack_a)->array[j].value > (*stack_a)->array[j].value)
			i++;
	}
	return (i);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_cost	cost;

	cost = (t_cost){.index = 0, .sorted = sorted(stack_a) > \
		(*stack_a)->size / 3,
		.range = ft_range(stack_a)
	};
	while ((*stack_a)->size > 0)
	{
		if ((*stack_a)->array[0].index <= cost.index)
		{
			interaction(PB, stack_a, stack_b);
			++cost.index;
		}
		else if ((*stack_a)->array[0].index <= (cost.index + cost.range))
		{
			interaction(PB, stack_a, stack_b);
			interaction(RB, stack_a, stack_b);
			++cost.index;
		}
		else
			interaction(RA + 2 * (!!cost.sorted), stack_a, stack_b);
	}
}

#pragma endregion	/* Functions */