/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:33:12 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/23 14:51:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
