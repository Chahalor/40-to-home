/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:01:14 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/21 16:02:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	if (!s1 || s1[0] == '\0')
		return (-(unsigned char)s2[0]);
	else if (!s2 || s2[0] == '\0')
		return ((unsigned char)s1[0]);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i] || s1[i] == '\0')
			return (-(unsigned char)s2[i]);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i] || s2[i] == '\0')
			return ((unsigned char)s1[i]);
		i++;
	}
	return (0);
}
