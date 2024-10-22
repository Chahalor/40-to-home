/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:27:50 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/22 09:46:01 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
