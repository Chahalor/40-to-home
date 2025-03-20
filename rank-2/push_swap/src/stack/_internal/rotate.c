/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:39:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/20 12:22:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/** */
__attribute__((hot, leaf))
void	rotate(t_stack **stackp)
{
	register t_nb	tmp;
	register int	i;
	t_stack			*stack;

	stack = *stackp;
	if (stack == NULL || stack->size < 2)
		return ;
	tmp = stack->array[0];
	i = stack->size;
	while (--i > 0)
		stack->array[i] = stack->array[i - 1];
	stack->array[0] = tmp;
}

/** */
__attribute__((hot))
void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

/** */
__attribute__((hot, leaf))
void	reverse_rotate(t_stack **stackp)
{
	register t_nb	tmp;
	register int	i;
	t_stack			*stack;

	stack = *stackp;
	if (stack == NULL || stack->size < 2)
		return ;
	tmp = stack->array[stack->size - 1];
	i = -1;
	while (++i < stack->size - 1)
		stack->array[i + 1] = stack->array[i];
	stack->array[0] = tmp;
}

/** */
__attribute__((hot))
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
