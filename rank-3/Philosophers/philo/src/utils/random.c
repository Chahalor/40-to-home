/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:17:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 14:31:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers
// System
#include <string.h>
#include <unistd.h>
#include <stdio.h>

// Global
#include "type.h"
#include "config.h"

// Modules
#include "_utils.h"
#include "utils.h"

#pragma endregion Headers
#pragma region Functions

/**
 * use  Linear Congruential Generator (LCG) for random number generation.
 */
static int	_manager(
	const int access,
	const void *const data
)
{
	static int		seed = 1;
	static t_mutex	prot = PTHREAD_MUTEX_INITIALIZER;

	lock(&prot);
	if (_LIKELY(access == get_value))
		seed = seed * RAND_MAGIC_VALUE1 + RAND_MAGIC_VALUE2;
	else if (_UNLIKELY(access == add_seed))
		seed = *(const int *)data;
	unlock(&prot);
	return (seed);
}

/**
 * @brief	Set the seed for the random number generator.
 * 
 * @param	seed New seed value.
 * 
 * @return	the seed
 */
int	set_seed(
	const int seed
)
{
	return (_manager(add_seed, &seed));
}

/**
 * @brief	Generate a random integer between min and max (inclusive).
 * 
 * @param	min Minimum value (inclusive).
 * @param	max Maximum value (inclusive).
 * 
 * @return	Generated random integer.
 * 
 * @note	Uses a Linear Congruential Generator (LCG) for rng.
 */
int	ft_randint(
	const int min,
	const int max
)
{
	return ((_manager(get_value, NULL) % (max - min + 1)) + min);
}

#pragma endregion Functions