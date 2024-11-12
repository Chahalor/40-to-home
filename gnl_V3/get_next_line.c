/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:04:20 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/12 16:02:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	get_nl_pos(char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i++);
		i++;
	}
	return (-1);
}

static char	*get_result(char **stock, char *buffer)
{
	size_t	r_size;
	char	*result;
	size_t	i;

	if (get_nl_pos(*stock) > 0)
	{
		result = gnl_strdup(*stock, get_nl_pos(*stock));
	}
}

char	*get_next_line(int fd)
{
	static char	*stock[MAX_FD] = {NULL};
	char		buffer[BUFER_SIZE + 1];
	ssize_t		rbytes;
	char		*result;

	if (fd == -1 || BUFER_SIZE <= 0)
		return (NULL);
	rbytes = read(fd, buffer, BUFER_SIZE);
	if (rbytes == -1)
		return (NULL);
	buffer[rbytes] = '\0';

}
