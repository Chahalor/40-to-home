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

static char	*read_stdin(char buffer[BUFFER_SIZE])
{
	char	*result;
	ssize_t	readbytes;
	ssize_t	linelen;

	readbytes = read(0, buffer, BUFFER_SIZE);
	if (readbytes < 0)
		return (NULL);
	linelen = 0;
	while (linelen < readbytes && buffer[linelen] != '\n')
		linelen++;
	result = gnl_strdup(buffer, linelen + 1);
	return (result);
}

static char	*read_fd(int fd, char buffer[BUFFER_SIZE])
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
		if (readbytes < 0)
			return (NULL);
		else if (readbytes == 0)
			break ;
		c = buffer[i];
		i++;
	}
	if (i > 0)
		result = gnl_strdup(buffer, i);
	else
		result = NULL;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd == 0)
		result = read_stdin(buffer);
	else
		result = read_fd(fd, buffer);
	return (result);
}
