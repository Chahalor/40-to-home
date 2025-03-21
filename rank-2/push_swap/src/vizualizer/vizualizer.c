/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:29:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/21 15:36:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"

// Global
#include "vizualizer.h"

// Modules
	//...

#pragma endregion	/* Header */
#pragma region "Functions"

#include <stdio.h>
#include <unistd.h> // Pour sleep()

// "\033[%d;15H%s";
void	show_stacks(const t_stack *stack_a, const t_stack *stack_b,
	const t_instruct instruct)
{
	// int	i;
	// int val_a;
	// int val_b;

	// if (!stack_a || !stack_b || instruct == NONE)
	// 	return ;
	// ft_printf("__%c__ --- __%c__\n", stack_a->name, stack_b->name);
	// i = -1;
	// while (++i < stack_a->size)
	// {
	// 	if (i < stack_a->size)
	// 		ft_printf("")
	// }
}

#pragma endregion	/* Functions */