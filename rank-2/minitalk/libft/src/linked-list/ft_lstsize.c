/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:27:50 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:32:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of elements in a list.
 * 
 * @param lst The beginning of the list.
 * @return int The number of elements in the list.
 */
int	ft_lstsize(t_list *lst)
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
