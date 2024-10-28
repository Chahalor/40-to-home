/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:24:22 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/27 08:24:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*custom_strdup(const char *s, int index)
{
	char	*dup;
	int		i;
	int		slen;

	slen = ft_strlen(s);
	if (slen <= BUFFER_SIZE - index)
		dup = (char *)malloc(sizeof(char) * (slen + 1));
	else
		dup = (char *)malloc(sizeof(char) * (BUFFER_SIZE - index));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && i <= BUFFER_SIZE - index)
	{
		dup[i] = s[i];
		i++;
	}
	if (i <= BUFFER_SIZE - index)
		dup[i] = '\0';
	return (dup);
}
