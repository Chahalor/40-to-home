/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:04:17 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:29:23 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks for an ASCII character.
 * 
 * @param c Character to be checked.
 * @return int 1 if c is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
