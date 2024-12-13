/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:03:22 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:30:26 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the element ’new’ at the end of the list.
 * 
 * @param lst Address of a pointer to the first link of a list.
 * @param new The address of the element to be added to the list.
 * @return void
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*next;

	if (!(*lst))
	{
		(*lst) = new;
		return ;
	}
	if (!(*lst)->next)
	{
		(*lst)->next = new;
		return ;
	}
	next = (*lst)->next;
	while (next && next->next)
		next = next->next;
	next->next = new;
}
