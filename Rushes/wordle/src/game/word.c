/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:34:36 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 17:19:38 by nduvoid          ###   ########.fr       */
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

char *get_random_word(
	const t_dico2 *dict
)
{
	const int total_words = dict->size;
	int	target = rand() % total_words;

	for (int i = 0; i < MAP_SIZE; ++i) {
		t_word *cur = dict->table[i];
		while (cur) {
			if (target == 0)
				return cur->word;
			target--;
			cur = cur->next;
		}
	}
	return (NULL); // Should not happen if total_words is correct
}


/** */
__attribute__((hot)) char	*get_word(
	const t_dico2 *dico
)
{
	char			*word = NULL;

	word = get_random_word(dico);//ft_strdup(buffer);
	debug_print("get_word(): word: %s\n", word);
	return (word);
}

/** */
void	update_screen(
	char data[MAX_WORD_SIZE],
	const int i,
	char *input
)
{
	static t_screen	memory[MAX_TRY] = {0};
	register int	j = -1;
	
	if (!input)
		return (_clear_memory(memory, i));

	memory[i].word = input;
	memcpy(memory[i].pattern, data, MAX_WORD_SIZE);

	while (++j <= i)
	{
		debug_print("update_screen(): word: %p, i=%d\n", memory[j].word, i);	// rm
		print_str_to_art_patern(memory[j].word, memory[j].pattern);
	}
	while (j++ < MAX_TRY)
		print_str_to_art("00000");
}

/** */
int	the_game(
	const char *restrict word,
	t_dico2 *dico
)
{
	register int	i;
	char			checker[MAX_WORD_SIZE] = {0};
	char			*input;
	int				data = 0;
	t_bool			running = TRUE;
	char			*values;

	values = calloc(sizeof(char), 27);
	if (!values)
		return (EXIT_MALLOC);
	i = -1;
	while (++i < MAX_TRY && running)
	{
		input = get_input(STDIN_FILENO);
		if (!input)
			update_screen(checker, i, NULL);
		else
			data = check_input(input, word, checker, dico);
		if (!data)
		{
			printf(RED "invalid input: %s\n" RESET, input);
			free(input);
			--i;
		}
		else
		{
			running = _is_finish(checker) != TRUE;
			update_screen(checker, i, input);
			_updateValues(values, input, checker);
			_displayAlpha(values);
			printf("\n");
		}
		memset(checker, 0, MAX_WORD_SIZE);
		// fflush(STDIN_FILENO);
	}
	update_screen(checker, i, NULL);
	free(values);
	return (running);
}

__attribute__((hot)) void	end_game(
	char *restrict word,
	const int result
)
{
	if (!result)
		printf(GREEN "You win! The word was: %s\n" RESET, word);
	else
		printf(RED "You lose! The word was: %s\n" RESET, word);
	printf("Press enter to continue...\n");
	read(1, NULL, 1);
}

/** */
__attribute__((hot)) int	start_game(
	t_dico *restrict dico
)
{
	char	*word;
	register int	i;


	word = get_word(dico);
	if (!word)
		exit_error("get_word(): unable to find a word (da fuck ?? )", ENOMEM);
	print_header();
	i = -1;
	while (++i < MAX_TRY)
		print_str_to_art("00000");
	end_game(word, the_game(word, dico));
	return (0);
}

#pragma endregion Functions