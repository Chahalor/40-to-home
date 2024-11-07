/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:17 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/07 15:20:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	new_stock(char *stock, int size)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = stock[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*read_new_fd(int fd, char *stock, char buffer[BUFFER_SIZE])
{
	ssize_t	rbytes;
	char	*result;
	ssize_t	next_nl;

	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes <= 0)
		return (NULL);
	if (rbytes < BUFFER_SIZE)
		return (gnl_strdup(buffer, rbytes));
	next_nl = get_nl_pos(buffer);
	if (next_nl != -1)
	{
		stock = gnl_strdup(&buffer[next_nl + 1], rbytes);
		return (gnl_strdup(buffer, next_nl));
	}
	stock = gnl_strdup(buffer, rbytes);
	return (NULL);
}

static char	*read_old_fd(int fd, char *stock, char buffer[BUFFER_SIZE])
{
	char	*result;
	char	tmp[BUFFER_SIZE];
	ssize_t	next_nl;

	next_nl = get_nl_pos(buffer);
	if (next_nl != -1)
	{
		gnl_strcpy(stock, tmp, get_stock_size(stock));
		free(stock);
		stock = gnl_strdup(tmp[next_nl], BUFFER_SIZE);
		return (gnl_strdup(tmp, next_nl));
	}
	
}

char	*get_next_line(int fd)
{
	static char	*stock[MAX_FD];
	char		buffer[BUFFER_SIZE];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (stock[fd] == NULL)
		return (read_new_fd(fd, stock[fd], buffer));
	return (read_old_fd(fd, stock[fd], buffer));
}

