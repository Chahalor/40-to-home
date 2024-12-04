/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:42:44 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/04 12:55:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	write(1, RRR, 3);
}
