/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:27:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/21 15:39:08 by nduvoid          ###   ########.fr       */
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
__attribute__((hot))
t_actions	get_actions(const int a_wanted, const int b_wanted,
	const int a_curent_pos, const int b_curent_pos)
{
	const int	a_up = a_curent_pos - a_wanted;
	const int	a_down = (*quick_acces(NULL, 'A'))->size - a_curent_pos;
	const int	b_up = b_curent_pos - b_wanted;
	const int	b_down = (*quick_acces(NULL, 'B'))->size - b_curent_pos;
	const int	nb_double = max(min(a_up, b_up), min(a_down, b_down));

	return ((t_actions){
		.multiple = {
			.instuct = RR + (a_up + b_up < a_down + b_down),	// il va falloir prendre en compte que a_up + b_up < a_up + b_down
			.number = nb_double,
		},
		.only_a = {
			.instuct = RA + 2 * (a_up < a_down),
			.number = max(a_up, a_down) - nb_double,
		},
		.only_b = {
			.instuct = RB + 4 * (b_up < b_down),
			.number = max(b_up, b_down) - nb_double,
		}
	});
}

/** */
__attribute__((hot, unused))
static void	sort_one(t_stack **stack_a, t_stack **stack_b)
{
	const int	a_curent_pos = get_max_pos(*stack_a);
	ft_printf("a_curent_pos: %d\n", a_curent_pos);	// rm
	const int	a_wanted = 0;	// we can check if the cost of just keeping max(A) is lower than the cost of moving it
	const int	b_curent_pos = 0;
	const int	b_wanted = get_right_index((*stack_b)->array[b_curent_pos],
		*stack_b);
	t_actions	actions;

	actions = get_actions(a_wanted, b_wanted, a_curent_pos, b_curent_pos);
	while (actions.multiple.number-- > 0)
		interaction(actions.multiple.instuct, stack_a, stack_b);
	while (actions.only_a.number-- > 0)
		interaction(actions.only_a.instuct, stack_a, stack_b);
	while (actions.only_b.number-- > 0)
		interaction(actions.only_b.instuct, stack_a, stack_b);
	interaction(PB, stack_a, stack_b);
	// rm the unused tag
}


/** */
__attribute__((hot))
int	_turkish(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return (0);
	quick_acces(stack_a, 'A');
	quick_acces(stack_b, 'B');
	while ((*stack_a)->size > 0)
	{
		sort_one(stack_a, stack_b);
		ft_printf("----\n");		// rm
		print_stack(*stack_a);	// rm
		print_stack(*stack_b);	// rm
		ft_printf("----\n");		// rm
	}
	// while ((*stack_b)->size > 0)
	// 	interaction(PA, stack_a, stack_b);
	return (0);
}

#pragma endregion	/* Functions */