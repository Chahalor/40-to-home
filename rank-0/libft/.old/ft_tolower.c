/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:14:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 08:38:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
