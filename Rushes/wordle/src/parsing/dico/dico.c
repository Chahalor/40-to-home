/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dico.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:01:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/16 15:50:21 by nduvoid          ###   ########.fr       */
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
 * @brief	Gets the dictionary information.
 * 
 * @param	char	Path The path to the dictionary file.
 * 
 * @return	t_dico	A structure containing the size of the dictionary and an error code.
*/
__attribute__((cold)) t_dico2	*get_dico_info(
	const char *path
)
{
	t_dico2	*dico = NULL;

	if (!path)
	{
		perror("get_dico_info(): path is NULL");
		return (NULL);
	}
	dico = load_dico(path);
	if (!dico)
	{
		perror("get_dico_info(): load_dico() failed");
		return (NULL);
	}
	return (dico);
}

#pragma endregion Functions