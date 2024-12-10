/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:26:44 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/10 14:57:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tester.h"

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

void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
}

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
