/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:28:28 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/10 15:03:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tester.h"

void	rrr(t_stack *stacks)
{
	rra(stacks);
	rrb(stacks);
}

t_bool	is_instruction(char *target)
{
	return (!ft_strcmp(target, SA) || !ft_strcmp(target, SB)
		|| !ft_strcmp(target, SS) || !ft_strcmp(target, PA)
		|| !ft_strcmp(target, PB) || !ft_strcmp(target, RA)
		|| !ft_strcmp(target, RB) || !ft_strcmp(target, RR)
		|| !ft_strcmp(target, RRA) || !ft_strcmp(target, RRB)
		|| !ft_strcmp(target, RRR));
}

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
