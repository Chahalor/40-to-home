/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:03:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 11:25:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "config.h"
#include "struct.h"
#include "cryptography.h"
#include <signal.h>
#include <stdlib.h>

/**  */
int	g_pid = 0;

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

	if (mode == send)
	{
		if (!buff[i] && kill(g_pid, SIGUSR1))
			exiting(0, "client: kill: unable to send the message", NULL);
		else if (kill(g_pid, SIGUSR1 + 2 * (buff[i] >> (7 - bit) & 1)))
			exiting(0, "client: kill: unable to send the message", NULL);
		if (++bit == 8)
		{
			bit = 0;
			++i;
		}
	}
	else if (mode == alloc)
		buff = msg;
	else if (mode == freeing)
	{
		if (buff)
			free(buff);
		buff = NULL;
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
		manager(send, NULL);
	else
	{
		manager(freeing, NULL);
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
		ft_printf("message successfully delivered\n");
		manager(freeing, NULL);
		exit(0);
	}
}

#endif

/**
 * @brief this function is the main function of the client
 * 
 * @return int
 */
int	main(int argc, const char *argv[])
{
	const t_args			args = parse_args(argc, argv);
	const struct sigaction	sa = {.sa_flags = SA_SIGINFO | SA_RESTART,
		.sa_sigaction = handler, .sa_mask = {0}};
	char					*msg;

	if (args.err)
		exiting(args.err, "parse_args: invalid arguments", NULL);
	g_pid = args.pid;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		exiting(0, "client: sigaction: unable to setup signal handler", NULL);
	if (kill(g_pid, 0) == -1)
		exiting(0, "kill: no such process", NULL);
	if (args.key)
	{
		msg = encode_xor(args.msg, args.key);
		if (!msg)
			exiting(0, "client: encode_xor: unable to encode the message", NULL);
	}
	else
		msg = ft_strdup(args.msg);
	manager(alloc, msg);
	manager(send, NULL);
	while (1)
		pause();
	return (0);
}
