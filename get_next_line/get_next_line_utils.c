/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:24:22 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/27 08:24:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	linelen(char *s, size_t max)
{
	size_t	r;

	r = 0;
	while (s[r] != '\n' && r < max)
		r++;
	if (r < max)
		return (r + 1);
	return (r);
}

t_data	*new_t_data(int fd, size_t content_size)
{
	t_data	*new_one;

	new_one = (t_data *)malloc(sizeof(t_data));
	if (!new_one)
		return (NULL);
	new_one->fd = fd;
	new_one->size = content_size;
	new_one->next = NULL;
	return (new_one);
}

size_t	get_buffer_use(t_data *data)
{
	size_t	r;
	t_data	*d;

	if (!data)
		return (0);
	d = data;
	r = 0;
	while (d)
	{
		r += d->size;
		d = d->next;
	}
	return (r);
}

void	add_end_lst(t_data **lst, t_data *elt)
{
	t_data	*l;

	if (!lst || !(*lst))
	{
		(*lst) = elt;
		return ;
	}
	l = (*lst);
	while (l->next)
		l = l->next;
	l->next = elt;
}

int	is_fd_already_read(int fd, t_data **data)
{
	t_data	*d;

	if (!data || !(*data))
		return (-1);
	d = (*data);
	if (d->fd == fd)
		return (1);
	while (d->next)
	{
		if (d->fd == fd)
			return (1);
		d = d->next;
	}
	return (0);
}