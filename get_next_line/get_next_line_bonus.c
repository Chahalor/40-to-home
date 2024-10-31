/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:51:23 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/31 14:56:23 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_new_fd(int fd, t_fd lst_fd[MAX_FD], ssize_t buffer_use)
{
	size_t	line_len;
	ssize_t	read_size;
	char	*result;

	read_size = read(fd, lst_fd[fd].buffer, BUFFER_SIZE - buffer_use);
	if (read_size <= 0)
		return (NULL);
	line_len = linelen(lst_fd[fd].buffer, lst_fd[fd].buffer_use, read_size);
	result = gnl_substr(lst_fd[fd].buffer, 0, line_len);
	if (!result)
		return (NULL);
	lst_fd[fd].buffer_use = line_len;
	return (result);
}

static char	*read_old_fd(int fd, t_fd lst_fd[MAX_FD], ssize_t buffer_use)
{
	size_t	line_len;
	char	*result;

	line_len = linelen(lst_fd[fd].buffer, lst_fd[fd].buffer_use,
			BUFFER_SIZE - buffer_use);
	result = gnl_substr(lst_fd[fd].buffer, lst_fd[fd].buffer_use, line_len);
	if (!result)
		return (NULL);
	lst_fd[fd].buffer_use += line_len;
	return (result);
}

char	*get_next_line(int fd)
{
	static t_fd	lst_fd[MAX_FD];
	ssize_t		buffer_use;

	buffer_use = get_buffer_use(lst_fd);
	if (buffer_use >= BUFFER_SIZE)
		return (NULL);
	if (lst_fd[fd].buffer_use == 0)
		return (read_new_fd(fd, lst_fd, buffer_use));
	else
		return (read_old_fd(fd, lst_fd, buffer_use));
}
