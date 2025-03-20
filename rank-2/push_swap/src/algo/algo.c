/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:29:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/20 12:44:57 by nduvoid          ###   ########.fr       */
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

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((hot))
t_error	turkish(t_stack **stack_a, t_stack **stack_b)
{
	if ((is_sorted(*stack_a) && (*stack_a)->size > 0) || (*stack_a)->size == 0)
		return (0);
	return (_turkish(stack_a, stack_b));
}

/** */
__attribute__((hot))
t_error	mein_random(t_stack **stack_a, t_stack **stack_b)
{
	int		seed;

	seed = (size_t)((*stack_a)->array);
	while (!is_sorted(*stack_a))
	{
		seed ^= (seed >> (size_t)&(*stack_a)->array[0]) ^ (seed << 7) ^ (seed >> 4);
		interaction(seed % RRR, stack_a, stack_b);
		seed = (seed % 10) + 1;
	}
	return (0);
}

/** */
__attribute__((hot))
t_error	miracle(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	ft_printf("were waiting for the miracle...\n");
	if (is_sorted(*stack_a))
	{
		ft_printf("the miracle is here! No, the stack is just already sorted\n");
		return (0);
	}
	while (!is_sorted(*stack_a))
		;
	ft_printf("wait wait guys, do we just saw a miracle ???\n");
	return (0);
}

#pragma endregion	/* Functions */