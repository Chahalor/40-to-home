/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:03:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/12 13:48:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**  */
t_client	g_client = {0};

/**
 * @brief this function manages the sending of the message to the server.
 * 
 * @param mode the mode of the function
 * @param msg the message to send
 * 
 * 
 * @note: this function as two modes:
 * 
 * - alloc: copy the message ptr to the buffer ptr
 * 
 * - send: send the message to the server
*/
__attribute__((hot)) void	manager(const t_mode mode, char *msg)
{
	static char	*buff = NULL;
	static int	i = 0;
	static int	bit = 0;

	if (mode == alloc)
		buff = msg;
	else if (mode == send)
	{
		if (!buff[i] && kill(g_client.pid, SIGUSR1))
			exit(0);
		else if (kill(g_client.pid, SIGUSR1 + 2 * (buff[i] >> (7 - bit) & 1)))
			exit(0);
		if (++bit == 8)
		{
			bit = 0;
			++i;
		}
	}
	else
		return ;
}

#if BONUS == 0

/**
 * @brief this function handles the signals received from the server.
 * 
 * @param signal the signal received
 * @param info the info of the signal
 * @param context the context of the signal
 * 
 * @return void
 * 
 * @note: this function print nothing when SIGUSR2 is received
 */
__attribute__((hot)) void	handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		manager(send, NULL);
	else
	{
		if (g_client.status == name)
		{
			g_client.status = msg;
			manager(reset, NULL);
			manager(alloc, g_client.msg);
		}
		else
			exit(0);
	}
}

#else

/**
 * @brief this function handles the signals received from the server.
 * 
 * @param signal the signal received
 * @param info the info of the signal
 * @param context the context of the signal
 * 
 * @return void
 * 
 * @note: this function print a message when SIGUSR2 is received
 */
__attribute__((hot)) void	handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		manager(send, NULL);
	else
	{
		if (g_client.status == name)
		{
			g_client.status = msg;
			manager(reset, NULL);
			manager(alloc, g_client.msg);
		}
		else
		{
			ft_printf("Message succesfully send\n");
			exit(0);
		}
	}
}

#endif

__attribute__((destructor))	void	cleanup(void)
{
	if (g_client.name)
	{
		free(g_client.name);
		g_client.name = NULL;
	}
}

/**
 * @brief this function is the main function of the client
 * 
 * @return int
 */
int	main(int argc, char *argv[])
{
	const t_args			args = parse_args(argc, argv);
	const struct sigaction	sa = {.sa_flags = SA_SIGINFO | SA_RESTART,
		.sa_sigaction = handler};

	if (args.err == einval)
		exiting(args.err, "usage: ./client [options] <pid> <message>");
	g_client = (t_client){.pid = args.pid, .msg = args.msg,
		.name = args.name, .status = msg};
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		exiting(errno, "client: sigaction: unable to setup signal handler");
	if (kill(g_client.pid, 0) == -1)
		exiting(errno, "kill: no such process");
	if (args.name)
	{
		manager(alloc, args.name);
		manager(send, NULL);
		g_client.status = name;
	}
	else
		g_client.status = msg;
	while (1)
		pause();
	return (0);
}
