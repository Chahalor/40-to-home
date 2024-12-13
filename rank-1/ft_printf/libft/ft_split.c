/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:51:43 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/23 13:47:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tab(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

static size_t	get_buffer(const char *s, char c)
{
	size_t	nb;
	size_t	i;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

static void	fill_tab(char *dest, const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

static void	alloc_tab(char **r, const char *s, char c)
{
	size_t	count;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		count = 0;
		while (s[i + count] && s[i + count] != c)
			count++;
		if (count > 0)
		{
			r[j] = malloc(sizeof(char) * (count + 1));
			if (!r[j])
				return (free_tab(r, j));
			fill_tab(r[j], (s + i), c);
			j++;
			i = i + count;
		}
		else
			i++;
	}
	r[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_tab;
	char	**r;

	nb_tab = get_buffer(s, c);
	r = (char **)malloc(sizeof(char *) * (nb_tab + 1));
	if (!r)
		return (NULL);
	alloc_tab(r, s, c);
	if (!r)
		return (NULL);
	return (r);
}
