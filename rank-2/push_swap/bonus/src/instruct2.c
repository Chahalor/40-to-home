/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:26:44 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 09:11:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tester.h"

/**
 * @brief rotate the stack a, the first element becomes the last
 */
void	ra(t_stack *stacks)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stacks->stack_a[0];
	while (++i < stacks->size_a)
		stacks->stack_a[i - 1] = stacks->stack_a[i];
	stacks->stack_a[i - 1] = tmp;
}

/**
 * @brief rotate the stack b, the first element becomes the last
 */
void	rb(t_stack *stacks)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stacks->stack_b[0];
	while (++i < stacks->size_b)
		stacks->stack_b[i - 1] = stacks->stack_b[i];
	stacks->stack_b[i - 1] = tmp;
}

/**
 * @brief rotate the stack a and b at the same time
 */
void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
}

/**
 * @brief reverse rotate the stack a, the last element becomes the first
 */
void	rra(t_stack *stacks)
{
	int	i;
	int	tmp;

	i = stacks->size_a;
	tmp = stacks->stack_a[i - 1];
	while (--i > 0)
		stacks->stack_a[i] = stacks->stack_a[i - 1];
	stacks->stack_a[0] = tmp;
}

/**
 * @brief reverse rotate the stack b, the last element becomes the first
 */
void	rrb(t_stack *stacks)
{
	int	i;
	int	tmp;

	i = stacks->size_b;
	tmp = stacks->stack_b[i - 1];
	while (--i > 0)
		stacks->stack_b[i] = stacks->stack_b[i - 1];
	stacks->stack_b[0] = tmp;
}
