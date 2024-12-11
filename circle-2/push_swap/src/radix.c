/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:21:06 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 15:27:52 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief push push every number of the stack A to B if the number % expo == i
 */
void	push_signi_to_b(t_all *all, int expo)
{
	int	i;

	i = 0;
	//passe les nbr dont le le nb expo est i de A a B
	while (i < all->stack_a->size)
	{
		if (all->stack_a->stack[0]/expo % 10 == i)
		{
			// write(1, PB, 3);
			pb(all);
		}
		else 
		{
			// write(1, RA, 3);
			ra(all);
		}
		i++;
	}
}

/**
 * @brief sort the stack B by shearching the max and pushing it to A and 
 * rotating the stack A to push the max to the bottom of A
 */
void	sort_stack_b(t_all *all)
{
	int	max;
	int	max_poss;

	while (all->stack_b->size > 0)
	{
		max = get_max(all->stack_b);
		max_poss = get_poss(all->stack_b, max);
		if (max_poss == -1)
			return ;
		if (max_poss > all->stack_b->size / 2)
		{
			while (all->stack_b->stack[0] != max)
			{
				// write(1, RRB, 4);
				rrb(all);
			}
		}
		else
		{
			while (all->stack_b->stack[0] != max)
			{
				// write(1, RB, 3);
				rb(all);
			}
		}
		// write(1, PA, 3);
		pa(all);
		if (all->stack_b->size > 1)
		{
			// write(1, RA, 3);
			ra(all);
		}
	}
}

void	radix(t_all *all)
{
	int	expo;
	int	i;

	expo = get_expo(get_max(all->stack_a));
	while (expo > 0)
	{
		i = 1;
		while (i < 10)
		{
			push_signi_to_b(all, i);
			sort_stack_b(all);
			i++;
		}
		expo /= 10;
		print_all(all);
	}
}
