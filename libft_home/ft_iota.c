/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:14:00 by marvin            #+#    #+#             */
/*   Updated: 2024/10/16 09:14:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
char *ft_strdup(const char *s);

void	*expand_malloc(char *arr, size_t size, size_t new_size)
{
	char	*tmp_arr;
	size_t	i;

	tmp_arr = ft_strdup(arr);
	arr = malloc(sizeof(char) * new_size);
	if (!arr || !tmp_arr)
		return (NULL);
	i = 1;
	while (i++ < new_size)
		arr[i] = tmp_arr[i - 1];
	return (arr);
}

char *ft_itoa(int n)
{
	size_t	r_size;
	char	*result;

	r_size = 1;
	result = malloc(sizeof(char) * r_size);
	if (!result)
		return (NULL);
	while (n % 10)
	{
		result[0] = n % 10;
		expand_malloc(result, r_size, r_size + 1); // ou `result = expand_malloc(result, r_size, r_size + 1);`
		if (!result)
			return (NULL);
		r_size++;
	}
	if (n < 0)
	{
		expand_malloc(result, r_size, r_size + 1); // ou `result = expand_malloc(result, r_size, r_size + 1);`
		if (!result)
			return (NULL);
		result[0] = '-';
	}
	return (result);
}
