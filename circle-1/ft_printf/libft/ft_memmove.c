/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:08:08 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/23 14:08:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (!dest && !src)
		return (NULL);
	if (((unsigned char *)src) < ((unsigned char *)dest)
		&& ((unsigned char *)src) < ((unsigned char *)dest) + n)
	{
		i = n;
		while (i-- > 0)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
