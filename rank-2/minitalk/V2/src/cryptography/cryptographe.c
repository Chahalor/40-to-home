/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cryptographe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:27:20 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 11:25:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

__attribute__((malloc)) char *encode_xor(const char *str, const char *key)
{
	int		i;
	int		j;
	int		len;
	char	*r;

	r = ft_strdup(str);
	if (!r)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(key);
	while (str[i])
	{
		r[i] ^= key[j];
		r[i] += 1;
		i++;
		j = (j + 1) % len;
	}
	return (r);
}

__attribute__((malloc)) char *decode_xor(const char *str, const char *key)
{
	int		i;
	int		j;
	int		len;
	char	*r;

	r = ft_strdup(str);
	if (!r)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(key);
	while (str[i])
	{
		r[i] -= 1;
		r[i] ^= key[j];
		i++;
		j = (j + 1) % len;
	}
	return (r);
}
// #include <stdio.h>
// int main(void)
// {
// 	char *str = "Hello, World!";
// 	const char *key = "sush";

// 	printf("Original: %s\n", str);
// 	str = encode_xor(str, key);
// 	printf("Encoded: %s\n", str);
// 	str = decode_xor(str, key);
// 	printf("Decoded: %s\n", str);
// 	return (0);
// }
