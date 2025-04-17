/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:01:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/15 13:04:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"
#include <fcntl.h>	// @todo:  move to an header
#include <unistd.h>	// @todo:  move to an header

/* Internal */
// #include "_dico.h"
#include "dico.h"

/* Modules  */
	//...

#pragma endregion Headers
#pragma region Functions

/**
 * @brief	Reads the dictionary file and counts the number of words.
 * 
 * @param	path	Path The path to the dictionary file.
 * 
 * @return	t_dico		A structure containing the size of the dictionary and an error code.
*/
__attribute__((always_inline, used)) static inline t_dico	dico_read_info(
	const char *path
)
{
	t_dico			dico = {NULL, 0, DICO_NO_ERROR};
	int				fd = -1;
	char			buff[64] = {0};
	int				ret = 0;
	register int	i = 0;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ((t_dico){NULL, 0, DICO_NO_WAY_TO_OPEN});
	ret = read(fd, buff, MAX_WORD_SIZE + 1);
	while (ret > 0)
	{
		if (ret == -1)
		{
			close(fd);
			return ((t_dico){NULL, 0, DICO_NO_WAY_TO_OPEN});
		}
		i = -1;
		while (++i < MAX_WORD_SIZE)
		{
			if (buff[i] == '\n')
				dico.size++;
			else if (!is_alpha(buff[i]))
				return ((t_dico){NULL, 0, DICO_INVALID_WORD});
		}
		ret = read(fd, buff, MAX_WORD_SIZE + 1);
	}
	dico.path = (char *)path;
	close(fd);
	return (dico);
}

/**
 * @brief	Gets the dictionary information.
 * 
 * @param	char	Path The path to the dictionary file.
 * 
 * @return	t_dico	A structure containing the size of the dictionary and an error code.
*/
__attribute__((cold)) t_dico	get_dico_info(
	const char *path
)
{
	t_dico	dico;

	if (!path)
		return ((t_dico){NULL, 0, DICO_NO_PATH});
	dico = dico_read_info(path);
	if (dico.error && dico.size == 0)
		return ((t_dico){NULL, 0, DICO_EMPTY});
	return (dico);
}

#pragma endregion Functions