/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:05:05 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:29:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks for any printable character.
 * 
 * @param c Character to be checked.
 * @return int 1 if c is a printable character, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}
