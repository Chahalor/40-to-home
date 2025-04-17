/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:55:00 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/15 10:40:06 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"
#include "formating.h"

/* Internal */
// #include "_utils.h"
#include "utils.h"

/* Modules  */
	//...

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((cold)) void	exit_error(
	const char *msg,
	const int errnum
)
{
	if (__builtin_expect(msg, EXPECTED))
	{
		fprintf(stderr, RED "Error: " RESET "%s\n", msg);
		if (__builtin_expect(errnum, EXPECTED))
			fprintf(stderr, PADD "%s\n", strerror(errnum));
	}
	exit(errnum);
}

/** */
__attribute__((always_inline, used)) inline t_bool	is_alpha(
	const char c
)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/** */
__attribute__((always_inline, used)) int	randint(
	int min,
	int max
)
{
	int	tmp;

	if (min > max)
	{
		tmp = min;
		min = max;
		max = tmp;
	}
	return (rand() % (max - min + 1) + min);
}

#pragma endregion Functions