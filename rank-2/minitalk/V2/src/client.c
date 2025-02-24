/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:26:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/24 10:07:35 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <errno.h>

__attribute__((cold)) void	send_size(int pid, char *msg)
{
	static int	size = 0;

	if (msg)
		size = ft_strlen(msg);
	ft_printf("size: %d\n", size);
	kill(pid, bit_to_sig((size >> 31) & 1));
	size <<= 1;
}

__attribute__((hot)) void	send_message(int pid, char *message)
{
	static char	*msg = NULL;
	static int	i = 0;

	if (message)
		msg = message;
	if (msg[i] >> 1)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	msg[i] <<= 1;
	if (!msg[i])
		++i;
	if (!msg[i])
		send_message(pid, "\4");
}

__attribute__((hot)) void	client_signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	ft_printf("signum: %d\n", signum);
	if (signum == SIGUSR1)
		send_size(info->si_pid, NULL);
	else if (signum == SIGUSR2)
		send_message(info->si_pid, NULL);
}

__attribute__((cold, unused)) void	setup_signal(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = client_signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		exiting(EINVAL, "Usage: ./client [PID] [Message]\n");
	pid = ft_atoi(argv[1]);
	ft_printf("pid: %d\n", getpid());
	if (pid < 1)
		exiting(EINVAL, "Invalid PID\n");
	setup_signal();
	send_size(pid, (argv[2]));
}
