/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _thougth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:09:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 15:51:00 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
#include "_philosopher.h"
#include "_thought.h"

/* -----| Modules  |----- */
#include "philosophers.h"
#include "utils.h"

#pragma endregion Headers
#pragma region Functions

static const char	*_get_thougth(
	const int index
)
{
	static const char	*list[NB_THOUGHTS] = {
		THOUGHT_0, THOUGHT_1, THOUGHT_2, THOUGHT_3, THOUGHT_4, THOUGHT_5,
		THOUGHT_6, THOUGHT_7, THOUGHT_8, THOUGHT_9, THOUGHT_10, THOUGHT_11,
		THOUGHT_12, THOUGHT_13, THOUGHT_14, THOUGHT_15, THOUGHT_16,
		THOUGHT_17, THOUGHT_18, THOUGHT_19, THOUGHT_20, THOUGHT_21,
		THOUGHT_22, THOUGHT_23, THOUGHT_24, THOUGHT_25, THOUGHT_26,
		THOUGHT_27, THOUGHT_28, THOUGHT_29, THOUGHT_30, THOUGHT_31,
		THOUGHT_32, THOUGHT_33, THOUGHT_34, THOUGHT_35, THOUGHT_36,
		THOUGHT_37, THOUGHT_38, THOUGHT_39
	};

	if (_UNLIKELY(index < 0 || index > ((int) sizeof(list) - 1)))
		return ("");
	else
		return (list[index]);
}

static const char	*_get_dream(
	const int index
)
{
	static const char	*list[NB_DREAMS] = {
		DREAM_0, DREAM_1, DREAM_2, DREAM_3, DREAM_4, DREAM_5,
		DREAM_6, DREAM_7, DREAM_8, DREAM_9, DREAM_10, DREAM_11,
		DREAM_12, DREAM_13, DREAM_14, DREAM_15, DREAM_16,
		DREAM_17, DREAM_18, DREAM_19, DREAM_20, DREAM_21,
		DREAM_22, DREAM_23, DREAM_24, DREAM_25, DREAM_26,
		DREAM_27, DREAM_28, DREAM_29
	};

	if (_UNLIKELY(index < 0 || index > ((int) sizeof(list) - 1)))
		return ("");
	else
		return (list[index]);
}

const char	*get_random_thougth(void)
#if ALLOW_THOUGHTS == 1

{
	return (_get_thougth(ft_randint(0, NB_THOUGHTS - 1)));
}

#else

{
	(void)_get_thougth;
	return ("");
}

#endif

const char	*get_random_dream(void)
#if ALLOW_THOUGHTS == 1

{
	int	index;

	if (ft_rand() % 4 == 0)
		index = ft_randint(0, NB_DREAMS - 1);
	else
		index = -1;
	return (_get_dream(index));
}

#else

{
	(void)_get_dream;
	return ("");
}

#endif
#pragma endregion Functions