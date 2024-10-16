/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:57:46 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 07:57:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_home.h"

static unsigned int	check_begin(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	setlen;

	setlen = ft_strlen(set);
	i = 0;
	while (i < setlen && set[i] == s1[i])
		i++;
	if (i == setlen)
		return (setlen);
	return (0);	
}
static unsigned int	check_end(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	setlen;

	setlen = ft_strlen(set);
	i = 0;
	while (i < ft_strlen(s1) && j < setlen && set[j] == s1[i])
	{
		i++;
		j++;
	}
	if (j == setlen)
		return (setlen);
	return (0);
}


char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	setbegin;
	unsigned int	setend;
	unsigned int	buffer;
	char			*result;
	unsigned int	i;

	setbegin = check_begin(s1, set);
	setend = check_end(s1, set);
	buffer = ft_strlen(s1) - (setbegin + setend);
	printf("begin=%d, end=%d, buffer=%d", setbegin, setend, buffer);
	result = malloc(sizeof(char) * buffer);
	if (!result)
		return (NULL);
	i = setbegin;
	while (i < setbegin + buffer)
	{
		result[i - setbegin] = s1[i];
		i++;
	}
	return (result);
}
