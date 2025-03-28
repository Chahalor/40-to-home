/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:39:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/21 14:00:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/** Rotate la stack vers le haut */
__attribute__((hot, leaf))
void rotate(t_stack **stackp)
{
	if (!stackp || !*stackp || (*stackp)->size < 2)
		return;

	t_nb tmp = (*stackp)->array[0];
	ft_memmove(&(*stackp)->array[0], &(*stackp)->array[1], ((*stackp)->size - 1) * sizeof(t_nb));
	(*stackp)->array[(*stackp)->size - 1] = tmp;
}

/** Rotate la stack vers le bas */
__attribute__((hot, leaf))
void reverse_rotate(t_stack **stackp)
{
	if (!stackp || !*stackp || (*stackp)->size < 2)
		return;

	t_nb tmp = (*stackp)->array[(*stackp)->size - 1];
	ft_memmove(&(*stackp)->array[1], &(*stackp)->array[0], ((*stackp)->size - 1) * sizeof(t_nb));
	(*stackp)->array[0] = tmp;
}

/** */
__attribute__((hot))
void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

/** */
__attribute__((hot))
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
