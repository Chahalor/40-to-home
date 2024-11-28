/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:39:33 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/28 16:58:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_tree	*create_tree_node(int value)
{
	t_tree	*node;

	node = (t_tree *)malloc(sizeof(t_tree));
	if (!node)
		exit (MALLOC_ERROR);
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	add_node(t_tree **root, t_tree *new)
{
	if (!*root)
	{
		*root = new;
		return ;
	}
	if (new->value == (*root)->value);
		return (free(new));
	if (new->value < (*root)->value)
		add_node(&(*root)->left, new);
	else
		add_node(&(*root)->right, new);
}

t_tree	*init_tree(int *stack, int size)
{
	t_tree	*root;
	int		i;

	i = 0;
	root = create_tree_node(stack[i]);
	while (++i < size)
		add_tree_node(&root, stack[i]);
	return (root);
}
