/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:50:55 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/30 10:50:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	ft_strjoin(char *s1, char *s2)
// {

// }

char	*gnl_strdup(char *src, ssize_t max)
{
	char	*dest;
	ssize_t	buffer;
	
	buffer = 0;
	while (src[buffer] && buffer < max)
		buffer++;
	dest = (char *)malloc(sizeof(char) * (buffer + 1));
	if (!dest)
		return (NULL);
	while (buffer >= 0)
	{
		dest[buffer] = src[buffer];
		buffer--;
	}
	return (dest);
}
