/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:21:06 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/13 11:45:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief push evry numbre of stack A into B that are equal to signi * mod
 * 
 * @param all	 the structure that contain the two stacks
 * @param signi	 the number that will be used to sort the stack (signi != 0)
 * @param mod	 the number that will be used to sort the stack
 * 
 * @note signi should not be equal to 0
 */
void	push_signi_to_b(t_all *all, int signi, int mod)
{
	int	i;
	int	nb_iter;
	int	nb_to_push;

	nb_iter = 0;
	nb_to_push = 0;
	while (nb_iter < all->stack_a->size)
		if (all->stack_a->stack[nb_iter++]/signi == mod)
			nb_to_push++;
	i = 1;
	while (i < nb_iter && nb_to_push > 0)
	{
		if (all->stack_a->stack[0] > signi && all->stack_a->stack[0]/signi == mod)
		{
			write(1, PB, 3);
			pb(all);
			nb_to_push--;
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
 * 
 * @param all the structure that contain the two stacks
 */
void	sort_stack_b(t_all *all)
{
	int	min;
	int	min_pos;

	while (all->stack_b->size > 0)
	{
		min = get_min(all->stack_b);
		min_pos = get_poss(all->stack_b, min);
		if (min_pos < 0)
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
		ra(all);
	}
}

#if RADIX == 0
/** @todo */
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
		while (i < 10 /*&& !(is_sorted(all->stack_a) && all->stack_b->size == 0)*/)
		{
			push_signi_to_b(all, expo, i);
			sort_stack_b(all);
			i++;
		}
		expo *= 10;
	}
}

#else
/** @todo */
void	radix(t_all *all)
{
	int	expo;
	int	i;

	expo = get_expo(get_max(all->stack_a));
	while (expo > 0)
	{
		i = 1;
		while (i < 10 /*&& !(is_sorted(all->stack_a) && all->stack_b->size == 0)*/)
		{
			push_signi_to_b(all, expo, i);
			sort_stack_b(all);
			i++;
		}
		expo /= 10;
	}
}

#endif