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

static char	*quit_all(char *content, int fd)
{
	free(content);
	close(fd);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*content;
	char			*result;
	unsigned int	i;
	int				rout;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	content = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!content)
		return (NULL);
	rout = read(fd, content, BUFFER_SIZE);
	if (rout == -1)
		return (quit_all(content, fd));
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			break ;
		else if (content[i] == '\\' && content[i + 1] == 'n')
			break ;
		i++;
	}
	result = custom_strdup(content, i);
	quit_all(content, fd);
	return (result);
}
