/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:04:45 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:29:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks for a digit (0 through 9).
 * 
 * @param c Character to be checked.
 * @return int 1 if c is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (48 <= c && c <= 57);
}
