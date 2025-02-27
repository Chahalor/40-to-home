/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:03:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 14:28:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

__attribute__((cold)) void	send_EOT(const int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(SLEEP_TIME);
	}
}

/** */
__attribute__((hot)) void	send_msg(char *msg, const int pid)
{
	int	i;
	int	bit;
	int	ret;

	i = -1;
	while (msg[++i])
	{
		bit = 0;
		while (msg[i])
		{
			ft_printf("%d ", msg[i] >> 7 & 1);	//rm
			if (kill(pid, SIGUSR1 + 2 * (msg[i] >> 7 & 1)))
				return ;
			msg[i] <<= 1;
			++bit;
			usleep(SLEEP_TIME);
		}
		while (bit++ < 8)
		{
			ret = kill(pid, SIGUSR1);
			ft_printf("0");	//rm
			if (ret)
				return ;
			usleep(SLEEP_TIME);
		}
		ft_printf(" ");	//rm
	}
	send_EOT(pid);
}

__attribute__((cold)) void	handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		ft_printf("Message received\n");
	else if (signal == SIGUSR2)
		ft_printf("Message not received\n");
}

__attribute__((unused, cold)) int	setup_signal(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		return (1);
	else
		return (0);
}

__attribute__((unused, cold)) t_args	parse_args(int argc, char *argv[])
{
	t_args	args;

	if (argc != 3)
	{
		args.err = EINVAL;
		return (args);
	}
	args.pid = ft_atoi(argv[1]);
	if (args.pid <= 0)
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
	t_args	args;

	args = parse_args(argc, argv);
	if (args.err)
		exiting(args.err, "parse_args:");
	setup_signal();
	send_msg(args.msg, args.pid);
	return (0);
}
