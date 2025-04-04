/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:50:33 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 09:51:25 by nduvoid          ###   ########.fr       */
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
 * @brief Locates the first occurrence of c (converted to an unsigned char)
 * in string s.
 * 
 * @param s String to be analyzed.
 * @param c Character to be located.
 * @param n Number of bytes to be analyzed.
 * @return void* Pointer to the located character or NULL
 * if the character does not appear in the string.
 */
void	*ft_memchr(const void *s, int c, unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (NULL);
}

/**
 * @brief Compares the first n bytes of the block of memory pointed by s1 and s2.
 * 
 * @param s1 Pointer to the first block of memory.
 * @param s2 Pointer to the second block of memory.
 * @param n Number of bytes to be compared.
 * @return int An integer less than, equal to, or greater than zero
 *  if the first n bytes of s1 is found, respectively,
 * to be less than, to match, or be greater than the first n bytes of s2.
 */
int	ft_memcmp(const void *s1, const void *s2, unsigned long int n)
{
	unsigned long int	i;
	int					diff;

	i = 0;
	while (i < n)
	{
		diff = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

#pragma endregion	/* Functions */