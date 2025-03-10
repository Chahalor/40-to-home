/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:03:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 15:37:12 by nduvoid          ###   ########.fr       */
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
 * - alloc: copy the message ptr to the g_client.msger ptr
 * 
 * - send: send the message to the server
*/
__attribute__((hot)) void	manager(void)
{
	static int	i = 0;
	static int	bit = 0;

	if (!g_client.msg[i] && kill(g_client.server_pid, SIGUSR1))
		exiting(1, "kill: unable to send signal");
	else if (kill(g_client.server_pid, SIGUSR1 + 2 * (g_client.msg[i] \
		>> (7 - bit) & 1)))
		exiting(1, "kill: unable to send signal");
	else if (++bit == 8)
	{
		bit = 0;
		++i;
	}
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
		manager();
	else
		exit(0);
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
		manager();
	else
	{
		ft_printf("message successfully delivered\n");
		exit(0);
	}
}

#endif	/* BONUS */

/**
 * @brief this function parse the arguments of the program.
 * 
 * @param argc the number of arguments
 * @param argv the arguments
 * 
 * @return t_args the parsed arguments
 */
__attribute__((unused, cold)) t_args	parse_args(int argc, char *argv[])
{
	t_args	args;

	if (argc != 3)
	{
		args.err = 1;
		return (args);
	}
	args.pid = ft_atoi(argv[1]);
	if (args.pid < 0)
	{
		args.err = 1;
		return (args);
	}
	args.name = ft_strdup("RED IS SUS");
	args.msg = argv[2];
	args.err = 0;
	return (args);
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
		.sa_sigaction = handler, .sa_mask = {0}};

	if (args.err)
		exiting(args.err, "parse_args: invalid arguments");
	g_client.server_pid = args.pid;
	g_client.name = args.name;
	g_client.msg = args.msg;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		exiting(errno, "client: sigaction: unable to setup signal handler");
	else if (kill(g_client.server_pid, 0))
		exiting(errno, "kill: no such process");
	// kill(g_client.server_pid, SIGUSR1);
	manager();
	while (1)
		pause();
	return (0);
}
