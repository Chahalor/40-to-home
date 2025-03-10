/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:21:34 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 08:48:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "config.h"
#include "struct.h"
#include "cryptography.h"

/**
 * @brief this function manages the sending of the message to the server.
 * 
 * @param mode the mode of the function
 * @param msg the message to send
 * 
 * 
 * @note: this function as two modes:
 * 
 * - alloc: copy the message ptr to the buffer ptr
 * 
 * - send: send the message to the server
*/
__attribute__((hot)) void	manager_rc4(const t_mode mode, char *msg)
{
	static char	*buff = NULL;
	static int	i = 0;
	static int	bit = 0;

	if (__builtin_expected(mode == send, expected))
	{
		if (i == BUFF_SIZE)
		
		else if (kill(g_pid, SIGUSR1 + 2 * (buff[i] >> (7 - bit) & 1)))
			exit(0);
		if (++bit == 8)
		{
			bit = 0;
			++i;
		}
	}
	else if (mode == alloc)
	{
		buff = msg;
		i = 0;
		bit = 0;
	}
	else
		return ;
}
