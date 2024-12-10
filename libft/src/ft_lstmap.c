/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:33:12 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:40:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
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
