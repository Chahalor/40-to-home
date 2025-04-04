/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:41:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 08:48:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */
	//...

/* Global */
	//...

/* Modules */
#include "list.h"

#pragma endregion	/* Includes */
#pragma region "Functions"

/**
 * @brief Allocates and returns a new element.
 * 
 * @param content The content to be added to the new element.
 * @return t_list* The new element.
 */
__attribute__((malloc)) t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node[0].content = content;
	node[0].next = NULL;
	return (node);
}

/**
 * @brief Adds the element ’new’ at the end of the list.
 * 
 * @param lst Address of a pointer to the first link of a list.
 * @param new The address of the element to be added to the list.
 * @return void
 */
__attribute__(()) void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*next;

	if (!(*lst))
	{
		(*lst) = new_node;
		return ;
	}
	if (!(*lst)->next)
	{
		(*lst)->next = new_node;
		return ;
	}
	next = (*lst)->next;
	while (next && next->next)
		next = next->next;
	next->next = new_node;
}

/**
 * @brief Adds the element ’new’ at the beginning of the list.
 * 
 * @param lst Address of a pointer to the first link of a list.
 * @param new The address of the element to be added to the list.
 * @return void
 */
__attribute__(()) void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (!lst || !new_node)
		return ;
	new_node->next = lst[0];
	lst[0] = new_node;
}

/**
 * @brief Deletes and frees the given element using the function ’del’.
 * 
 * @param lst The element to be freed.
 * @param del The address of the function used to delete the content
 * of the element.
 * @return void
 */
__attribute__(()) void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/**
 * @brief Deletes and frees the given element and every successor of that
 * element, using the function ’del’ and free(3).
 * 
 * @param lst The address of a pointer to an element.
 * @param del The address of the function used to delete the content
 * of the element.
 * @return void
 */
__attribute__(()) void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	next = (*lst);
	while (next)
	{
		tmp = next->next;
		ft_lstdelone(next, del);
		next = tmp;
	}
	ft_lstdelone(next, del);
	(*lst) = NULL;
}

#pragma endregion	/* Functions */