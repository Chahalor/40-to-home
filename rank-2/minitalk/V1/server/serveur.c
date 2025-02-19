/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:10:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/17 09:47:29 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
#include "libft.h"
#include <unistd.h>

// Global
//...

// Modules
#include "Translator.h"
#include "Talker.h"
#include "Listener.h"

/* -----| Functions |----- */

__attribute__((cold, unused, noreturn)) void	exiting(int exitcode, char *msg, void *ptr)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (ptr)
		free(ptr);
	exit(exitcode);
}

/** */
int	main(void)
{
	if (!setup_signal())
		return (err_signal);
	ft_printf("serveur PID: %d \n", getpid());
	while (1)
	{
		pause();
	}
}
