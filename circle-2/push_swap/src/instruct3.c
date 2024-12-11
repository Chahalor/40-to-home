/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:28:28 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 11:25:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief swap the first two elements of stack A
 */
void	rrr(t_all *all)
{
	rra(all);
	rrb(all);
}

/**
 * @brief check if the target is an instruction
 * 
 * @example is_instruction("sa\n") => TRUE
 * @example is_instruction("sa") => FALSE
 * 
 * @param target: the target to check
 * @return
 * 
 * - TRUE if the target is an instruction
 * 
 * - FALSE if the target is not an instruction
 */
t_bool	is_instruction(char *target)
{
	return (!ft_strncmp(target, SA, 3) || !ft_strncmp(target, SB, 3)
		|| !ft_strncmp(target, SS, 3) || !ft_strncmp(target, PA, 3)
		|| !ft_strncmp(target, PB, 3) || !ft_strncmp(target, RA, 3)
		|| !ft_strncmp(target, RB, 3) || !ft_strncmp(target, RR, 3)
		|| !ft_strncmp(target, RRA, 4) || !ft_strncmp(target, RRB, 4)
		|| !ft_strncmp(target, RRR, 4));
}

/**
 * @brief execute the instructions
 * 
 * - the function will execute the instruction
 * 
 * - do nothing if the instruction is not valid
 * 
 * @param all: the two stacks and their sizes
 * @param instructs: the instruction to
 * 
 */
void	do_instructions(t_all *all, char *instructs)
{
	if (!ft_strncmp(instructs, SA, 3))
		sa(all);
	else if (!ft_strncmp(instructs, SB, 3))
		sb(all);
	else if (!ft_strncmp(instructs, SS, 3))
		ss(all);
	else if (!ft_strncmp(instructs, PA, 3))
		pa(all);
	else if (!ft_strncmp(instructs, PB, 3))
		pb(all);
	else if (!ft_strncmp(instructs, RA, 3))
		ra(all);
	else if (!ft_strncmp(instructs, RB, 3))
		rb(all);
	else if (!ft_strncmp(instructs, RR, 3))
		rr(all);
	else if (!ft_strncmp(instructs, RRA, 4))
		rra(all);
	else if (!ft_strncmp(instructs, RRB, 4))
		rrb(all);
	else if (!ft_strncmp(instructs, RRR, 4))
		rrr(all);
}
