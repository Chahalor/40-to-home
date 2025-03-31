/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   information.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:37:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 08:30:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"

// Global
//...

// Modules
#include "stack.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((hot))
int	is_sorted(const t_stack *stack)
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
int	get_min_pos(const t_stack *stack)
{
	int	min;
	int	min_pos;
	int	i;

	if (stack == NULL)
		return (-1);
	min = stack->array[0].value;
	min_pos = 0;
	i = -1;
	while (++i < stack->size)
	{
		if (stack->array[i].value < min)
		{
			min = stack->array[i].value;
			min_pos = i;
		}
	}
	return (min_pos);
}

/** */
__attribute__((hot))
int	get_max_pos(const t_stack *stack)
{
	int	max;
	int	max_pos;
	int	i;

	if (stack == NULL)
		return (-1);
	max = stack->array[0].value;
	max_pos = 0;
	i = -1;
	while (++i < stack->size)
	{
		if (stack->array[i].value > max)
		{
			max = stack->array[i].value;
			max_pos = i;
		}
	}
	return (max_pos);
}

/** */
__attribute__((hot))
int	get_right_index(const t_nb nb, const t_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (-1);
	i = -1;
	while (++i < stack->size)
		if (stack->array[i].index > nb.index)
			return (i);
	return (i);
}

/** */
__attribute__((hot))
int	reverse_get_index(const t_nb nb, const t_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (-1);
	i = -1;
	while (++i < stack->size)
	{
		if (stack->array[i].index == nb.index && stack->array[i + 1].index \
			< nb.index)
			return (i);
		else if (stack->array[i].index < nb.index)
			return (i);
	}
	return (i);
}

#pragma endregion	/* Functions */