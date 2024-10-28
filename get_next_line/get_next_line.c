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
	static int	buffer;
	int			i;

	buffer = 0;
}
