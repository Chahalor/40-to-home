/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:04:20 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/13 13:51:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*update_stock(char **s, char *buffer, size_t s_strt, size_t b_strt)
{
	size_t	size;
	char	*result;
	size_t	i;
	size_t	j;

	size = ft_strlen(*s) - s_strt + ft_strlen(buffer) - b_strt;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s && i < ft_strlen(*s) - s_strt)
	{
		result[i] = (*s)[i + s_strt];
		i++;
	}
	j = 0;
	while (buffer && j < ft_strlen(buffer) - b_strt)
		result[i++] = buffer[b_strt + j++];
	result[i] = '\0';
	free(*s);
	return (result);
}

static char	*get_line(char **s, char *buffer)
{
	char	tmp[BUFFER_SIZE + 1];
	size_t	s_size;
	size_t	b_size;
	char	*result;

	s_size = 0;
	b_size = 0;
	if (*s)
	{
		while ((*s)[s_size] && s_size < BUFFER_SIZE)
		{
			tmp[s_size] = (*s)[s_size];
			s_size++;
			if (tmp[s_size - 1] == '\n')
				break ;
		}
		if (tmp[s_size - 1] == '\n')
		{
			tmp[s_size] = '\0';
			result = gnl_strdup(tmp, s_size);
			*s = update_stock(s, buffer, s_size, b_size);
			return (result);
		}
	}
	while (buffer[b_size] && b_size + s_size + 1 < BUFFER_SIZE)
	{
		tmp[b_size + s_size] = buffer[b_size];
		b_size++;
		if (tmp[b_size - 1 + b_size] == '\n')
			break ;
	}
	tmp[b_size + s_size] = '\0';
	result = gnl_strdup(tmp, s_size + b_size);
	*s = update_stock(s, buffer, s_size, b_size);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stock[MAX_FD] = {NULL};
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		rbytes;
	char		*result;

	if (fd == -1 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes == -1)
		return (NULL);
	buffer[rbytes] = '\0';
	result = get_line(&stock[fd], buffer);
	return (result);
}
