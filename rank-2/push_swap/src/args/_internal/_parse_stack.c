/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:00:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/19 14:25:00 by nduvoid          ###   ########.fr       */
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
__attribute__((hot, pure))
static inline int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

__attribute__((cold, pure))
static inline int	is_array_valid(const t_nb *array, const int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (array[i].value == array[j].value)
				return (0);
	}
	return (1);
}

/** */
__attribute__((cold))
static inline int	argv_to_array(const char **argv, const int max, t_nb *dest)
{
	int	i;

	i = -1;
	while (++i < max)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		dest[i].value = ft_atoi(argv[i]);
		dest[i].index = -1;
		if (dest[i].value == 0 && (argv[i][0] != '0' && argv[i][1] != '\0'))
			return (0);
	}
	if (!is_array_valid(dest, i))
		return (0);
	return (i);
}

/** */
__attribute__((cold, malloc))
t_nb	*_parse_stack(const int argc, const char **argv, int *i, t_args *args)
{
	t_nb	*result;

	result = (t_nb *)malloc(sizeof(t_nb) * (argc - *i));
	if (__builtin_expect(!result, unexpected))
	{
		args->error = malloc_failed;
		return (NULL);
	}
	args->len_stack = argv_to_array(&argv[*i], argc - *i, result);
	if (__builtin_expect(!args->len_stack, unexpected))
	{
		free(result);
		args->error = invalid_number;
		return (NULL);
	}
	*i += args->len_stack;
	return (result);
}

#pragma endregion	/* Functions */