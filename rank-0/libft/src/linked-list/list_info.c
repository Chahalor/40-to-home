/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:44:26 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 10:16:38 by nduvoid          ###   ########.fr       */
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
 * @brief Returns the last element of the list.
 * 
 * @param lst The beginning of the list.
 * @return t_list* The last element of the list.
 */
__attribute__((malloc)) t_list	*ft_lstlast(const t_list *const lst)
{
	t_list	*next;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return ((t_list *)lst);
	next = lst->next;
	while (next->next)
		next = next->next;
	return (next);
}

/**
 * @brief Counts the number of elements in a list.
 * 
 * @param lst The beginning of the list.
 * @return int The number of elements in the list.
 */
__attribute__((leaf)) int	ft_lstsize(const t_list *const lst)
{
	int		size;
	t_list	*next;

	if (!lst)
		return (0);
	size = 1;
	next = lst->next;
	while (next)
	{
		size++;
		next = next->next;
	}
	return (size);
}

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’
 * to the content of each element.
 * 
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete
 * the content of the element.
 * @return t_list* The new list.
 */
__attribute__((malloc)) t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*new;
	t_list	*next;
	t_list	*nnext;

	if (!lst || !f || !del)
		return (NULL);
	next = lst;
	new = ft_lstnew(f(next->content));
	if (!new)
		return (NULL);
	nnext = new;
	while (next->next)
	{
		next = next->next;
		nnext->next = ft_lstnew(f(next->content));
		if (!nnext->content)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		nnext = nnext->next;
	}
	return (new);
}

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’
 * to the content of each element.
 * 
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 * @return void
 */
__attribute__((leaf)) void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next;

	if (!lst || !f)
		return ;
	next = lst;
	while (next)
	{
		(f)(next->content);
		next = next->next;
	}
}

#pragma endregion	/* Functions */