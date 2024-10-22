/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:03:22 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/22 13:30:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*next;

	if (!lst || !new)
		return ;
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
