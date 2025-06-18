/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _data.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:31:52 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/29 13:56:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_parsing.h"

/* -----| Modules  |----- */
#include "parsing.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief Print the error message for the number of arguments
 * 
 * @param current The current number of arguments
 * @param min The minimum number of arguments
 * @param max The maximum number of arguments
 * 
 * @return void
 */
__attribute__((always_inline, used)) static inline void	err_args_num(
	const int current,
	const int min,
	const int max
)
{
	if (current < min)
		printf(RED ERROR RESET "too few arguments\n" PADD \
			"get %d arguments, need %d or %d\n", current, min, max);
	else
		printf(RED ERROR RESET "too many arguments\n" PADD \
			"get %d arguments, need %d or %d\n", current, min, max);
}

/**
 * @brief Print the error message for an invalid number
 * 
 * @param arg The invalid argument
 * 
 * @return void
 */
__attribute__((always_inline, used)) static inline void	err_invalid_num(
	const char *restrict arg,
	const int out
)
{
	if (out == -1)
		printf(RED ERROR RESET "invalid argument:\n" PADD \
			"argument \"%s\" is negative, only positive numbers allowed\n",
			arg);
	else
		printf(RED ERROR RESET "invalid argument:\n" PADD \
			"argument \"%s\" is not a valid number\n", arg);
}

/**
 * @brief Check if the arguments are valid. aka they are 4 or 5 valid numbers
 * 
 * @param argv The arguments
 * @param i The index of the first argument
 * @param argc The number of arguments
 * 
 * @return true if the arguments are valid, false otherwise
 */
__attribute__((always_inline, used)) inline t_bool	_is_valide_args(
	const char *restrict *restrict argv,
	const int i,
	const int argc
)
{
	register int	j;
	int				out;

	if (__builtin_expect(argc - i < 4 || argc - i > 5, unexpected))
	{
		err_args_num(argc - i, 4, 5);
		return (false);
	}
	j = -1;
	while ((++j < 4))
	{
		out = is_nbr(argv[i + j]);
		if (out == -1 || out == 0)
			return (err_invalid_num(argv[i + j], out), false);
	}
	if (argc - i > 4)
	{
		out = is_nbr(argv[i + j]);
		if (out == -1 || out == 0)
			return (err_invalid_num(argv[i + j], out), false);
	}
	return (true);
}

#pragma endregion Functions