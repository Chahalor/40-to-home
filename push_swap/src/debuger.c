/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:30:55 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/28 12:32:26 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

void	print_stack(t_list *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		ft_printf("%d, ", *(int *)stack->content);
		stack = stack->next;
	}
	printf("\n");
}