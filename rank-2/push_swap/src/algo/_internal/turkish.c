/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:27:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/25 15:50:11 by nduvoid          ###   ########.fr       */
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

void	extraction(t_stack **stack_a, t_stack **stack_b)
{
	int		cost_up;
	int		cost_down;
	int		max_pos;
	int		cheapest;
	int operation;
	
	while ((*stack_b)->size > 0)
	{
		max_pos = get_max_pos(*stack_b);
		cost_up = max_pos;
		cost_down = (*stack_b)->size - max_pos;
		cheapest = cost_up < cost_down ? cost_up : cost_down;
		operation = 1 + (-2 * (cost_up < cost_down));
		while (cheapest += operation > 0)
		{
			if (cost_up < cost_down)
				interaction(RB, stack_a, stack_b);
			else
				interaction(RRB, stack_a, stack_b);
		}
		interaction(PA, stack_a, stack_b);
	}
}

/** */
__attribute__((hot))
t_actions	get_actions(const int a_wanted, const int b_wanted,
	const int a_curent_pos, const int b_curent_pos)
{
	const int	a_up = a_curent_pos - a_wanted;							// cost to move a_wanted with RA
	const int	a_down = (*quick_acces(NULL, 'A'))->size - a_wanted;	// cost to move a_wanted with RRA
	const int	b_down = b_curent_pos - b_wanted;						// cost to move b_wanted with RB
	const int	b_up = (*quick_acces(NULL, 'B'))->size - b_wanted;		// cost to move b_wanted with RRB
	const int	nb_double = 0;// min(a_up + b_up, a_down + b_down) * (a_curent_pos != a_wanted && b_curent_pos != b_wanted);

	return ((t_actions){
		.multiple = {
			.instuct = RR + 3 * (a_up + b_up > a_down + b_down),	// il va falloir prendre en compte que a_up + b_up < a_up + b_down
			.number = nb_double,
		},
		.only_a = {	// on doit probablement pas prendre en compte les mouvement de multiple (erreur)
			.instuct = RA + 2 * (a_up < a_down),
			.number = min(a_up, a_down) - nb_double,
		},
		.only_b = {
			.instuct = RB + 4 * (b_up < b_down),
			.number = min(b_up, b_down) - nb_double,
		}
	});
}

/** */
__attribute__((hot))
static void	sort_one(t_stack **stack_a, t_stack **stack_b)
{
	const int	a_curent_pos = get_max_pos(*stack_a);
	const int	a_wanted = 0;	// we can check if the cost of just keeping max(A) is lower than the cost of moving it
	const int	b_curent_pos = 0;
	const int	b_wanted = get_right_index((*stack_b)->array[b_curent_pos], *stack_b);
	t_actions	actions;

	# if DEBUG == 1
		ft_printf("{a_curent_pos: %d | a_wanted: %d | b_curent_pos: %d | b_wanted: %d}\n",
			a_curent_pos, a_wanted, b_curent_pos, b_wanted);	// rm
		print_stack(*stack_a);	// rm
		print_stack(*stack_b);	// rm
	#endif	// rm
	actions = get_actions(a_wanted, b_wanted, a_curent_pos, b_curent_pos);
	# if DEBUG == 1
		ft_printf("Actions: { multiple: %d (%d) | only_a: %d (%d) | only_b: %d (%d) }\n",
			actions.multiple.instuct, actions.multiple.number,
			actions.only_a.instuct, actions.only_a.number,
			actions.only_b.instuct, actions.only_b.number);
	# endif	// rm
	while (actions.multiple.number-- > 0)
		interaction(actions.multiple.instuct, stack_a, stack_b);
	while (actions.only_a.number-- > 0)
		interaction(actions.only_a.instuct, stack_a, stack_b);
	while (actions.only_b.number-- > 0)
		interaction(actions.only_b.instuct, stack_a, stack_b);
	interaction(PB, stack_a, stack_b);
}

/** */
__attribute__((hot))
int	_turkish(t_stack **stack_a, t_stack **stack_b)
{
	quick_acces(stack_a, 'A');
	quick_acces(stack_b, 'B');
	interaction(PB, stack_a, stack_b);
	interaction(PB, stack_a, stack_b);
	while ((*stack_a)->size > 0)
		sort_one(stack_a, stack_b);
	// while ((*stack_b)->size > 0)
	// 	interaction(PA, stack_a, stack_b);
	extraction(stack_a, stack_b);	// big fat boucle infinit et j ai cree cette fonction pour remplacer le faite que B est pas trier avec l algo de base (bruh)
	return (0);
}

// 1 4 2 5 3

#pragma endregion	/* Functions */