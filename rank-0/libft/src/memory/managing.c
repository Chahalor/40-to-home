/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:46:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/07 08:15:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */
	//...

/* Global */
	//...

/* Modules */
#include "memory.h"

#pragma endregion	/* Includes */
#pragma region "Functions"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s
 * with the constant byte c.
 * 
 * @param s Pointer to the memory area.
 * @param c Constant byte to be copied.
 * @param n Number of bytes to be copied.
 * @return void* Pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	register size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = c;
	return (s);
}

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * 
 * @param dest Pointer to the destination array
 * where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param n Number of bytes to copy.
 * @return void* dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	register size_t	i;

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

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * 
 * @param dest Pointer to the destination array
 * where the content is to be copied.
 * @param src Pointer to the source of data to be copied.
 * @param n Number of bytes to copy.
 * @return void* dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	register size_t	i;

	if (!dest && !src && n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/** */
__attribute__((malloc)) void	*ft_memdup(const void *src, const size_t n)
{
	void	*dest;

	dest = malloc(n);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, n);
	return (dest);
}

/**
 * @brief Sets the first n bytes of the block of memory pointed by s to zero.
 * 
 * @param s Pointer to the block of memory to fill.
 * @param n Number of bytes to be set to zero.
 * @return void
 */
void	ft_bzero(void *s, unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

#pragma endregion	/* Functions */