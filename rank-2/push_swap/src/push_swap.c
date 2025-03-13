/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:11:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/13 13:40:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "parsing.h"

/** */
t_stack	*get_stack(const t_choose choose)
{
	static t_stack *stacks[2];
	t_stack	*stack;

	stack = stacks[choose];
	if (stack == NULL)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (stack == NULL)
			return (NULL);
		stacks[choose] = stack;
	}
	return (stack);
}

/** */
int	main(int argc, const char *argv[])
{
	const t_args	args = parse_args(argc, argv);
	int		(*const algo)(t_stack *(*const get_stack)))[NB_ALGO] = {
		turkish_algo, random_algo, miracle_algo};
	t_stack			*stack_a;
	t_stack			*stack_b;

	if (args.error)
		exiting(args.error, "Error: invalid argument");
	return (algo[args.algo](get_stack));
}
