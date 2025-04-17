/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _alphabet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:37:22 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 16:40:32 by nduvoid          ###   ########.fr       */
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

void	_updateValues(char *values, char *input, char *checker)
{
	int i = 0;
	int j = 0;
	char a = 'a';

	
	while (i < MAX_WORD_SIZE)
	{
		if (checker[i] == 1 || checker[i] == 2) {
			j = 0;
			a = 'a';
			while (a != input[i]){
				a++;
				j++;
			}
			if (values[j] < checker[i])
				values[j] = checker[i];
		}
		i++;
	}
	printf("%s\n", values);
}

void	_displayAlpha(char *values)
{
	int i = 0;
	char a = 'a';

	while (a < 'z'){
		if (values[i] == 0)
			printf(GREY "%c " RESET, a);
		else if (values[i] == 1)
			printf(YELLOW "%c " RESET, a);
		else
			printf(GREEN "%c " RESET, a);
		a++;
		i++;
	}
}