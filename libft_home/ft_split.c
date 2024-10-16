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

#include <stdlib.h>

unsigned int	ft_strlen(const char s);
void 			*ft_calloc(size_t nmemb, size_t size);

typedef struct	t_split_piece
{
	unsigned int	size;
	char			*start;
	char			*next;
} split_piece;

static unsigned int	find_split_nbr(char const *s, char c)
{
	unsigned int	result;
	unsigned int	i;

	result = 0;
	i = 0;
	while (s[i])
		if (s[i++] == c)
			result++;
	return (result);
}

static	split_piece	 find_next_piece(char const *s, char c, unsigned int start)
{
	split_piece		next;
	unsigned int	i;

	i = start;
	next.size = 0;
	next.start = &s[start];
	while (s[i] && s[i] != c)
		next.size++;
	if (s[i + 1])
		next.next = &s[i + 1];
	else
		next.next = NULL;
	return (next);
}

static split_piece	*find_split(char const *s, char c)
{
	split_piece		*result;
	unsigned int	i;
	unsigned int	j;

	result = malloc(sizeof(split_piece) * find_split_nbr(s, c));
	i = 0;
	j = 0;
	while (s[i])
	{
		result[j++] = find_next_piece(s, c, i);
		i += result[j].size;
	}
	return (result);
}

char **ft_split(char const *s, char c)
{
	unsigned int	buffer_size;
	unsigned int	i;
	char			**arr;
	split_piece		*list_piece;

	list_piece = find_split(s, c);
	i = 0;
	while (list_piece[i++].next)
		buffer_size++;
	arr = malloc(sizeof(char *) * buffer_size);
	if (!arr)
		return (NULL);
	i = 0;
	while (list_piece[i++].next)
		arr[i] = list_piece[i].start;
	return (arr);
}
