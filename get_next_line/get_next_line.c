/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:24:03 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/27 08:24:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*rd_until_nxt_line(int fd, size_t buffer_use)
{
	int			rout;
	char		rbuffer[BUFFER_SIZE];
	char		*result;
	size_t		i;
	size_t		j;

	rout = read(fd, rbuffer, BUFFER_SIZE - buffer_use);
	if (rout == -1)
		return (NULL);
	i = 0;
	while (i < linelen(rbuffer, rout) && BUFFER_SIZE >= buffer_use + i)
		i++;
	if (BUFFER_SIZE >= buffer_use + i)
		i++;
	result = (char *)malloc(sizeof(char) * i);
	if (!result)
		return (NULL);
	j = 0;
	while (i < j)
	{
		result[j] = rbuffer[j];
		j++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static t_data	*data = NULL;
	size_t			buffer_use;
	char			*rbuffer;
	t_data			*tmp;

	if (!data)
		data = new_t_data(fd, linelen(rd_until_nxt_line(fd, 0), BUFFER_SIZE));
	buffer_use = get_buffer_use(data);
	if (!is_fd_already_read(fd, &data))
	{
		rbuffer = rd_until_nxt_line(fd, buffer_use);
		if (!rbuffer)
			return (NULL);
		add_end_lst(&data, new_t_data(fd, linelen(rbuffer, BUFFER_SIZE)));
		buffer_use += linelen(rbuffer, BUFFER_SIZE);
		return (rbuffer);
	}
	tmp = data;
	while (tmp->fd != fd)
		tmp = tmp->next;
	rbuffer = rd_until_nxt_line(fd, buffer_use);
	if (!rbuffer)
		return (NULL);
	tmp->size += linelen(rbuffer, BUFFER_SIZE);
	return (rbuffer);
}
