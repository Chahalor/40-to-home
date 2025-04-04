/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parse_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:00:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 09:20:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
#include <limits.h>

// Global
	//...

// Modules
#include "_parsing.h"
#include "utils.h"
#include "libft.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief	Checks if the string will overflow when converted to an integer.
 * 
 * @param	str	The string to check.
 * 
 * @return	1 if the string will overflow, 0 otherwise.
 */
__attribute__((always_inline, used, pure))
static inline int	will_overflow(const char *str)
{
	int				i;
	int				sign;
	unsigned int	r;
	int				digit;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		++i;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		++i;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if ((r > (unsigned int)(INT_MAX - digit) / 10 && sign == 1)
			|| (r > (unsigned int)((unsigned int)INT_MAX + 1 - digit) / 10))
			return (1);
		r = r * 10 + digit;
		++i;
	}
	return (0);
}

/**
 * @brief	Checks if the string is a valid number.
 *
 * @param	str	The string to check.
 * 
 * @return	1 if the string is a valid number, 0 otherwise.
 * 
 * @exemple
 *		is_valid_number("123");	// returns 1
 *		is_valid_number("12a3");	// returns 0
*/
__attribute__((hot, pure, unused))
static inline int	is_valid_number(const char *str)
{
	register int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	else if (will_overflow(str))
		return (0);
	return (1);
}

/**
 * @brief	Checks if the array is valid (no duplicates).
 * 
 * @param	array	The array to check.
 * @param	size	The size of the array.
 * 
 * @return	1 if the array is valid, 0 otherwise.
 * 
 * 
 * @exemple
 * 		is_array_valid({1, 2, 3}, 3);	// returns 1
 * 		is_array_valid({1, 1, 2}, 3);	// returns 0
 */
__attribute__((cold, pure, unused))
static inline int	is_array_valid(const t_nb *array, const int size)
{
	register int	i;
	register int	j;

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

/**
 * @brief	Parses a string and fills the destination array with numbers.	
 * 
 * @param	str	The string to parse.
 * @param	dest	The destination array to fill.	
 * @param	start	The starting index in the destination array.
 * @param	max	The maximum size of the destination array.
 * 
 * @return	The number of elements added to the destination array.
*/
__attribute__((cold))
static int	multiple_atoi(char *str, t_nb **dest, const int start, int *max)
{
	char			**splited;
	register int	i;

	splited = ft_split(str, ' ');
	if (!splited)
		return (-1);
	i = -1;
	while (splited[++i])
	{
		if (!is_valid_number(splited[i]))
			return (freeing_array(splited), -1);
		if (start + i >= *max)
		{
			*dest = reallocing(*dest, (*max) * sizeof(t_nb),
					((*max) + PARSING_ALLOC_SIZE) * sizeof(t_nb));
			if (!*dest)
				return (freeing_array(splited), -1);
			(*max) += PARSING_ALLOC_SIZE;
		}
		(*dest)[start + i].value = ft_atoi(splited[i]);
		(*dest)[start + i].index = -1;
	}
	freeing_array(splited);
	return (i);
}

/**
 * @brief	Parses the stack from the command line arguments.
 * 
 * @param	argc	The number of arguments.
 * @param	argv	The arguments.
 * @param	i		The index of the current argument.
 * @param	args	The arguments structure.
 * 
 * @return	The parsed stack.
 */
__attribute__((cold, malloc))
t_nb	*_parse_stack(const int argc, const char **argv, int *i, t_args *args)
{
	t_nb	*result;
	int		ret;
	int		alloced;

	alloced = PARSING_ALLOC_SIZE;
	result = (t_nb *)mallocing(sizeof(t_nb) * alloced);
	if (__builtin_expect(!result, unexpected))
		return (args->error = 1, NULL);
	while ((*i) < argc && ret != -1)
	{
		ret = multiple_atoi((char *)argv[(*i)++], &result, args->len_stack,
				&alloced);
		args->len_stack = (args->len_stack + ret) * (ret != -1);
	}
	if (__builtin_expect(!args->len_stack, unexpected))
		return (args->error = 1, free(result), NULL);
	else if (!is_array_valid(result, args->len_stack))
		return (args->error = 1, free(result), NULL);
	else
		return (result);
}

#pragma endregion	/* Functions */