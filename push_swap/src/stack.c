/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:23:51 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 08:49:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->stack)
		free(stack->stack);
	free(stack);
}

t_bool	is_in_stack(t_stack *stack, int content)
{
	int	i;

	if (!stack->stack)
		return (false);
	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i++] == content)
			return (true);
	}
	return (false);
}
t_bool	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (false);
		i++;
	}
	return (true);
}

t_bool	is_nbr(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

t_stack	*init_stack(int argc, const char **argv)
{
	t_stack	*stack;

	stack = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 1;
	stack->stack = (int *)ft_calloc(argc, sizeof(int));
	if (!stack->stack)
		return (free(stack), NULL);
	if (!argv || argc <= 1)
		return (stack);
	while (stack->size < argc)
	{
		if (!is_nbr(argv[stack->size])
			|| is_in_stack(stack, ft_atoi(argv[stack->size])))
			return (free(stack->stack), NULL);
		stack->stack[stack->size] = ft_atoi(argv[stack->size]);
		stack->size++;
	}
	if (!is_sorted(stack))
		return (stack);
	free_stack(stack);
	exit(SORTED);
}
