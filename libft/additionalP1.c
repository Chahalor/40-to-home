/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionalP1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:57:12 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/18 16:33:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*result;

	if (!s || s[0] == '\0')
		return ("");
	if (start > ft_strlen(s))
		return ("");
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i])
		result[j++] = s[i++];
	result[j] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

// int main(void)
// {
// 	(void)ft_strjoin("", "");
// 	char	*s = "";
// 	char	*r = ft_substr(s, 2, 6);
// 	printf("%s\n", r);

// 	return (0);
// }