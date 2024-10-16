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

#include "libft_home.h"

static void	*expand_malloc(char *arr, size_t new_size)
{
	char	*tmp_arr;
	size_t	i;

	tmp_arr = ft_strdup(arr);
	free(arr);
	arr = (char *)malloc(sizeof(char) * (new_size + 1));
	if (!tmp_arr || !arr)
	{
		free(tmp_arr);
		return (NULL);
	}
	i = 0;
	while (i++ < new_size)
		arr[i + 1] = tmp_arr[i];
	arr[new_size - 1] = '\0';
	free(tmp_arr);
	return (arr);
}

char	*ft_itoa(int n)
{
	size_t	r_size;
	char	*result;

	r_size = 1;
	result = malloc(sizeof(char) * r_size);
	if (!result)
		return (NULL);
	while (n % 10)
	{
		// printf("result : %s\n", result);
		result = expand_malloc(result, r_size + 1); // ou `result = expand_malloc(result, r_size, r_size + 1);`
		if (!result)
			return (NULL);
		result[0] = n % 10;
		r_size++;
	}
	if (n < 0)
	{
		result = expand_malloc(result, r_size + 1); // ou `result = expand_malloc(result, r_size, r_size + 1);`
		if (!result)
			return (NULL);
		result[0] = '-';
	}
	return (result);
}
/*
int main(void)
{
		char	*tkt = "MOGUS";
	tkt = expand_malloc(tkt, 5);
	tkt[0] = 'A';
	write(1, tkt, ft_strlen(tkt));
	return 0;
}

*/