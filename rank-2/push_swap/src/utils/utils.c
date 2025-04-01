/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:22:11 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/01 15:58:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
//...

// Global
#include "_utils.h"

// Modules
//...

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((cold, unused, noreturn))
void	exiting(const int error, const char *message)
{
	if (message)
		ft_printf("%s\n", message);
	exit(error);
}

/** */
__attribute__((cold, unused))
void	freeing_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	*mallocing(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exiting(21, RED "Error" RESET ": while allocating memory");
	return (ptr);
}

/** */
__attribute__((hot, malloc))
void	*reallocing(void *ptr, const size_t old, const size_t new)
{
	void	*new_ptr;

	if (new == 0)
		return (free(ptr), NULL);
	else if (ptr == NULL)
		return (mallocing(new));
	else if (old == new)
		return (ptr);
	new_ptr = mallocing(new);
	ft_memcpy(new_ptr, ptr, old * (old < new) + new * (old > new));
	free(ptr);
	return (new_ptr);
}

#pragma endregion	/* Functions */