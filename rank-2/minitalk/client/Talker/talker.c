/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:26:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 18:33:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
//...

// Global
#include "types.h"
#include "config.h"
#include "struct.h"

// Modules
#include "interne/_Talker.h"

/* -----| Functions |----- */

__attribute__((cold)) t_bool	talker(const int serv_pid, const t_byte *msg)
{
	if (!msg)
		return (FALSE);
	while (*msg)
	{
		if (msg[0] == 0)
			if (kill(serv_pid, SIGUSR1) == -1)
				return (FALSE);
		else if (msg[0] == 1)
			if (kill(serv_pid, SIGUSR2) == -1)
				return (FALSE);
		else
			return (FALSE);
	}
	return (TRUE);
}
