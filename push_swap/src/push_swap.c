/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:09:04 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/28 16:55:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*init_stack(int argc, char **argv)
{
	int	atoied;
	int	i;
	int	*stack;

	stack = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		atoied = ft_atoi(argv[i]);
		if (atoied == 0 && *argv[i] != '0')
			return (free(stack), NULL);
		stack[i] = atoied;
	}
	return (stack);
}

void	sort_stack(t_list *stack_a, t_list *stack_b, int argc)
{
	t_tree	*tree;

	tree = init_tree(stack_a, argc - 1);
}

/**
 * @todo everything
 */
int	main(int argc, const char **argv)
{
	int	*statck_a;
	int	*statck_b;

	statck_a = init_stack(argc, argv);
	statck_b = ft_calloc(sizeof(int), argc - 1);
	if (!statck_a || !statck_b)
	{
		ft_printf("Error\n");
		return (free(statck_a), free(statck_b), INVALIDE_STACK);
	}
	sort_stack(statck_a, statck_b, argc);
	free_stack(&statck_a);
	free_stack(&statck_b);
	return (SUCCESS);
}
