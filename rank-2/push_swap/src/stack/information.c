/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:37:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/18 08:33:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
#include <stdbool.h>
#include <stdlib.h>

// Global
//...

// Modules
#include "stack.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((hot))
t_bool	is_sorted(const t_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (false);
	i = -1;
	while (++i < stack->size - 1)
		if (stack->array[i].value > stack->array[i + 1].value)
			return (false);
	return (true);
}

/** */
__attribute__((hot))
int	get_max_pos(const t_stack *stack)
{
	int	i;
	int	max;

	if (stack == NULL)
		return (0);
	i = -1;
	max = 0;
	while (++i < stack->size)
		if (stack->array[i].value > max)
			max = stack->array[i].value;
	return (max);
}

/** */
__attribute__((hot))
int	get_right_index(const t_nb nb, const t_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = -1;
	while (++i < stack->size)
		if (stack->array[i].index > nb.index)
			return (i);
	return (i);
}

#pragma endregion	/* Functions */