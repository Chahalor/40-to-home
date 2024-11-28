/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:23:51 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/28 13:15:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*create_node(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	add_end_nodes(t_list **stack, t_list *new)
{
	t_list	*tmp;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp->content);
		free(tmp);
	}
}

t_bool	is_in_stack(t_list *stack, void *content)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->content == content)
			return (true);
		stack = stack->next;
	}
	return (false);
}

t_list	*init_stack(int argc, const char **argv)
{
	t_list	*stack;
	int		atoied;
	int		i;
	int		*content;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		atoied = ft_atoi(argv[i]);
		if (atoied == 0 && *argv[i] != '0')
			return (free_stack(&stack), NULL);
		else if (is_in_stack(stack, &atoied))
			return (free_stack(&stack), NULL);
		content = (int *)malloc(sizeof(int));
		if (!content)
			return (free_stack(&stack), NULL);
		*content = atoied;
		add_end_nodes(&stack, create_node(content));
		i++;
	}
	return (stack);
}
