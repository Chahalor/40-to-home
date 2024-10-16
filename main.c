/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:47:34 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 13:47:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft_home/libft_home.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	unsigned int	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < nmemb)
		arr[i++] = 0;
	return (arr);
}

char	*ft_strdup(const char *s)
{
	char			*dupp;
	unsigned int	slen;
	unsigned int	i;

	slen = ft_strlen(s);
	dupp = malloc(sizeof(char) * slen);
	if (!dupp)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		dupp[i] = s[i];
		i++;
	}
	return (dupp);
}

int main(void)
{
	/*
	char	*vstrtrim = "AMOGUSAMO";
	char	*trimr = ft_strtrim(vstrtrim, "");
	write(1, trimr, ft_strlen(trimr));
	free(trimr);
	write(1, "\n\n====\n\n", 8);

	char	*splitstr = "aa.bb.cc.dd";
	char	**splitr = ft_split(splitstr, '.');
	int	i = 0;
	while (i < 5)
	{
		write(1, splitr[i], ft_strlen(splitr[i]));
		free(splitr[i]);
		i++;
	}
	free(splitr);
	*/

	return (0);
}
