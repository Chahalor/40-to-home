/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:12:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/19 09:20:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
// Libs
#include <stdlib.h>
#include "libft.h"

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
	client->msg = (char *)argv[2];
	client->hear = parsing_args;
	client->translator = translator;
	client->talker = talker;
	client->callback = NULL;
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
		exiting(1, "client: parsing_args: Invalid pid\n", NULL);
	client->translator(client->msg, client->server_pid);
	free(client);
	return (0);
}
