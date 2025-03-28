/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:37:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/28 09:24:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
	//...

// Global
	//...

// Modules
#include "stack.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief this function will assign the index of each number in the sorted stack
 */
__attribute__((cold, leaf))
void	get_index(t_nb *array, const int size)
{
	int		i;
	int		j;
	int		index;

	i = -1;
	while (++i < size)
	{
		index = 0;
		j = -1;
		while (++j < size)
			if (array[i].value > array[j].value)
				index++;
		array[i].index = index;
	}
}

/** */
__attribute__((hot, leaf))
void	_sort_stack(t_stack **stack)
{
	t_nb	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < (*stack)->size)
	{
		j = i;
		while (++j < (*stack)->size)
		{
			if ((*stack)->array[i].value > (*stack)->array[j].value)
			{
				tmp = (*stack)->array[i];
				(*stack)->array[i] = (*stack)->array[j];
				(*stack)->array[j] = tmp;
			}
		}
	}
}

#pragma endregion	/* Functions */