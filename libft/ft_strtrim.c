/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:57:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/17 15:57:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *s)
{
	unsigned int	i;
	unsigned int	slen;

	slen = ft_strlen(s);
	i = 0;
	while (i < slen)
		if (c == s[i++])
			return (1);
	return (0);
}

static unsigned int	*get_poss(const char *s1, const char *set)
{
	unsigned int	*r;
	unsigned int	i;

	r = (unsigned int *)malloc(sizeof(unsigned int) * 2);
	if (!r)
		return (NULL);
	i = 0;
	while (in_set(s1[i], set))
		i++;
	r[0] = i;
	i = ft_strlen(s1);
	while (in_set(s1[i], set))
		i--;
	r[1] = i;
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	*start_end;
	char			*result;
	unsigned int	buffer;

	buffer = ft_strlen(s1) + 1;
	start_end = get_poss(s1, set);
	if (!start_end)
		return (NULL);
	buffer -= start_end[0] + (buffer - start_end[1]);
	result = (char *)malloc(sizeof(char) * (buffer + 1));
	if (!result)
		return (NULL);
	result = ft_substr(s1, start_end[0], buffer);
	result[buffer] = '\0';
	return (result);
}

int main(void)
{
	char s1[] = " lorem ipsum dolor sit amet";
	char	*trim = ft_strtrim(s1, "et");
	printf("%s", trim);
	return 0;
}