/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:04:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 15:12:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interne/i_utils.h"

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
