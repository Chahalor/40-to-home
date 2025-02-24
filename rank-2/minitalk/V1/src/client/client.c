/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:12:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/24 15:58:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
#include <stdlib.h>
#include "libft.h"
#include <signal.h>

// Global
#include "types.h"
#include "config.h"
#include "struct.h"

// Modules
// #include "Hear.h"
#include "Translator.h"
#include "Talker.h"
#include "utils.h"

/* -----| Functions |----- */

void	parsing_args(int argc, const char *argv[], t_client *client)
{
	if (argc != 3 || !argv || !client)
		exiting(1, "Arguments invalides\n", NULL);
	client->server_pid = ft_atoi(argv[1]);
	if (client->server_pid <= 0)
		exiting(1, "Invalid pid\n", NULL);
	client->msg = (char *)argv[2];
	client->hear = parsing_args;
	client->translator = translator;
	client->talker = NULL;
	client->callback = NULL;
}

__attribute__((hot)) void	signal_handler(int signum, siginfo_t *siginfo,
	void *context)
{
	(void)siginfo;
	(void)context;
	if (!DEBUG)
		return ;
	if (signum == SIGUSR1)
		ft_printf("0");
	else if (signum == SIGUSR2)
		ft_printf("1");
}

__attribute__((cold, unused)) t_bool	setup_signal(void *ptr)
{
	struct sigaction	handler;

	handler.sa_sigaction = signal_handler;
	handler.sa_flags = SA_SIGINFO;
	sigemptyset(&handler.sa_mask);
	if (sigaction(SIGUSR1, &handler, NULL) == -1)
		exiting(err_signal, "sigaction error\n", ptr);
	if (sigaction(SIGUSR2, &handler, NULL) == -1)
		exiting(err_signal, "sigaction error\n", ptr);
	return (TRUE);
}

/** */
int	main(int argc, const char *argv[])
{
	t_client	*client;

	client = (t_client *)ft_calloc(1, sizeof(t_client));
	if (argc != 3 || !client)
		exiting(1, "Usage: ./client [pid] [message]\n", NULL);
	parsing_args(argc, argv, client);
	if (client->server_pid == 0)
		exiting(1, "Invalid pid\n", NULL);
	// setup_signal(client);
	client->translator(client->msg, client->server_pid);
	free(client);
	return (0);
}
