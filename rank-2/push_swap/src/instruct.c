/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:08:04 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/09 11:08:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief swap the first two elements of stack A
 * 
 * @param all: the two stacks and their sizes
 */
void	sa(t_all *all)
{
	int	tmp;

	if (all->stack_a->size < 2)
		return ;
	tmp = all->stack_a->stack[0];
	all->stack_a->stack[0] = all->stack_a->stack[1];
	all->stack_a->stack[1] = tmp;
}

/**
 * @brief swap the first two elements of stack B
 * 
 * @param all: the two stacks and their sizes
 */
void	sb(t_all *all)
{
	int	tmp;

	if (all->stack_b->size < 2)
		return ;
	tmp = all->stack_b->stack[0];
	all->stack_b->stack[0] = all->stack_b->stack[1];
	all->stack_b->stack[1] = tmp;
}

/**
 * @brief swap the first two elements of stack A and B
 * 
 * @param all: the two stacks and their sizes
 */
void	ss(t_all *all)
{
	sa(all);
	sb(all);
}

/**
 * @brief push the first element of stack A to stack B
 * 
 * @param all: the two stacks and their sizes
 */
void	pa(t_all *all)
{
	int	i;

	if (all->stack_b->size == 0)
		return ;
	i = all->stack_a->size;
	while (i > 0)
	{
		all->stack_a->stack[i] = all->stack_a->stack[i - 1];
		i--;
	}
	all->stack_a->stack[0] = all->stack_b->stack[0];
	i = 0;
	while (i < all->stack_b->size - 1)
	{
		all->stack_b->stack[i] = all->stack_b->stack[i + 1];
		i++;
	}
	all->stack_a->size++;
	all->stack_b->size--;
}

/**
 * @brief push the first element of stack B to stack A
 * 
 * @param all: the two stacks and their sizes
 */
void	pb(t_all *all)
{
	int	i;

	if (all->stack_a->size == 0)
		return ;
	i = all->stack_b->size;
	while (i > 0)
	{
		all->stack_b->stack[i] = all->stack_b->stack[i - 1];
		i--;
	}
	all->stack_b->stack[0] = all->stack_a->stack[0];
	i = 0;
	while (i < all->stack_a->size - 1)
	{
		all->stack_a->stack[i] = all->stack_a->stack[i + 1];
		i++;
	}
	all->stack_b->size++;
	all->stack_a->size--;
}
