/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:30:55 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 11:22:54 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	if (!stack)
	{
		ft_printf("Stack is NULL\n");
		return ;
	}
	i = 0;
	ft_printf("Stack size: %d\n", stack->size);
	ft_printf("[");
	while (i < stack->size)
	{
		ft_printf("%d, ", stack->stack[i]);
		i++;
	}
	ft_printf("]\n");
}

void	print_all(t_all *all)
{
	ft_printf("Stack A:\n");
	print_stack(all->stack_a);
	ft_printf("Stack B:\n");
	print_stack(all->stack_b);
}
