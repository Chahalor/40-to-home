/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:02:17 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/05 15:47:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_fd(int fd, char buffer[BUFFER_SIZE])
{
	char	tmp[BUFFER_SIZE];
	char	*result;
	ssize_t	rbytes;
	int		buffer_size;

	ft_strlcpy(tmp, buffer, BUFFER_SIZE);
	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes < 0)
		return (NULL);
	buffer_size = min(ft_strlen(tmp) + rbytes, BUFFER_SIZE) + 1;
	result = (char *)malloc(sizeof(char) * buffer_size);
	if (!result)
		return (NULL);
	ft_strlcpy(result, tmp, ft_strlen(tmp));
	ft_strlcat(result, buffer, buffer_size - ft_strlen(tmp));
	if (buffer_size == BUFFER_SIZE)
		return (result);
	buffer[rbytes] = \0
	buffer = &buffer[buffer_size - ft_strlen(tmp)]
	
}



char	*get_next_line(int fd)
{
	static char	lst_fd[MAX_FD][BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	
}

