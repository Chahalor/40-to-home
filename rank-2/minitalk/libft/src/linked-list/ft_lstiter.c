/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:09:01 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:40:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’
 * to the content of each element.
 * 
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 * @return void
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
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
