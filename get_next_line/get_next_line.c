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

char	*read_fd(int fd, char buffer[BUFFER_SIZE])
{
	char	*result;
	char	c;
	ssize_t	readbytes;
	ssize_t	i;

	i = 0;
	c = '\0';
	while (c != '\n' && i < BUFFER_SIZE)
	{
		readbytes = read(fd, buffer + i, 1);
		c = buffer[i];
		if (readbytes < 0)
			return (NULL);
		i++;
	}
	result = gnl_strdup(buffer, i);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_fd(fd, buffer[fd]));
}

