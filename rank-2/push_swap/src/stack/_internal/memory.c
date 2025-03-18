/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:08:42 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/17 13:21:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stack.h"

/**
 * @brief this function will assign the index of each number in the sorted stack
 */
__attribute__((cold, leaf))
void get_index(t_nb *array, const int size)
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
