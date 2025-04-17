/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:18:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 17:18:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"
#include "letter.h"
#include "formating.h"
#include <stdio.h>	//@todo: move to a .h file
#include <unistd.h>	//@todo: move to a .h file

/* Internal */
#include "display.h"

/* Modules  */
#include "debug.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Print the header of the programme.
 * 
 * @param void
 * 
 * @return void
*/
__attribute__((always_inline, used)) inline void	print_header(
	void
)
{
	return ;	// dont have time bruh
	printf(FULL_CLEAN "%s\n", HEADER);
}

/**
 * @brief	Print a string in ASCII art.
 * 
 * @param const	char	*str The string to print.
 * 
 * @return void
*/
__attribute__((used)) void	print_str_to_art(
	const char *str
)
{
	static const char	*alphabet[28][LETTER_HEIGHT] = {
		A, B, C, D, E, F, G, H, I, J,
		K, L, M, N, O, P, Q, R, S, T,
		U, V, W, X, Y, Z, SPACE, BLANK
	};
	register int	i;
	register int	j;
	register int	index = 27;

	i = -1;
	while (++i < LETTER_HEIGHT)
	{
		j = -1;
		while (str[++j])
		{
			if (str[j] >= 'a' && str[j] <= 'z')
				index = str[j] - 'a';
			else if (str[j] >= 'A' && str[j] <= 'Z')
				index = str[j] - 'A';
			else if (str[j] == ' ')
				index = 26;
			else
				index = 27;
			printf("%s", alphabet[index][i]);
		}
		printf("\n");
	}
}

/**
 * @brief	Print a string in ASCII art with a pattern.
 * 
 * @param	const	char	*str The string to print.
 * @param	char	patern[MAX_WORD_SIZE] The pattern to use.
 * 
 * @return void
*/
__attribute__((hot)) void	print_str_to_art_patern(
	const char *str,
	char patern[MAX_WORD_SIZE]
)
{
	static const char	*alphabet[28][LETTER_HEIGHT] = {
		A, B, C, D, E, F, G, H, I, J,
		K, L, M, N, O, P, Q, R, S, T,
		U, V, W, X, Y, Z, SPACE, BLANK
	};
	static const char	*colors[3]= {GREY, YELLOW, GREEN};
	register int	i;
	register int	j;
	register int	index = 27;

	if (!str || !patern)
		return ;
	i = -1;
	while (++i < LETTER_HEIGHT)
	{
		j = -1;
		while (str[++j])
		{
			if (str[j] >= 'a' && str[j] <= 'z')
				index = str[j] - 'a';
			else if (str[j] >= 'A' && str[j] <= 'Z')
				index = str[j] - 'A';
			else if (str[j] == ' ')
				index = 26;
			else
				index = 27;
			printf("%s%s" RESET, colors[(int)patern[j]], alphabet[index][i]);
		}
		printf("\n");
	}
}


#pragma endregion Functions