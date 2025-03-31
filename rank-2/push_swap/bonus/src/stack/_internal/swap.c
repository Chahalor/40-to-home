/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:35:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 10:21:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stack.h"

/**
 * 
*/
__attribute__((hot, leaf))
void	swap(t_stack **stackp)
{
	register t_nb	tmp;

	if (!stackp || !*stackp || (*stackp)->size < 2)
		return ;
	tmp = (*stackp)->array[0];
	(*stackp)->array[0] = (*stackp)->array[1];
	(*stackp)->array[1] = tmp;
}

/** */
__attribute__((hot))
void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
