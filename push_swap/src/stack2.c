/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:30:15 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/28 15:34:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_top_stack(t_list **stack, t_list *new)
{
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

int	get_stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack->next)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}