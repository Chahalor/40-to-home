/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:17:06 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 08:49:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	find_nb_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	r;

	i = 0;
	r = 0;
	while (s[i])
		if (s[i++] == c)
			r++;
	return (r);
}

static char	*strdup_from_to(const char *s, unsigned int from, unsigned int to)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	if (from == to)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (to - from + 1));
	if (!result)
		return (NULL);
	i = from;
	j = 0;
	while (i < to)
	{
		result[j] = s[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

static char	**free_all(char **arr, unsigned int nb_elt)
{
	unsigned int	i;

	i = 0;
	while (i < nb_elt)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**malloc_logic(char **dest, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*data;

	i = 0;
	j = 0;
	k = 0;
	while (i < ft_strlen(s))
	{
		if (s[i++] == c)
		{
			data = strdup_from_to(s, j, i - 1);
			if (!data)
				return (free_all(dest, k));
			dest[k++] = data;
			j = i;
		}
	}
	dest[k] = strdup_from_to(s, j, i);
	dest[k + 1] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (find_nb_split(s, c) + 2));
	if (!result)
		return (NULL);
	return (malloc_logic(result, s, c));
}
