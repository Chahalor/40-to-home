/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:20:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/26 12:01:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Modules |----- */
#include "interne/_Translator.h"

/* -----| Functions |----- */

__attribute__((cold)) void	send_EOT(int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			return ;
		usleep(1);
	}
}

/** */
__attribute__((hot)) t_bool	translator(char *msg, const int pid)
{
	int	i;
	int	bit;
	int	ret;

	i = -1;
	while (msg[++i])
	{
		bit = 0;
		while (msg[i])
		{
			ft_printf("%d", msg[i] >> 7 & 1);
			if (msg[i] >> 7 & 1)
				ret = kill(pid, SIGUSR2);
			else
				ret = kill(pid, SIGUSR1);
			if (ret)
				return (FALSE);
			msg[i] <<= 1;
			++bit;
			usleep(SLEEP_TIME);
		}
		while (bit++ % 8)
		{
			ret = kill(pid, SIGUSR1);
			ft_printf("0");	//rm
			if (ret)
				return (FALSE);
			usleep(SLEEP_TIME);
		}
		ft_printf(" ");
	}
	send_EOT(pid);
	return (TRUE);
}
