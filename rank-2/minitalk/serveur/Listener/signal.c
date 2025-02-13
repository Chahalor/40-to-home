/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 17:41:34 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
//...

// Global
#include "types.h"
#include "libft.h"

// Modules

#include "interne/_Listener.h"

/* -----| Functions |----- */

/** */
__attribute__((hot)) void	signal_handler(int signum, siginfo_t *siginfo,
	void *context)
{
	static int	count = 0;
	static int	buffer[HEAR_BUFF] = {0};
	
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

void	signal_handler2(int signum, siginfo_t *siginfo, void *context)
{
	static int	count = 0;
	static char	buffer[HEAR_BUFF] = {'\0'};

	if (signum == SIGUSR1)
		buffer[count / 8] = buffer[count] << 1;
	else if (signum == SIGUSR2)
		buffer[count / 8] = (buffer[count] << 1) | 1;
	++count;
	if (count == HEAR_BUFF * 8 - 2)
	{
		ft_printf("%s\n", buffer);
		ft_memset(buffer, 0, HEAR_BUFF);
		count = 0;
	}
}

/** */
__attribute__((cold, unsused)) t_bool	setup_signal()
{
	struct sigaction	handler;

	handler.sa_sigaction = signal_handler2;
	sygemtyset(&handler.sa_mask);
	if (sigaction(SIGUSR1, &handler, NULL) == SIG_ERR)
		return (FALSE);
	if (sigaction(SIGUSR2, &handler, NULL) == SIG_ERR)
		return (FALSE);
	return (TRUE);
}
