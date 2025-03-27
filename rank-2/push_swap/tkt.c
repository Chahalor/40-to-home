/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:39:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/27 16:45:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	move_uncommon(t_stack **stack_a, t_stack **stack_b);

static void	algo2(t_stack *a_stk, t_stack *stack_b)
{
	t_stack	*lis;

	lis = ft_get_lis2(a_stk);
	if (!lis)
		return ;
	ft_move_uncommons(a_stk, stack_b, lis);
	ft_clear_stacks(&lis, NULL);
	ft_best_movements(a_stk, stack_b);
	ft_min_to_the_top(a_stk, a_stk, a_stk->inst);
}

static void	algo1(t_stack *a_stk, t_stack *stack_b)
{
	t_stack	*lis;

	lis = ft_get_lis1(a_stk);
	if (!lis)
		return ;
	ft_move_uncommons(a_stk, stack_b, lis);
	ft_clear_stacks(&lis, NULL);
	ft_best_movements(a_stk, stack_b);
	ft_min_to_the_top(a_stk, a_stk, a_stk->inst);
}

void	ft_lis_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack_a2;
	t_stack	*stack_b2;

	stack_a2 = copy_stack(*stack_a);
	stack_b2 = copy_stack(*stack_b);
	if (!stack_a2 || !stack_b2)
	{
		destroyer(stack_a2);
		destroyer(stack_b2);
		return ;
	}
	algo2(stack_a2, stack_b2);
	algo1((*stack_a), stack_b);
}
