/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 08:29:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/27 08:53:53 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
#include <stdlib.h>

// Global
#include "types.h"

// Modules
#include "_algo.h"
#include "stack.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((always_inline, used, pure))
inline int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/** */
__attribute__((always_inline, used, pure))
inline int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

/** */
__attribute__((always_inline, used, leaf, pure))
inline t_magic	get_magic(const t_stack *stack)
{
	if (stack->size <= 200)
		return (t_magic){.val1 = 20, .val2 = 5};
	else if (stack->size <= 500)
		return (t_magic){.val1 = 15, .val2 = 4};
	else if (stack->size <= 750)
		return (t_magic){.val1 = 13, .val2 = 3.5};
	else if (stack->size <= 1000)
		return (t_magic){.val1 = 10, .val2 = 3};
	else
		return (t_magic){.val1 = 8, .val2 = 2.5};
}

/** */
__attribute__((hot))
t_stack	**quick_acces(t_stack **stack, const char who)
{
	static t_stack	**stack_a = NULL;
	static t_stack	**stack_b = NULL;

	if (who == 'A')
	{
		if (!stack_a)
			stack_a = stack;
		else
			return (stack_a);
	}
	else if (who == 'B')
	{
		if (!stack_b)
			stack_b = stack;
		else
			return (stack_b);
	}
	else
		return (NULL);
	return (NULL);
}

/** */
__attribute__((always_inline, cold, used))
inline void	sort_3(t_stack **stack_a, t_stack **stack_b)
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

#pragma endregion	/* Functions */