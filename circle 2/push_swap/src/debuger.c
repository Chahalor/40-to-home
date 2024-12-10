/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:30:55 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/05 13:21:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	int	i;

	if (!stack || !stack->stack || stack->size == 0)
		return ;
	i = 0;
	while (i < stack->size)
		ft_printf("%d ", stack->stack[i++]);
	ft_printf("\n");
}
