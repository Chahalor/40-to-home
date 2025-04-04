/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:54:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 09:09:06 by nduvoid          ###   ########.fr       */
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

/** */
__attribute__((malloc)) void	*safe_alloc(const size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		ft_exit(errno, RED "Error: " YELLOW __func__ ": " \
			RESET "Memory allocation failed\n");
	return (ptr);
}

#pragma endregion	/* Functions */