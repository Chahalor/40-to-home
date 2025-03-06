/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:22:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/06 13:57:20 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft/libft.h"

char *e_xor(char *str, const char *key)
{
	int	i;
	int	j;

	if (!str || !key)
		return (NULL);
	i = -1;
	j = -1;
	while (str[++i])
	{
		str[i] ^= key[++j];
		j *= (key[j] != '\0');
	}
	return (str);
}

char	*e_and(char *str, const char *key)
{
	int	i;
	int	j;

	if (!str || !key)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		str[i] &= key[j++];
		j *= (key[j] != '\0');
	}
	return (str);
}

#include <stdio.h>
int main()
{
	char		str[] = "Hello world\n";
	const char	*key = "key";

	// // printf("Original: %s\n", str);

	e_xor(str, key);
	write(1, str, 11);
	
	write(1, "\n", 1);

	e_xor(str, key);
	write(1, str, 11);
	// // printf("decoded: %s\n", str);
	
	return (0);
}
