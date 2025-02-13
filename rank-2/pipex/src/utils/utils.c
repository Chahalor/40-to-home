/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:04:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 10:37:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interne/_utils.h"

/**
 * @brief Exit the program with a message and a pointer
 *  to free what given to ptr
 * 
 * @param exit_code The exit code
 * @param msg The message to print
 * @param ptr The pointer to free
 * @param f The function to free the pointer
 * 
 * @note this is an exit point
 */
__attribute__((cold, unused, noreturn)) void	exiting(const int exit_code,
	char *msg, void *ptr, void *(*f)())
{
	if (f)
		f(ptr);
	if (msg)
		perror(msg);
	exit(exit_code);
}

/**
 * @brief Get the value of an environment variable
 * 
 * @param envp The environment variables
 * @param target The target variable
 * 
 * @return char* The value of the target variable
 * 
 * @note allocate the return value with malloc
 */
__attribute__((cold, unused)) char	*ft_getenv(const char *envp[],
	const char *target)
{
	char	*path;

	while (*envp && ft_strncmp(*envp, target, ft_strlen(target)) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	path = ft_strdup(*envp + ft_strlen(target) + 1);
	if (!path)
		exiting(malloc_error, "Malloc error", NULL, NULL);
	return (path);
}
