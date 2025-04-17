/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:35:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 16:48:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"

/* Internal */
#include "_game.h"
#include "game.h"

/* Modules  */
#include "dico.h"
#include "display.h"
#include "utils.h"
#include "debug.h"
#include "game.h"

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	returne the length of a NULL terminated string
 * 
 * @param	const	char	*restrict	str The string to measure.
 * 
 * @return	int The length of the string.
 */
__attribute__((always_inline, used)) static inline int ft_strlen(
	const char *restrict str
)
{
	register int i = 0;

	while (str[i])
		++i;
	return (i);
}

/**
 * @brief	Flush the file descriptor.
 * 
 * @param	const	int	fd The file descriptor to flush.
 * 
 * @return void
 */
__attribute__((always_inline, used)) static inline void	flush_fd(
	const int fd
)
{
	char buff[1024];

	while (read(fd, buff, sizeof(buff)))
		continue ;
}

/**
 * @brief	Check if a character is inside the word.
 * 
 * @param	const	char	*restrict	word The word to check.
 * @param	char	c The character to check.
 * 
 * @return int The index of the character in the word, or -1 if not found.
 */
__attribute__((always_inline, used)) static inline int	is_inside(
	const char *restrict word,
	char c
)
{
	int i = 0;

	while (i < 5){
		if (word[i] == c){
			return (i);
		}
		i++;
	}
	return (-1);
}

/**
 * @brief	Fill the checker array with the result of the check.
 * 
 * @param	const char	*restrict	word The word to check.
 * @param	const char	*restrict	input The input to check.
 * @param	char	*checker The checker array to fill.
 * @param	char	c The character to check.
 * @param	int	place The index of the character to check.
 * 
 * @return void
 */
__attribute__((hot)) void	checkerFill(
	const char *restrict word,
	const char *restrict input,
	char *checker,
	char c,
	int place
)
{
	if (word[place] == input[place]){
		checker[place] = 2;
		return ;
	}
	else if (word[place] != input[place] && is_inside(word, c) != -1){
		checker[place] = 1;
		return ;
	}
	else if (is_inside(word, c) == -1){
		checker[place] = 0;
		return ;
	}
}

/**
 * @brief	Check if the input is valid.
 * 
 * @param	char	*input The input to check.
 * @param	const char	*restrict	word The word to check.
 * @param	char	checker[MAX_WORD_SIZE] The checker array to fill.
 * 
 * @return int 1 if the input is valid, 0 otherwise.
 */
__attribute__((hot)) int	check_input(
	char *input,
	const char *restrict word,
	char checker[MAX_WORD_SIZE],
	t_dico2 *dico
)
{
	int		i;
	int		j;

	if (word_exists(dico, input) == FALSE)
		return (0);
	// if (ft_strlen(input) != MAX_WORD_SIZE)
		// return (0);
	i = -1;
	while (input[++i])
		if (!is_alpha(input[i]))
			return (0);
	j = -1;
	while (input[++j])
		checkerFill(word, input, checker, input[j], j);
	return (1);
}

/**
 * @brief	Get the input from the user.
 * 
 * @param	const int	fd The file descriptor to read from.
 * 
 * @return char* The input string.
 */
__attribute__((hot, malloc)) char	*get_input(
	const int fd
)
{
	char	input[64];
	ssize_t	bytes_read;
	char	*result;

	printf("Enter a word: ");
	fflush(stdout);
	bytes_read = read(fd, input, 63);
	if (bytes_read > 0 && bytes_read < 64)
	{
		input[bytes_read] = '\0';
		if (input[bytes_read - 1] == '\n')
			input[bytes_read - 1] = '\0';
	}
	result = ft_strdup(input);
	return (result);
}
