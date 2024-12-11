/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:23:51 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 11:28:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	is_digits(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	in_stack(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_all	*init_stacks(int argc, const char *argv[])
{
	t_all	*all;
	int		i;

	all = (t_all *)ft_calloc(1, sizeof(t_all) 
		+ 2 * (sizeof(t_stack) + argc + 1 * sizeof(int)));
	if (!all)
		exiting(MALLOC_ERROR);
	all->stack_a = (t_stack *)(all + 1);
	all->stack_b = (t_stack *)(all->stack_a + 1);
	all->stack_a->stack = (int *)(all->stack_b + 1);
	all->stack_b->stack = (int *)(all->stack_a->stack + argc + 1);
	all->stack_a->size = 0;
	all->stack_b->size = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_digits(argv[i]) || in_stack(all->stack_a, ft_atoi(argv[i])))
		{
			free(all);
			exiting(ARG_ERROR);
		}
		all->stack_a->stack[all->stack_a->size++] = ft_atoi(argv[i]);
		i++;
	}
	return (all);
}
