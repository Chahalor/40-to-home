/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/14 14:54:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
#include "interne/_Listener.h"

/* -----| Functions |----- */

/** */
__attribute__((hot)) void	signal_handler(int signum, siginfo_t *siginfo,
	void *context)
{
	static int	count = 0;
	static int	buffer[HEAR_BUFF] = {0};

	(void)siginfo;
	(void)context;
	if (signum == SIGUSR1)
		buffer[count++] = 0;
	else if (signum == SIGUSR2)
		buffer[count++] = 1;
	if (count == 1023 || is_EOT(buffer, count))
	{
		translator(buffer, count);	// @todo
		ft_memset(buffer, 0, HEAR_BUFF);
		count = 0;
	}
}

/** */
__attribute__((cold, unused)) t_bool	setup_signal(void)
{
	struct sigaction	handler;

	handler.sa_sigaction = signal_handler;
	sigemptyset(&handler.sa_mask);
	if (sigaction(SIGUSR1, &handler, NULL) == -1)
		return (FALSE);
	if (sigaction(SIGUSR2, &handler, NULL) == -1)
		return (FALSE);
	return (TRUE);
}
