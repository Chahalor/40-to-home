/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:47:39 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:32:00 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last element of the list.
 * 
 * @param lst The beginning of the list.
 * @return t_list* The last element of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*next;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	next = lst->next;
	while (next->next)
		next = next->next;
	return (next);
}
