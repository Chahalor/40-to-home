/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inline.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:31:29 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/13 09:38:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief this function exit the programme with the code code (nooo way) 
 * and if any message is given to it print it.
 * 
 * @param code the error code
 * @param msg the msg to print (should not be allocated)
 * 
 * @return no return, this function exit any way
 */
__attribute__((cold, unused, noreturn)) void	exiting(
	const t_error code,
	const char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (code)
		errno = code;
	exit(code);
}

/**
 * @brief this function allocate the buffer to the first size
 * 
 * @param buff the buffer to allocate
 * @param nb_alloc the number of allocation done
 * 
 * @return the new buffer
 */
__attribute__((hot)) void	*allocator(char *buff, int *nb_alloc)
{
	buff = (char *)malloc(++(*nb_alloc) * BUFF_SIZE);
	if (!buff)
		exiting(enomen, "Error: malloc failed\n");
	ft_memset(buff, 0, BUFF_SIZE * *nb_alloc);
	return (buff);
}

/**
 * @brief this function realloc the buffer to the next size
 * 
 * @param buff the buffer to realloc
 * @param nb_alloc the number of allocation done
 * 
 * @return the new buffer
 */
__attribute__((hot, unused)) void	*reallocator(char *buff, int *nb_alloc)
{
	char	*tmp;

	tmp = buff;
	buff = (char *)allocator(buff, nb_alloc);
	ft_memcpy(buff, tmp, (*nb_alloc - 1) * BUFF_SIZE);
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (buff);
}
