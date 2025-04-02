/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:39:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 13:27:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/_stack.h"

/** Rotate la stack vers le haut */
__attribute__((hot))
int	rotate(t_stack **stackp)
{
	t_nb	tmp;

	if (!stackp || !*stackp || (*stackp)->size < 2)
		return (0);
	tmp = (*stackp)->array[0];
	ft_memmove(&(*stackp)->array[0], &(*stackp)->array[1], ((*stackp)->size - 1) * sizeof(t_nb));
	(*stackp)->array[(*stackp)->size - 1] = tmp;
	return (1);
}

/** Rotate la stack vers le bas */
__attribute__((hot))
int	reverse_rotate(t_stack **stackp)
{
	t_nb	tmp;

	if (!stackp || !*stackp || (*stackp)->size < 2)
		return (0);
	tmp = (*stackp)->array[(*stackp)->size - 1];
	ft_memmove(&(*stackp)->array[1], &(*stackp)->array[0], ((*stackp)->size - 1) * sizeof(t_nb));
	(*stackp)->array[0] = tmp;
	return (1);
}

/** */
__attribute__((hot))
int	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	return (rotate(stack_a) || rotate(stack_b));
}

/** */
__attribute__((hot))
int	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	return (reverse_rotate(stack_a) || reverse_rotate(stack_b));
}
