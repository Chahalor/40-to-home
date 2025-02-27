/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:20:02 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 13:48:43 by nduvoid          ###   ########.fr       */
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
		kill(pid, SIGUSR1);
		usleep(SLEEP_TIME);
	}
}

/** */
__attribute__((hot)) t_bool	translator(char *msg, const int pid)
{
	int	i;
	int	bit;
	int	ret;
	int	nb_sig = 0;

	i = -1;
	while (msg[++i])
	{
		bit = 0;
		while (msg[i])
		{
			ft_printf("%d", msg[i] >> 7 & 1);	//rm
			if (msg[i] >> 7 & 1)
				ret = kill(pid, SIGUSR2);
			else
				ret = kill(pid, SIGUSR1);
			if (ret)
				return (FALSE);
			++nb_sig;
			msg[i] <<= 1;
			++bit;
			usleep(SLEEP_TIME);
		}
		while (bit++ < 8)
		{
			ret = kill(pid, SIGUSR1);
			ft_printf("0");	//rm
			if (ret)
				return (FALSE);
			++nb_sig;
			usleep(SLEEP_TIME);
		}
		ft_printf(" ");	//rm
	}
	send_EOT(pid);
	ft_printf("\nnb_sig: %d", nb_sig + 8);	//rm
	return (TRUE);
}
