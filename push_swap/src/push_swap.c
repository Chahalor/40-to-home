/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:09:04 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/04 12:59:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max;
	

	while (stack_a->size)
	{
		i = 0;
		max = stack_b->stack[0];
		while (i < stack_b->size)
		{
			if (stack_b->stack[i] > max)
				max = stack_b->stack[i];
			i++;
		}
		
	}
}

void	sortator(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int i;
	int j;

	pivot = find_median(stack_a);
	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->stack[i] < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
			i++;
	}
	j = sort(stack_b, stack_a);
	while (j > 0)
	{
		pa(stack_a, stack_b);
		j--;
	}
	sort(stack_b, stack_a);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	pivot;
	int	i;
	
	pivot = stack_a->stack[stack_a->size / 2];
	i = 0;
	while (i < argc)
	{
		if (stack_a->stack[i] < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sortator(stack_a, stack_b);
	sortator(stack_b, stack_a);
}

/**
 * @todo everything
 */
int	main(int argc, const char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack(argc, argv);
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
	{
		ft_printf("Error\n");
		return (free_stack(&stack_a), free_stack(&stack_b), MALLOC_ERROR);
	}
	stack_b->stack = (int *)malloc(sizeof(int) * stack_a->size);
	if (!stack_b->stack)
	{
		ft_printf("Error\n");
		return (free_stack(&stack_a), free_stack(&stack_b), MALLOC_ERROR);
	}
	sort_stack(stack_a, stack_b, argc);
	free_stack(stack_a);
	free_stack(stack_b);
	return (SUCCESS);
}
