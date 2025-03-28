/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:22:11 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/28 12:08:46 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
#include <stdlib.h>

// Global
#include "libft.h"

// Modules
#include "utils.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((cold, unused, noreturn))
void	exiting(const int error, const char *message)
{
	if (message)
	{
		if (error)
			ft_printf(RED "%s\n" RESET, message);
		else
			ft_printf("%s\n", message);
	}
	exit(error);
}

/** */
__attribute__((hot, malloc))
void	*reallocing(void *ptr, const size_t old, const size_t new)
{
	void	*new_ptr;

	new_ptr = malloc(new);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

#pragma endregion	/* Functions */