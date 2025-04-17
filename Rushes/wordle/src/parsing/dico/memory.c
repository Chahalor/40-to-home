/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:58:31 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 17:27:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"

/* Internal */
// #include "_dico.h"
#include "dico.h"
#include "utils.h"

/* Modules  */
	//...

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Hashes a word using the djb2 algorithm.
 * 
 * @param	char	*str The word to hash.
 * 
 * @return	unsigned int The hash value of the word.
 * 
 * @note Hash the word using the djb2 algorithm.
 * 
 * why 5381 ? magic number found by smarter people.
 * 
 * why hash << 5 ? because ti hash * 33 but faster.
 * 
 * and why hash time 33 ? for the same reason as 5381.
 */
__attribute__((hot, const)) static unsigned int	hash_word(
	const char *restrict str
)
{
	register unsigned int	hash = 5381;
	register int			c;

	if (!str)
		return (-1);
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash % MAP_SIZE);
}

/**
 * @brief	Inserts a word into the dictionary.
 * 
 * @param	t_dico2	*restrict dico The dictionary to insert the word into.
 * 
 * @param	const char	*restrict word The word to insert.
 */
__attribute__((hot)) void	insert_word(
	t_dico2 *restrict dico,
	const char *restrict word
)
{
	const unsigned int	index = hash_word(word);

	t_word	*new = (t_word *)malloc(sizeof(t_word));
	new->word = ft_strdup(word);
	new->next = dico->table[index];
	dico->table[index] = new;
	++dico->size;
}

/**
 * @brief	Checks if a word exists in the dictionary.
 * 
 * @param	t_dico2	*restrict dico The dictionary to check.
 * 
 * @param	const char	*restrict word The word to check.
 * 
 * @return	t_bool TRUE if the word exists, FALSE otherwise.
 */
__attribute__((hot)) t_bool	word_exists(
	t_dico2 *restrict dico,
	const char *restrict word
)
{
	if (!word)
		return (FALSE);

	const unsigned int	index = hash_word(word);
	t_word				*entry = dico->table[index];

	while (entry)
	{
		if (ft_strcmp(entry->word, word) == 0)
			return (TRUE);
		entry = entry->next;
	}
	return (FALSE);
}
/**
 * @brief	Loads the dictionary from a file.
 * 
 * @param	const char	*restrict filepath The path to the dictionary file.
 * 
 * @return	t_dico2* A pointer to the dictionary structure.
 */
__attribute__((cold, malloc)) t_dico2	*load_dico(
	const char *restrict filepath
)
{
	t_dico2	*dico = (t_dico2 *)calloc(1, sizeof(t_dico2));
	FILE	*fp = fopen(filepath, "r");
	char	buffer[128];

	if (!fp)
		return NULL;

	while (fgets(buffer, sizeof(buffer), fp))
	{
		buffer[strcspn(buffer, "\n")] = 0;
		insert_word(dico, buffer);
	}
	fclose(fp);
	return dico;
}

/**
 * @brief	Frees the memory allocated for the dictionary.
 * 
 * @param	t_dico2	*restrict dico The dictionary to free.
 * 
 * @return	void
 */
__attribute__((cold)) void	free_dico(
	t_dico2 *restrict dico
)
{
	register int	i;

	i = -1;
	while (++i < MAP_SIZE)
	{
		if (!dico || !dico->table[i])
			continue;
		t_word *entry = dico->table[i];
		while (entry)
		{
			t_word *tmp = entry;
			entry = entry->next;
			free(tmp->word);
			free(tmp);
		}
	}
	free(dico);
}

#pragma endregion Functions