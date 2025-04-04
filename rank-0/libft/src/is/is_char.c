/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:24:12 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 10:15:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */
	//...

/* Global */
	//...

/* Modules */
#include "is.h"

#pragma endregion	/* Includes */
#pragma region "Functions"

/**
 * @brief Checks for an alphanumeric character.
 * 
 * @param c Character to be checked.
 * @return int 1 if c is an alphanumeric character, 0 otherwise.
 */
__attribute__((pure, const)) int	ft_isalnum(const int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

/**
 * @brief Checks for an alphabetic character.
 * 
 * @param c Character to be checked.
 * @return int 1 if c is an alphabetic character, 0 otherwise.
 */
__attribute__((pure, const, leaf)) int	ft_isalpha(int c)
{
	return ((c >= 65 && 90 >= c) || (c >= 97 && 122 >= c));
}

/**
 * @brief Checks for an ASCII character.
 * 
 * @param c Character to be checked.
 * @return int 1 if c is an ASCII character, 0 otherwise.
 */
__attribute__((pure, const, leaf)) int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

/**
 * @brief Checks for a digit (0 through 9).
 * 
 * @param c Character to be checked.
 * @return int 1 if c is a digit, 0 otherwise.
 */
__attribute__((pure, const, leaf)) int	ft_isdigit(int c)
{
	return (48 <= c && c <= 57);
}

/**
 * @brief Checks for any printable character.
 * 
 * @param c Character to be checked.
 * @return int 1 if c is a printable character, 0 otherwise.
 */
__attribute__((pure, const, leaf)) int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

#pragma endregion	/* Functions */