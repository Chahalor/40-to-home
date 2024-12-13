/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:26:44 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/13 10:24:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief rotate the stack a, the first element becomes the last
 * 
 * @param all: the two stacks and their sizes
 */
void	ra(t_all *all)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = all->stack_a->stack[0];
	while (++i < all->stack_a->size)
		all->stack_a->stack[i - 1] = all->stack_a->stack[i];
	all->stack_a->stack[i - 1] = tmp;
}

/**
 * @brief rotate the stack b, the first element becomes the last
 * 
 * @param all: the two stacks and their sizes
 */
void	rb(t_all *all)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = all->stack_b->stack[0];
	while (++i < all->stack_b->size)
		all->stack_b->stack[i - 1] = all->stack_b->stack[i];
	all->stack_b->stack[i - 1] = tmp;
}

/**
 * @brief rotate the stack a and b at the same time
 * 
 * @param all: the two stacks and their sizes
 */
void	rr(t_all *all)
{
	ra(all);
	rb(all);
}

/**
 * @brief reverse rotate the stack a, the last element becomes the first
 * 
 * @param all: the two stacks and their sizes
 */
void	rra(t_all *all)
{
	int	i;
	int	tmp;

	i = all->stack_a->size;
	tmp = all->stack_a->stack[i - 1];
	while (--i > 0)
		all->stack_a->stack[i] = all->stack_a->stack[i - 1];
	all->stack_a->stack[0] = tmp;
}

/**
 * @brief reverse rotate the stack b, the last element becomes the first
 * 
 * @param all: the two stacks and their sizes
 */
void	rrb(t_all *all)
{
	int	i;
	int	tmp;

	i = all->stack_b->size;
	tmp = all->stack_b->stack[i - 1];
	while (--i > 0)
		all->stack_b->stack[i] = all->stack_b->stack[i - 1];
	all->stack_b->stack[0] = tmp;
}
