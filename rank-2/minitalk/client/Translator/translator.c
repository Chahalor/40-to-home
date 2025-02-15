/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:20:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/15 13:20:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Modules |----- */
#include "interne/_Translator.h"

/* -----| Functions |----- */

__attribute__((unused)) static void send_EOT(const int pid)
{
	kill(pid, SIGUSR1);
	usleep(1);
	kill(pid, SIGUSR1);
	usleep(1);
	kill(pid, SIGUSR1);
	usleep(1);
}

/** */
__attribute__((cold)) t_bool	translator(const char *msg, const int pid)
{
	int	i;
	int	bit;
	int	ret;

	i = -1;
	while (msg[++i])
	{
		bit = -1;
		while (++bit < 8)
		{
			if (msg[i] >> bit & 1)
				ret = kill(pid, SIGUSR2);
			else
				ret = kill(pid, SIGUSR1);
			if (ret == -1)
				return (FALSE);
			usleep(1);
		}
	}
	// send_EOT(pid);
	return (TRUE);
}
