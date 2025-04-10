/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:26:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/10 19:35:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

// Global
#include "type.h"

// Modules
#include "formating.h"
#include "utils.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((always_inline, used)) inline int	get_ms_time(void)
{
	struct timeval	tv;

	if (__builtin_expect(gettimeofday(&tv, NULL), unexpected))
		return (-1);
	else
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/** */
__attribute__((cold, unused)) void	*emergency_storage(
	void *ptr
)
{
	static void	*storage = NULL;

	if (ptr)
		storage = ptr;
	return (storage);
}

/** */
__attribute__((always_inline)) inline int	ft_strlen(
const char *str
)
{
	register int	i;

	if (!str)
		return (0);
	else
	{
		i = 0;
		while (str[i])
			i++;
		return (i);
	}
}

/**
 * @brief Sets the first n bytes of the block of memory pointed by s to zero.
 * 
 * @param s Pointer to the block of memory to fill.
 * @param n Number of bytes to be set to zero.
 * @return void
 */
__attribute__((always_inline)) inline void	ft_bzero(
	void *ptr, size_t len
)
{
	uint8_t			*p;
	const uint64_t	zero[4] = {0, 0, 0, 0};
	const size_t	step = 32;

	p = (uint8_t *)ptr;
	while (((uintptr_t)p % step) && len--)
		*p++ = 0;
	while (len >= step)
	{
		*(uint64_t *)(p + 0) = zero[0];
		*(uint64_t *)(p + 8) = zero[1];
		*(uint64_t *)(p + 16) = zero[2];
		*(uint64_t *)(p + 24) = zero[3];
		p += step;
		len -= step;
	}
	while (len--)
		*p++ = 0;
}

/** */
__attribute__((always_inline, malloc)) inline void	*ft_calloc(
	const size_t nmemb, const size_t size
)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (__builtin_expect(!ptr, unexpected))
		return (NULL);
	else
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

#pragma endregion "Functions"