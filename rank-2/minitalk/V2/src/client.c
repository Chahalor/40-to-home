/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:26:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/19 11:53:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief this function will send bit by bit the message to the server. The
 * function wait its next call to send the next bit
 */
void	send_message(const int pid, char *msg)
{
	static char	*message = NULL;
	static int	count = 0;
	static int	index = 0;

	if (msg)
		message = msg;
	if (pid <= 0 || !message)
		exit(err_pid | err_arg);
	if (msg[index] >> count & 1)
		// kill(pid, SIGUSR2);
		ft_printf("1");
	else
		// kill(pid, SIGUSR1);
		ft_printf("0");
	++count;
	if (count == 32)
	{
		++index;
		count = 0;
	}
}

/** */
void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)	
		send_message(info->si_pid, NULL);
	else if (sig == SIGUSR2)
	{
		if (BONUS == 1)
			ft_printf("Message snd with succes\n");
		exit(err_none);
	}
}

/** */
__attribute__((cold, unused)) int	setup_signal(void)
{
	struct sigaction	handler;

	handler.sa_sigaction = signal_handler;
	sigemptyset(&handler.sa_mask);
	if (sigaction(SIGUSR1, &handler, NULL) == -1)
		return (0);
	if (sigaction(SIGUSR2, &handler, NULL) == -1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s [PID] [message]\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	setup_signal();
	send_message(pid, argv[2]);
	while (1)
		// pause();
		send_message(pid, NULL);
	return (0);
}
