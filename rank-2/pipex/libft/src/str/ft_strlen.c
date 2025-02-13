/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:11:05 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/21 10:38:02 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Computes the length of the string s.
 * 
 * @param s String to be computed.
 * @return unsigned long int Length of the string.
 */
unsigned long int	ft_strlen(const char *s)
{
	unsigned long int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
