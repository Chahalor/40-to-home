/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:21:06 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/12 10:28:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief push push every number of the stack A to B if the number % expo == i
 */
void	push_signi_to_b(t_all *all, int signi, int mod)
{
	int	i;
	int	nb_iter;

	i = 1;
	nb_iter = all->stack_a->size;
	while (i < nb_iter)
	{
		if (all->stack_a->stack[0] > signi && all->stack_a->stack[0]/signi == mod)
		{
			write(1, PB, 3);
			pb(all);
		}
		else
		{
			write(1, RA, 3);
			ra(all);
		}
		i++;
	}
}

/**
 * @brief sort the stack B by shearching the min and pushing it to A and 
 * rotating the stack A to push the min to the bottom of A
 */
void	sort_stack_b(t_all *all)
{
	int	min;
	int	min_pos;

	while (all->stack_b->size > 0)
	{
		min = get_min(all->stack_b);
		min_pos = get_poss(all->stack_b, min);
		if (min_pos == -1)
			return ;
		if (min_pos > all->stack_b->size / 2)
		{
			while (all->stack_b->stack[0] != min)
			{
				write(1, RRB, 4);
				rrb(all);
			}
		}
		else
		{
			while (all->stack_b->stack[0] != min)
			{
				write(1, RB, 3);
				rb(all);
			}
		}
		write(1, PA, 3);
		pa(all);
		write(1, RRA, 4);
		rra(all);
	}
}

void	radix(t_all *all)
{
	int	expo;
	int	expo_max;
	int	i;

	expo_max = get_expo(get_max(all->stack_a));
	expo = 1;
	while (expo < expo_max)
	{
		i = 1;
		while (i < 10 && !(is_sorted(all->stack_a) && all->stack_b->size == 0))
		{
			push_signi_to_b(all, expo, i);
			sort_stack_b(all);
			i++;
		}
		expo *= 10;
		// print_all(all);
	}
}
