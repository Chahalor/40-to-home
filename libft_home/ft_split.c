/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:17:06 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 08:17:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_home.h"

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

static void	**free_all(char **arr, unsigned int nb_elt)
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

char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	i;
	unsigned int	j;
	unsigned int	count_elt;

	result = (char **)malloc(sizeof(char *) * find_nb_split(s, c));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	count_elt = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			result[count_elt++] = strdup_from_to(s, j, i);
			if (!result[count_elt])
				return ((char **)free_all(result, count_elt));
			j = i + 1;
		}
		i++;
	}
	result[count_elt++] = strdup_from_to(s, j, i);
	return (result);
}
