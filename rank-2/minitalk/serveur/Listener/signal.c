/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 14:35:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
//...

// Global
# include "types.h"

// Modules
#include "interne/_Listener.h"

/* -----| Functions |----- */

/** */
__attribute__((hot)) void	signal_handler(int signum, siginfo_t *siginfo,
	void *context)
{
	static int		count = 0;
	static int		buffer[HEAR_BUFF] = {0};
	
	if (signum == SIGUSR1)
		buffer[count++] = 0;
	else if (signum == SIGUSR2)
		buffer[count++] = 1;
	if (count == 1023 || is_end_of_transmission(buffer))
	{
		count = 0;
		// do something with buffer
	}
}

__attribute__((cold, unsused)) t_bool	setup_signal()
{
	if (sigaction(SIGUSR1, signal_handler, NULL) == SIG_ERR)
		return (FALSE);
	if (sigaction(SIGUSR2, signal_handler, NULL) == SIG_ERR)
		return (FALSE);
	return (TRUE);
}
