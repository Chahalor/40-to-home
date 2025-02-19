/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:03:29 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:29:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks for an alphabetic character.
 * 
 * @param c Character to be checked.
 * @return int 1 if c is an alphabetic character, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	return ((c >= 65 && 90 >= c) || (c >= 97 && 122 >= c));
}
