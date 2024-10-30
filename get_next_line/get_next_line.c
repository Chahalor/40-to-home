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
#include <unistd.h>

char	*get_next_line(int fd)
{
	static void	*lst_fd[LST_FD_SZ];
	int			b_use;
	char		buffer[BUFFER_SIZE];
	ssize_t		rout;
	char		*result;

	if (lst_fd[1024] == NULL)
	{
		b_use = 0;
		lst_fd[1024] = &b_use;
	}
	else 
		b_use = (int)(*lst_fd)[1024];
	if (lst_fd[fd] == NULL)
	{
		rout = read(fd, buffer, BUFFER_SIZE - b_use);
		if (rout == -1)
			return (NULL);
		result = gnl_strdup(buffer, linelen(buffer, rout));
		lst_fd[fd] = &buffer[linelen(buffer, rout)];
		lst_fd[1024] += linelen(lst_fd[fd], BUFFER_SIZE - b_use);
		return (result);
	}
	printf("linelen=%d\n", BUFFER_SIZE - b_use);
	result = gnl_strdup(lst_fd[fd], linelen(lst_fd[fd], BUFFER_SIZE - b_use));
	lst_fd[fd] = &lst_fd[fd][linelen(lst_fd[fd], BUFFER_SIZE - b_use)];
	lst_fd[1024] += linelen(lst_fd[fd], BUFFER_SIZE - b_use);
	return (result);
}
