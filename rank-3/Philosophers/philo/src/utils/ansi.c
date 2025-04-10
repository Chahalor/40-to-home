/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:17:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/10 15:39:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <string.h>
#include <unistd.h>
#include <stdio.h>

// Global
#include "type.h"
#include "config.h"

// Modules
#include "utils.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((used, always_inline)) static inline void	ft_memcpy(
	void *dst,
	const void *src,
	size_t n
)
{
	char		*dest = (char *)dst;
	const char	*source = (const char *)src;

	while (n--)
		*dest++ = *source++;
}


/** */
__attribute__((used, always_inline)) static inline int	uputnbr(
	int n,
	char *buf
)
{
	char			tmp[4];
	register int	i;
	register int	len;

	i = 0;
	if (n == 0)
		tmp[i++] = '0';
	else
	{
		while (n > 0)
		{
			tmp[i++] = '0' + (n % 10);
			n /= 10;
		}
	}
	len = 0;
	while (i--)
		buf[len++] = tmp[i];
	return (len);
}

void	write_rgb_ansi(
	const int rgb
)
{
	char	buf[32];
	int		len;

	len = 7;
	ft_memcpy(buf, "\033[38;2;", len);
	len += uputnbr((rgb >> 16) & 0xFF, buf + len);
	buf[len++] = ';';
	len += uputnbr((rgb >> 8) & 0xFF, buf + len);
	buf[len++] = ';';
	len += uputnbr(rgb & 0xFF, buf + len);
	buf[len++] = 'm';
	buf[len] = '\0';
	printf("%s", buf);
}

#pragma endregion "Functions"