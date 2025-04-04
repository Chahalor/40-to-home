/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:26:49 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 10:15:16 by nduvoid          ###   ########.fr       */
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
 * @brief Checks if the given string is a number. (aka if it contains only
 *  digits)
 * 
 * @param str The string to check.
 * 
 * @return int 1 if the string is a number, 0 otherwise.
 * 
 * @note This function is marked as `const` and `pure`, indicating that it does
 * not modify any state and its result depends only on the input parameters.
 * 
 * example:
 * ```c
 * ft_isnumber("12345") // returns 1
 * ft_isnumber("123a45") // returns 0
 * ft_isnumber("") // returns 0
 * ```
 */
__attribute__((const, pure)) int	ft_isnumber(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

#pragma endregion	/* Functions */