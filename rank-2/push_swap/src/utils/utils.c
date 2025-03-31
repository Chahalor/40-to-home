/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:22:11 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 13:22:05 by nduvoid          ###   ########.fr       */
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

	new_ptr = malloc(new);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

#pragma endregion	/* Functions */