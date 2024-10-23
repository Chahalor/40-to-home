/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:57:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/23 14:50:50 by nduvoid          ###   ########.fr       */
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

static size_t	total_in_set(const char *s, const char *set)
{
	size_t			r;
	unsigned int	i;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (in_set(s[i], set))
			r++;
		i++;
	}
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*r;
	unsigned int	start;
	unsigned int	end;

	if (s1[0] == '\0')
		return (ft_strdup(""));
	if (total_in_set(s1, set) == ft_strlen(s1))
	{
		r = (char *)malloc(sizeof(char));
		if (!r)
			return (NULL);
		r[0] = '\0';
	}
	start = 0;
	while (in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (in_set(s1[end], set) && end > 0)
		end--;
	r = ft_substr(s1, start, end - start + 1);
	if (!r)
		return (NULL);
	return (r);
}
