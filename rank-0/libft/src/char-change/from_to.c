/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:37:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 08:38:14 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */
	//...

/* Global */
	//...

/* Modules */
	//...

#pragma endregion	/* Includes */
#pragma region "Functions"

/**
 * @brief Converts an upper-case letter to the corresponding lower-case letter.
 * 
 * @param c Character to be converted.
 * @return int The corresponding lower-case letter.
 */
int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}

/**
 * @brief Converts a lower-case letter to the corresponding upper-case letter.
 * 
 * @param c Character to be converted.
 * @return int The corresponding upper-case letter.
 */
int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

#pragma endregion	/* Functions */