/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:00:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/28 15:30:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
	//...

// Global
	//...

// Modules
#include "_parsing.h"
#include "utils.h"
#include "libft.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((hot, pure, unused))
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

__attribute__((cold, pure, unused))
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
int	multiple_atoi(char *str, t_nb *dest, int start, int *max)
{
	char	**splited;
	int		i;

	splited = ft_split(str, ' ');
	if (!splited)
		return (-1);
	i = -1;
	while (splited[++i])
	{
		if (!is_valid_number(splited[i]))
			return (free(splited), -1);
		if (start + i >= *max)
		{
			dest = reallocing(dest, (*max) * sizeof(t_nb),
				((*max) + PARSING_ALLOC_SIZE) * sizeof(t_nb));
			if (!dest)
				return (free(splited), -1);
			(*max) += PARSING_ALLOC_SIZE;
		}
		dest[start + i].value = ft_atoi(splited[i]);
		dest[start + i].index = -1;
		free(splited[i]);
	}
	free(splited);
	return (i);
}

/** */
__attribute__((cold, malloc))
t_nb	*_parse_stack(const int argc, const char **argv, int *i, t_args *args)
{
	t_nb	*result;
	int		ret;
	int		alloced;

	alloced = PARSING_ALLOC_SIZE;
	result = (t_nb *)malloc(sizeof(t_nb) * alloced);
	if (__builtin_expect(!result, unexpected))
	{
		args->error = 1;
		return (NULL);
	}
	while ((*i) < argc && ret != -1)
	{
		ret = multiple_atoi((char *)argv[*i], result, args->len_stack, &alloced);
		args->len_stack += ret;
		++(*i);
	}
	if (__builtin_expect(!args->len_stack, unexpected))
	{
		free(result);
		args->error = 1;
		return (NULL);
	}
	if (is_array_valid(result, args->len_stack) == 0)
	{
		free(result);
		args->error = 1;
		return (NULL);
	}
	return (result);
}

#pragma endregion	/* Functions */