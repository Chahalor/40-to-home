/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:17 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/08 17:21:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join(char *buffer, char **stock, size_t rbytes, size_t *stock_size)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *)malloc(sizeof(char) * (rbytes + *stock_size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < *stock_size && *stock != NULL)
	{
		result[i] = (*stock)[i];
		i++;
	}
	j = 0;
	while (j < rbytes)
		result[i++] = buffer[j++];
	result[i] = '\0';
	*stock_size = *stock_size + rbytes;
	free(*stock);
	return (result);
}

static char	*get_line(char **stock, size_t *stock_size, size_t rbytes)
{
	size_t	len_line;
	char	*result;
	size_t	i;

	len_line = 0;
	while (len_line < *stock_size && (*stock)[len_line] != '\n')
		len_line++;
	if ((*stock)[len_line] != '\n' && rbytes == BUFFER_SIZE && BUFFER_SIZE != 1)
		return (NULL);
	else
		len_line++;
	result = (char *)malloc(sizeof(char) * (len_line + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len_line)
		result[i] = (*stock)[i];
	result[i++] = '\0';
	*stock = gnl_stockdup(stock, len_line, *stock_size);
	*stock_size -= len_line;
	return (result);
}

char	*get_next_line(int fd)
{
	static char		*stock[MAX_FD] = {NULL};
	static size_t	stock_size = 0;
	char			buffer[BUFFER_SIZE];
	ssize_t			rbytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes == -1)
		return (NULL);
	if (rbytes == 0 && stock[fd] == NULL)
		return (NULL);
	if (rbytes > 0)
		stock[fd] = join(buffer, &stock[fd], rbytes, &stock_size);
	if (stock[fd] == NULL)
		return (NULL);
	return (get_line(&stock[fd], &stock_size, rbytes));
}
