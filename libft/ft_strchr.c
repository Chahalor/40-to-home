/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:10:22 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/23 14:10:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		if (s[i++] == (unsigned char)c)
			return (&((char *)s)[i - 1]);
	if (s[i++] == (unsigned char)c)
		return (&((char *)s)[i - 1]);
	return (NULL);
}
