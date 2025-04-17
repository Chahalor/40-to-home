/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _word.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:45:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 13:16:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"
#include "formating.h"

/* Internal */
#include "_game.h"
#include "game.h"

/* Modules  */
#include "dico.h"
#include "display.h"
#include "utils.h"
#include "debug.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) inline t_bool	_is_finish(
	const char checker[MAX_WORD_SIZE]
)
{
	register int	i;
	register int	sum = 0;

	i = -1;
	while (++i < MAX_WORD_SIZE)
		sum += checker[i];
	return (sum == 2 * MAX_WORD_SIZE);
}

/** */
__attribute__((always_inline, used)) inline void	_clear_memory(
	t_screen *memory,
	const int i
)
{
	register int	j;

	debug_print("clear memory\n");
	fflush(STDIN_FILENO);
	j = -1;
	while (++j < i)
	{
		free(memory[j].word);
		memory[j].word = NULL;
		memset(memory[j].pattern, 0, MAX_WORD_SIZE);
	}
}


#pragma endregion Functions