/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 13:10:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"
#include "stack.h"
#include "parsing.h"
#include "utils.h"
#include <stdbool.h>

/**
 * @brief	Perform the action on the stack. But don't print the action.
 * 
 * @param	instruct	The instruction to perform.
 * @param	stack_a		Pointer to the first stack.
 * @param	stack_b		Pointer to the second stack.
 * 
 * @return	void
 */
__attribute__((hot))
void	interaction2(const t_instruct instruct, t_stack **stack_a,
	t_stack **stack_b)
{
	static int (*const	actions[])() = {
	[PA] = push, [PB] = push, [SA] = swap, [SB] = swap,
	[SS] = swap_both, [RA] = rotate, [RB] = rotate,
	[RR] = rotate_both, [RRA] = reverse_rotate, [RRB] = reverse_rotate,
	[RRR] = reverse_rotate_both, [SORT] = _sort_stack, [NONE] = none};

	if (*stack_a == NULL || *stack_b == NULL || instruct < PA
		|| instruct > SORT)
		return ;
	else if (instruct == PA || instruct == RB || instruct == RRB)
		actions[instruct](stack_b, stack_a);
	else
		actions[instruct](stack_a, stack_b);
}
