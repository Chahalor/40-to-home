/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _small.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:32:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:44:36 by nduvoid          ###   ########.fr       */
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

/**
 * @brief this function sort 3 elements stack by the most efficient way
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return void
 */
__attribute__((cold))
void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	const int			top = (*stack_a)->array[0].value;
	const int			mid = (*stack_a)->array[1].value;
	const int			bot = (*stack_a)->array[2].value;
	const int			swap = ((top > mid) << 2) | ((mid > bot) << 1)
		| (top > bot);
	const t_instruct	moves[8][2] = {{NONE, NONE}, {SA, NONE}, {RRA, SA},
	{RRA, NONE}, {SA, NONE}, {RA, NONE}, {RRA, NONE}, {SA, RRA}};

	interaction(moves[swap][0], stack_a, stack_b);
	interaction(moves[swap][1], stack_a, stack_b);
}

/**
 * @brief this function sort 4 or 5 elements stack by the most efficient way
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return void
 */
__attribute__((cold))
void	four_or_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	while ((*stack_a)->size > 3)
	{
		min = get_min_pos(*stack_a);
		if (min <= (*stack_a)->size / 2)
			while (min-- > 0)
				interaction(RA, stack_a, stack_b);
		else
			while (((*stack_a)->size - min++) > 0)
				interaction(RRA, stack_a, stack_b);
		interaction(PB, stack_a, stack_b);
	}
	sort_3(stack_a, stack_b);
	while ((*stack_b)->size)
		interaction(PA, stack_a, stack_b);
}

#pragma endregion	/* Functions */