/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:55:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 15:57:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"
#include "formating.h"
#include <string.h>

/* Internal */
// #include "_utils.h"
#include "utils.h"

/* Modules  */
	//...

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Exits the programme with an error message.
 * 
 * @param	const char *restrict msg The error message to display.
 * @param	int errnum The error number to display.
 * 
 * @return void
 * 
 * @note exit the programme with an error message.
*/
__attribute__((cold, noreturn)) void	exit_error(
	const char *restrict msg,
	const int errnum
)
{
	if (__builtin_expect(msg != NULL, EXPECTED))
	{
		fprintf(stderr, RED "Error: " RESET "%s\n", msg);
		if (__builtin_expect(errnum, EXPECTED))
			fprintf(stderr, PADD "%s\n", strerror(errnum));
	}
	exit(errnum);
}

/**
 * @brief Checks if a character is an alphabetic letter (either lowercase or uppercase).
 *
 * @param c The character to check.
 * 
 * @return t_bool True if the character is alphabetic, false otherwise.
 */
__attribute__((always_inline, used)) inline t_bool	is_alpha(
	const char c
)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/**
 * @brief Generates a random integer within a specified range.
 *
 * @param min The minimum value of the range (inclusive).
 * @param max The maximum value of the range (inclusive).
 * 
 * @return int A random integer between min and max.
 */
__attribute__((always_inline, used)) int	randint(
	int min,
	int max
)
{
	int	tmp;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	return (rand() % (max - min + 1) + min);
}

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * @param s The string whose length is to be calculated.
 * 
 * @return int The length of the string.
 */
static inline int	ft_strlen(
	const char *s
)
{
	register int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

/**
 * @brief Duplicates a null-terminated string by allocating memory for the copy.
 *
 * @param s The string to duplicate.
 * 
 * @return char* A pointer to the newly allocated duplicate string,
 * or NULL if memory allocation fails.
 */
__attribute__((malloc)) char	*ft_strdup(
	const char *restrict s
)
{
	const unsigned int	slen = ft_strlen(s);
	char				*dup;
	unsigned int		i;

	dup = (char *)malloc(sizeof(char) * (slen + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

/**
 * @brief Compares two null-terminated strings lexicographically.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * 
 * @return int A negative value if s1 is less than s2, zero if they are equal,
 * or a positive value if s1 is greater than s2.
 */
__attribute__((always_inline, used)) inline int	ft_strcmp(
	const char *restrict s1,
	const char *restrict s2
)
{
	register int	i;

	if (!s1 || !s2)
		return (0);
	i = -1;
	while (s1[++i] && s2[i])
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (s1[i] - s2[i]);
}

#pragma endregion Functions