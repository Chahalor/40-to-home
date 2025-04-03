/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:37:48 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:55:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
//...

// Global
#include "types.h"

// Modules
//...

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief this function will assign the index of each number in the sorted stack
 * 
 * @param array the stack to sort
 * @param size the size of the stack
 * 
 * @return void
 */
__attribute__((cold, leaf))
void	get_index(t_nb *array, const int size)
{
	register int	i;
	register int	j;
	int				index;

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

/**
 * @brief this function will sort the stack in ascending order using the bubble
 * sort algorithm
 * 
 * @param stack the stack to sort
 * 
 * @return 0 if the stack is sorted, 1 if the stack is not sorted
 */
__attribute__((hot, leaf))
int	_sort_stack(t_stack **stack)
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
	return (0);
}

/**
 * @brief do nothing
 * 
 * @param stack_a the first stack
 * @param stack_b the second stack
 * 
 * @return 0 anyway
 */
__attribute__((cold, pure, leaf, const))
int	none(const t_stack **stack_a, const t_stack **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	return (0);
}

#pragma endregion	/* Functions */