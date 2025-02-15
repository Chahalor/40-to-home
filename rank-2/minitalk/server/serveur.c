/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:10:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/15 13:14:36 by nduvoid          ###   ########.fr       */
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
	// ft_printf("serveur PID: %d\n", getpid());
	if (!setup_signal())
		return (err_signal);
	ft_printf("serveur PID: %d\n", getpid());
	// int test[4096] = {1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1};
	// char *msg = translator(test, 48);
	// ft_printf("msg: %s\n", msg);
	while (1)
	{
		pause();
	}
}
