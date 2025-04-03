/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:22:11 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:28:20 by nduvoid          ###   ########.fr       */
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

/**
 * @brief: this function exit the program with an error code and a message.
 * 
 * @param error: the error code
 * @param message: the message to print
 * 
 * @return: noreturn
 */
__attribute__((cold, unused, noreturn))
void	exiting(const int error, const char *message)
{
	if (message)
		ft_printf("%s\n", message);
	exit(error);
}

/**
 * @brief: this function frees an array of strings. the array should be
 * terminated by a NULL pointer. if the array is NULL, it does nothing.
 * 
 * @param array: the array to free
 * 
 * @return: void
 */
__attribute__((cold, unused))
void	freeing_array(char **array)
{
	register int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

/**
 * @brief	Allocates memory and checks if the allocation was successful.
 *  if not, it exits the program with an error code.
 * 
 * @param	size	The size of the memory to allocate.
 * 
 * @return	A pointer to the allocated memory.
 */
void	*mallocing(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exiting(21, RED "Error" RESET ": while allocating memory");
	return (ptr);
}

/**
 * @brief	Reallocates memory and copies the old data to the new memory.
 * 
 * @param	ptr	The pointer to the old memory.
 * @param	old	The size of the old memory.
 * @param	new	The size of the new memory.
 */
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