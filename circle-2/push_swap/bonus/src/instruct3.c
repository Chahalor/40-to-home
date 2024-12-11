/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:28:28 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 09:13:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tester.h"

/**
 * @brief swap the first two elements of stack A
 */
void	rrr(t_stack *stacks)
{
	rra(stacks);
	rrb(stacks);
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
	return (!ft_strcmp(target, SA) || !ft_strcmp(target, SB)
		|| !ft_strcmp(target, SS) || !ft_strcmp(target, PA)
		|| !ft_strcmp(target, PB) || !ft_strcmp(target, RA)
		|| !ft_strcmp(target, RB) || !ft_strcmp(target, RR)
		|| !ft_strcmp(target, RRA) || !ft_strcmp(target, RRB)
		|| !ft_strcmp(target, RRR));
}

/**
 * @brief execute the instructions
 * 
 * - the function will execute the instruction
 * 
 * - do nothing if the instruction is not valid
 * 
 * @param stacks: the two stacks and their sizes
 * @param instructs: the instruction to
 * 
 */
void	do_instructions(t_stack *stacks, char *instructs)
{
	if (!ft_strcmp(instructs, SA))
		sa(stacks);
	else if (!ft_strcmp(instructs, SB))
		sb(stacks);
	else if (!ft_strcmp(instructs, SS))
		ss(stacks);
	else if (!ft_strcmp(instructs, PA))
		pa(stacks);
	else if (!ft_strcmp(instructs, PB))
		pb(stacks);
	else if (!ft_strcmp(instructs, RA))
		ra(stacks);
	else if (!ft_strcmp(instructs, RB))
		rb(stacks);
	else if (!ft_strcmp(instructs, RR))
		rr(stacks);
	else if (!ft_strcmp(instructs, RRA))
		rra(stacks);
	else if (!ft_strcmp(instructs, RRB))
		rrb(stacks);
	else if (!ft_strcmp(instructs, RRR))
		rrr(stacks);
}
