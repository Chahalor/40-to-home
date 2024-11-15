/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:35:20 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/15 14:12:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*join(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 + len_s2 == 0)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	gnl_strcpy(result, s1, 0);
	gnl_strcpy(&result[len_s1], s2, 0);
	free(s1);
	s1 = NULL;
	return (result);
}

static char	*final(char *result, char *buffer, size_t buffer_size)
{
	char	*tmp;

	tmp = gnl_strdup(buffer, buffer_size + 1);
	result = join(result, tmp);
	free(tmp);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	stock[MAX_FD][BUFFER_SIZE];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		rbytes;
	char		*result;

	if (fd == -1 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes == -1)
		return (NULL);
	buffer[rbytes] = '\0';
	result = NULL;
	while (line_len(buffer) == BUFFER_SIZE && rbytes == BUFFER_SIZE)
	{
		result = join(result, buffer);
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes == -1)
			return (NULL);
		buffer[rbytes] = '\0';
	}
	result = final(result, buffer, line_len(buffer));
	gnl_strcpy(stock[fd], buffer, line_len(buffer) - 1);
	printf("buff : %s\n", buffer);
	return (result);
}
