/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:26:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 16:57:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>
#include <string.h>

// Global
#include "type.h"

// Modules
#include "formating.h"
#include "utils.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((always_inline)) inline void ft_memcpy(
	void *restrict dest,
	const void *restrict src,
	register const size_t len
)
{
	register size_t	i;

	if (__builtin_expect(!dest || !src, unexpected))
		return ;
	i = -1;
	while (++i < len)
		((char *)dest)[i] = ((char *)src)[i];
}

/** */
__attribute__((always_inline)) static inline	_	// fonction to split ft_sprintf

/** */
__attribute__((always_inline)) inline int	ft_sprintf(
	char *restrict dest,
	int nb
)
{
	int				neg;
	register int	i;
	int				start;
	register int	j;
	register int	k;

	neg = 0;
	i = 0;
	if (__builtin_expect(!dest, 0))
		return (-1);
	else if (nb == 0)
		return ((void)memset(dest, 0, 2), 2);
	else if (nb < 0)
	{
		neg = 1;
		dest[i++] = '-';
		nb = -nb;
	}
	start = i;
	while (nb)
	{
		dest[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	dest[i] = '\0';
	j = start;
	k = i - 1;
	while (j < k)
	{
		++j;
		--k;
		char tmp = dest[j];
		dest[j] = dest[k];
		dest[k] = tmp;
	}
	return (i);
}


#pragma endregion "Functions"