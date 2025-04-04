/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _turkish.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:27:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:49:19 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
#include <stdlib.h>

// Global
#include "libft.h"

// Modules
#include "stack.h"
#include "_algo.h"
#include "debug.h"
#include "utils.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief this function get the cheapest way to push the bigest element of
 * stack_a to stack_b and sort the elements inside stack_b.
 * 
 * @param a_wanted the wanted position of the element in stack_a
 * @param b_wanted the wanted position of the element in stack_b
 * @param a_curent_pos the current position of the element in stack_a
 * @param b_curent_pos the current position of the element in stack_b
 * 
 * @return the actions to do to push the bigest element of stack_a to stack_b
 */
__attribute__((hot))
t_actions	get_actions(const int a_wanted, const int b_wanted,
	const int a_curent_pos, const int b_curent_pos)
{
	const int	a_up = a_curent_pos - a_wanted;	
	const int	a_down = (*quick_acces(NULL, 'A'))->size - a_curent_pos
		+ a_wanted;
	const int	b_down = b_curent_pos - b_wanted;
	const int	b_up = (*quick_acces(NULL, 'B'))->size - b_curent_pos
		+ b_wanted;
	int			nb_double;

	nb_double = min(a_up + b_up, a_down + b_down) * (a_curent_pos
			!= a_wanted && b_curent_pos != b_wanted);
	nb_double *= (nb_double > 0) * (a_up + b_up > a_down + b_up
			&& a_up + b_up > a_up + b_up && a_down + b_down > a_down
			+ b_up && a_down + b_down > a_up + b_up);
	return ((t_actions){
		.multiple = {.instuct = (RR + 3 * (a_up + b_up > a_down + b_down)),
			.number = nb_double,
		},
		.only_a = {.instuct = RA + 2 * (a_up > a_down),
			.number = min(a_up, a_down) - nb_double,
		},
		.only_b = {.instuct = RB + 4 * (b_up > b_down),
			.number = min(b_up, b_down) - nb_double,
		}
	});
}

/**
 * @brief this function psuh the bigest element of stack_a to stack_b
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return void
*/
__attribute__((hot))
static void	sort_one(t_stack **stack_a, t_stack **stack_b)
{
	const int	a_curent_pos = get_min_pos(*stack_a);
	const int	a_wanted = 0;
	const int	b_curent_pos = 0;
	const int	b_wanted = reverse_get_index((*stack_b)->array[b_curent_pos],
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
}

/**
 * @brief this function is the main function of the turkish algorithm
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return 0 if the stack is sorted or empty, else the result of the algorithm
 * 
 * @details how it works:
 * 
 * 1. push two elements from stack_a to stack_b
 * 
 * 2. try to find the cheapest way to push the bigest element of stack_a to
 * 
 *  stack_b. At the same time sort the elements inside stack_b
 * 
 * 3. push the elements of stack_b to stack_a
 */
__attribute__((hot))
int	_turkish(t_stack **stack_a, t_stack **stack_b)
{
	quick_acces(stack_a, 'A');
	quick_acces(stack_b, 'B');
	while ((*stack_a)->size > 0)
		sort_one(stack_a, stack_b);
	while ((*stack_b)->size > 0)
		interaction(PA, stack_a, stack_b);
	return (0);
}

#pragma endregion	/* Functions */