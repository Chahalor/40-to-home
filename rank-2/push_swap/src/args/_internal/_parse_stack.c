/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:00:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/18 16:18:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
//...

// Global
#include "_parsing.h"

// Modules
//...

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((cold, pure, leaf))
int	len(const char *str)
{
	int	i;
	int	result;

	result = 0;
	i = -1;
	while (str[++i])
		if (str[i] != ' ' && str[i + 1] == ' ')
			++result;
	return (result);
}

/** */
__attribute__((cold, malloc))
int	*_parse_stack(const int argc, const char **argv, int *i, t_args *args)
{
	int		*result;
	int		j;

	result = (int *)malloc(sizeof(int) * (argc - *i));
	if (!result)
	{
		args->error = malloc_failed;
		return (NULL);
	}
	j = -1;
	while (++(*i) < argc)
	{
		result[j] = ft_atoi(argv[*i]);
		if (result[j] == 0 && (argv[*i][0] != '0' && argv[*i][1] != '\0'))
		{
			args->error = invalid_number;
			return (free(result), NULL);
		}
		++j;
	}
	args->len_stack = j;
	return (result);
}

#pragma endregion	/* Functions */