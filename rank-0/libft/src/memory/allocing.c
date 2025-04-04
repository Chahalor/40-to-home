/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:54:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 09:52:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */
	//...

/* Global */
	//...

/* Modules */
#include "memory.h"
#include "colors.h"

#pragma endregion	/* Includes */
#pragma region "Functions"

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each
 * and returns a pointer to the allocated memory.
 * 
 * @param nmemb Number of elements.
 * @param size Size of each element.
 * @return void* Pointer to the allocated memory.
 */
__attribute__((malloc)) void	*ft_calloc(const size_t nmemb, const size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((nmemb * size) / nmemb != size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, '\0', size * nmemb);
	return (arr);
}

/**
 * @brief Allocates memory of size bytes and returns a pointer to the allocated
 *  memory. In case of failure, it exits the program with an error message.
 * 
 * @param size Size of memory to allocate.
 * 
 * @return void* Pointer to the allocated memory.
 */
__attribute__((malloc)) void	*safe_alloc(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_exit(errno, RED "Error: " YELLOW __func__ ": " \
			RESET "Memory allocation failed\n");
	return (ptr);
}

/**
 * @brief Allocates memory of new size bytes, copy the data from ptr, free it
 *  and returns a pointer to the allocated memory. In case of failure, returns
 *  NULL.
 * 
 * @param old Size of the old memory.
 * @param new Size of the new memory.
 * @param ptr Pointer to the old memory.
 * 
 * @return void* Pointer to the allocated memory. Or NULL if allocation fails.
 */
__attribute__((malloc)) void	*ft_realloc(const size_t old, const size_t new, void *ptr)
{
	void	*new_ptr;

	if (new == 0)
		return (free(ptr), NULL);
	else if (old == new)
		return (ptr);
	new_ptr = malloc(new);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old * (old < new) + new * (old >= new));
	free(ptr);
	return (new_ptr);
}

/**
 * @brief Frees the memory pointed to by ptr and sets it to NULL.
 * 
 * @param ptr Pointer to the memory to free.
 * 
 * @return void
 */
__attribute__((always_inline)) void	ft_free(void **ptr)
{
	if (ptr && *ptr)
		free(ptr);
	*ptr = NULL;
}

#pragma endregion	/* Functions */