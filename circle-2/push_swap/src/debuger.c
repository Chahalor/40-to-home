/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:30:55 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 14:51:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d", stack->stack[i]);
		if (i + 1 < stack->size)
			ft_printf(", ");
		i++;
	}
}

void	print_all(t_all *all)
{
	ft_printf("All\n");
	ft_printf("├─Stack A:\n");
	ft_printf("│ ├─size: %d\n", all->stack_a->size);
	ft_printf("│ └─[");
	print_stack(all->stack_a);
	ft_printf("]\n");
	ft_printf("└─Stack B\n");
	ft_printf("  ├─size: %d\n", all->stack_a->size);
	ft_printf("  └─[");
	print_stack(all->stack_b);
	ft_printf("]\n");
}
