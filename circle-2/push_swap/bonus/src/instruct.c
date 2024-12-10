/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:08:04 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/09 11:08:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tester.h"

void	sa(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_a < 2)
		return ;
	tmp = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[1];
	stacks->stack_a[1] = tmp;
}

void	sb(t_stack *stacks)
{
	int	tmp;

	if (stacks->size_b < 2)
		return ;
	tmp = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[1];
	stacks->stack_b[1] = tmp;
}

void	ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_stack *stacks)
{
	int	i;

	if (stacks->size_b == 0)
		return ;
	i = stacks->size_a;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
	stacks->stack_a[0] = stacks->stack_b[0];
	i = 0;
	while (i < stacks->size_b - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->size_a++;
	stacks->size_b--;
}

void	pb(t_stack *stacks)
{
	int	i;

	if (stacks->size_a == 0)
		return ;
	i = stacks->size_b;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
	stacks->stack_b[0] = stacks->stack_a[0];
	i = 0;
	while (i < stacks->size_a - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->size_b++;
	stacks->size_a--;
}
