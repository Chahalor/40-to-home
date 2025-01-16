/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:21:22 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:40:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given element and every successor of that
 * element, using the function ’del’ and free(3).
 * 
 * @param lst The address of a pointer to an element.
 * @param del The address of the function used to delete the content
 * of the element.
 * @return void
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
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
