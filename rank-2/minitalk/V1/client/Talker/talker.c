/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:26:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/14 11:29:55 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
#include <stdlib.h>
#include <stdio.h>	//rm

// Global
#include "types.h"
#include "config.h"
#include "struct.h"

// Modules
#include "interne/_Talker.h"

/* -----| Functions |----- */

__attribute__((cold)) t_bool	talker(const int serv_pid, t_byte *msg)
{
	t_byte	*tmp;
	int		i;

	if (!msg)
	return (FALSE);
	tmp = msg;
	i = -1;
	while (msg[++i] != 2)
	{
		if (msg[i] == 0)
		{
			if (kill(serv_pid, SIGUSR1) == -1)
				return (free(tmp), FALSE);
		}
		else if (msg[i] == 1)
		{
			if (kill(serv_pid, SIGUSR2) == -1)
				return (free(tmp), FALSE);
		}
		else
			printf("msg[i]: %d\n", msg[i]);	//rm
		printf("i: %d\n", i);	//rm
	}
	free(tmp);
	return (TRUE);
}

void	sig_bit(int bit, int pid)
{
	kill(12 -(bit * 2), pid);
}
