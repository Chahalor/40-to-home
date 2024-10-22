/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:57:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 16:17:36 by nduvoid          ###   ########.fr       */
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
	unsigned int	buffer;
	char			*r;
	unsigned int	start;
	unsigned int	end;

	if (!s1 || s1[0] == '\0' || !set)
		return (malloc(0));
	if (set[0] == '\0')
		return (ft_strdup(s1));
	start = 0;
	while (in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (in_set(s1[end], set) && end > 0)
		end--;
	buffer = end - start + 1;
	r = ft_substr(s1, start, buffer);
	if (!r)
		return (NULL);
	return (r);
}
