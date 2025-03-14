/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/14 15:49:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/** */
__attribute__((cold))
void	*destroyer(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	free(stack->array);
	free(stack);
	return (NULL);
}

/** */
__attribute__((cold, malloc))
t_stack	*new(const char name, const int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) + sizeof(t_nb) * size);
	if (stack == NULL)
		return (NULL);
	*stack = (t_stack){.array = (t_nb *)(stack + 1), .size = size, .name = name};
	return (stack);
}
