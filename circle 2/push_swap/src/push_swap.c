/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:09:04 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 09:59:30 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *stack_a = NULL;
t_stack *stack_b = NULL;

/**
 * @todo everything
 */
int	main(int argc, const char **argv)
{
	stack_a = init_stack(argc, argv);
	stack_b = init_stack(argc, NULL);
	if (!stack_a || !stack_b)
	{
		write(2, "Error\n", 6);
		return (free_stack(stack_a), free_stack(stack_b), MALLOC_ERROR);
	}
	radix_sort();
	// print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (SUCCESS);
}
