/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:27:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/19 14:39:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
# include <stdlib.h>

// Global
#include "libft.h"

// Modules
#include "stack.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((cold))
static void	quick_sort(t_stack *stack)
{
	int		i;
	int		wanted_index;

	i = -1;
	while (++i < stack->size)
	{
		wanted_index = get_right_index(stack->array[i], stack);
		if (wanted_index == stack->array[i].index)
			continue ;
		else
		{
			while (stack->array[i].index != wanted_index)
			{
				if (stack->array[i].index > stack->size / 2)
					interaction(RRB, stack, &(t_stack){0});
				else
					interaction(RB, stack, &(t_stack){0});
			}
		}
	}
}

/** */
__attribute__((hot))
static void	sort_one(t_stack *stack_a, t_stack *stack_b)
{
	const int	a_wanted_pos = 0;
	int			b_wanted_pos;
	int			a_curent_pos;
	int			b_curent_pos;

	a_curent_pos = get_max_pos(stack_a);
	b_curent_pos = 0;
	b_wanted_pos = get_right_index(stack_b->array[b_curent_pos], stack_b);
	ft_printf("a_curent_pos: %d, a_wanted= %d, b_current = %d, b_wanted = %d\n", a_curent_pos, a_wanted_pos, b_curent_pos, b_wanted_pos);	// rm
	while (a_curent_pos != a_wanted_pos && b_curent_pos != b_wanted_pos)
	{
		if (a_curent_pos != a_wanted_pos && b_curent_pos != b_wanted_pos)
		{
			if (a_curent_pos > stack_a->size / 2 && b_wanted_pos < stack_b->size / 2)
				interaction(RRR, stack_a, stack_b);
			else if (a_curent_pos < stack_a->size / 2 && b_wanted_pos > stack_b->size / 2)
				interaction(RR, stack_a, stack_b);
			else if (a_curent_pos > stack_a->size / 2)
				interaction(RRA, stack_a, stack_b);
			else if (b_wanted_pos < stack_b->size / 2)
				interaction(RB, stack_a, stack_b);
			else
				interaction(RA, stack_a, stack_b);
		}
		else if (a_curent_pos != a_wanted_pos)
		{
			if (a_curent_pos > stack_a->size / 2)
				interaction(RRA, stack_a, stack_b);
			else
				interaction(RA, stack_a, stack_b);
		}
		else
		{
			if (b_wanted_pos < stack_b->size / 2)
				interaction(RB, stack_a, stack_b);
			else
				interaction(RR, stack_a, stack_b);
		}
	}
}

/** */
__attribute__((hot))
int	_turkish(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return (0);
	interaction(PB, stack_a, stack_b);
	interaction(PB, stack_a, stack_b);
	while (!is_sorted(stack_a) && stack_a->size > 0)
		sort_one(stack_a, stack_b);
	ft_printf("after sort_one\n");		// rm
	quick_sort(stack_b);
	ft_printf("after quick_sort\n");	// rm
	while (stack_b->size > 0)
		interaction(PA, stack_a, stack_b);
	return (0);
}

#pragma endregion	/* Functions */