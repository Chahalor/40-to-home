/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:03:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/03 15:44:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**  */
int	g_pid = 0;

int	killing(const int pid, const int signal)
{
	ft_printf("%d", signal == SIGUSR2);
	return (kill(pid, signal));
}

/** */
__attribute__((hot)) void	manager(t_mode mode, char *msg)
{
	static int	i = 0;
	static char	*buff = NULL;
	static int	bit = 0;

	if (mode == alloc)
		buff = msg;
	else if (mode == send)
	{
		if (!buff[i])
			killing(g_pid, SIGUSR1);
		else if (killing(g_pid, SIGUSR1 + 2 * (buff[i] >> (7 - bit) & 1)))
			exit(0);
		if (++bit == 8)
		{
			if (!buff[i])
				exit(0);
			bit = 0;
			++i;
		}
	}
}

__attribute__((hot)) void	handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		manager(send, NULL);
	else
		ft_printf("Error: message not received\n");
}

/** */
__attribute__((unused, cold)) t_args	parse_args(int argc, char *argv[])
{
	t_args	args;

	if (argc != 3)
	{
		args.err = EINVAL;
		return (args);
	}
	args.pid = ft_atoi(argv[1]);
	if (args.pid < 0)
	{
		args.err = EINVAL;
		return (args);
	}
	args.msg = argv[2];
	args.err = 0;
	return (args);
}

int	main(int argc, char *argv[])
{
	const t_args			args = parse_args(argc, argv);
	const struct sigaction	sa = {.sa_flags = SA_SIGINFO | SA_RESTART,
		.sa_sigaction = handler, .sa_mask = {0}};

	if (args.err)
		exiting(args.err, "parse_args: invalid arguments");
	g_pid = args.pid;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		exiting(errno, "sigaction: unable to setup signal handler");
	if (kill(g_pid, 0) == -1)
		exiting(errno, "kill: no such process");
	manager(alloc, args.msg);
	manager(send, NULL);
	while (1)
		pause();
	return (0);
}
