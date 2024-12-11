/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:21:06 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 11:57:13 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// renvoie les nbr dans l ordre du nb signi (le plus grans en premier et les push en bas de A)
/**	tant que all.stack_b.size > 0
 * 		get poss max
 * 		rb() ou rrb() en fonction du plus opti jusqu a que stack_b.head == max
 * 		pa()
 * 		ra()
*/
void	sort_stack(t_all *all)
{
	int	max;
	int	max_poss
}

void	radix(t_all *all)
{
	int	expo;
	int	max;
	int	signi;
	int	i;
	int	j;
	int	max_poss;

	max = get_max(all->stack_a);
	expo = get_expo(max);

	while (expo > 0)
	{
		signi = 0;
		while (signi < 10)
		{
			i = 0;
			while (i < all->stack_a->size)	//passe les nbr dont le le nb signi est i de A a B
			{
				if (all->stack_a->stack[0] % signi == i)
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
			j = 0;

			while (j < all->stack_b->size)
			{
				max_poss = 0;
				
			}
			signi++;
		}
		expo /= 10;
	}
}
