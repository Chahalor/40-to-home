/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:57:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/18 16:49:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	unsigned int	i;
	unsigned int	slen;

	slen = ft_strlen(set);
	i = 0;
	while (i < slen)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	buffer;
	char			*r;
	unsigned int	start;
	unsigned int	end;

	if (s1[0] == '\0')
		return ("");
	i = 0;
	while (in_set(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (in_set(s1[i], set) && i > 0)
		i--;
	end = i;
	buffer = end - start + 1;
	if (buffer == 1)
		return ("");
	r = ft_substr(s1, start, buffer);
	if (!r)
		return (NULL);
	return (r);
}
