/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:26:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/07 15:35:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <unistd.h>

// Global
#include "type.h"

// Modules
#include "formating.h"
#include "utils.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((always_inline)) inline int	ft_strlen(const char *str)
{
	register int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/** */
__attribute__((always_inline)) inline void	ft_error(const char *msg)
{
	write(2, RED ERROR RESET, 21);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

/**
 * @brief Compares the two strings s1 and s2, but at most n bytes.
 * 
 * @param s1 First string to be compared.
 * @param s2 Second string to be compared.
 * @param n Number of bytes to be compared.
 * @return int 0 if the two strings are identical, otherwise the difference
 */
int	ft_strncmp(const char *s1, const char *s2, const size_t n)
{
	register size_t	i;

	if (n == 0)
		return (0);
	if (s1[0] == '\0')
		return (-(unsigned char)s2[0]);
	else if (s2[0] == '\0')
		return ((unsigned char)s1[0]);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i] || s1[i] == '\0')
			return (-(unsigned char)s2[i]);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i] || s2[i] == '\0')
			return ((unsigned char)s1[i]);
		++i;
	}
	return (0);
}

/** */
__attribute__((always_inline, unused))	// if used remove the unused attribute
static inline int	ft_isdigit(const int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/** */
__attribute__((always_inline, used))
static inline int	is_space(const int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}


/**
 * @brief Convert a string to an integer
 * 
 * @param nptr The string to convert
 * @return The integer value of the string
 */
__attribute__((cold))
int	ft_atoi(const char *nptr)
{
	int						r;
	register unsigned int	i;
	int						neg;

	neg = 1;
	r = 0;
	i = 0;
	while (is_space(nptr[i]))
		++i;
	if (nptr[i] == '-')
	{
		neg = -1;
		++i;
	}
	else if (nptr[i] == '+')
		++i;
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		r = r * 10 + (nptr[i++] - 48);
	return (r * neg);
}

#pragma endregion "Functions"