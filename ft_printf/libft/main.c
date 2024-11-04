/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:04:23 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/22 15:41:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	del(void *s)
{
	free(s);
}

void	*f(void *s)
{
	return (ft_strdup((char *)s));
}

int	main(void)
{
	t_list	*list = ft_lstnew(ft_strdup("seconde"));
	t_list *next = NULL;

	ft_lstadd_front(&list, ft_lstnew(ft_strdup("first")));
	int i = 0;
	while (i < 10)
	{
		ft_lstadd_back(&list, ft_lstnew(ft_itoa(i)));
		i++;
	}
	// ft_lstiter(list, f);
	t_list	*new_list = ft_lstmap(list, f, del);
	next = new_list;
	while (next)
	{
		if (next->content)
			ft_putstr_fd(next->content, 1);
		else
			ft_putstr_fd("no content", 1);
		write(1, "\n", 1);
		next = next->next;
	}
	ft_lstclear(&list, del);
	ft_lstclear(&new_list, del);
	return (0);
}
