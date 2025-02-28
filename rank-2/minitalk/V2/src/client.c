/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:03:40 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/28 17:20:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**  */
t_status	g_status = no_status;

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

__attribute__((hot)) void	handler(int signal, siginfo_t *info, void *context)
{
	char	c;

	(void)context;
	if (g_status == conn)
	{
		if (signal == SIGUSR1)
			g_status = sending;
		else
			g_status = error;
	}
	else if (g_status == sending)
	{
		if (signal == SIGUSR1)
			send_char(info.si_pid, get_char());
		else
			g_status = error;
	}
	
}

__attribute__((unused, cold)) int	connection(const int pid)
{
	struct sigaction	sa;

	g_status = conn;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		return (SIG_ERR);
	return (kill(pid, SIGUSR1));
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
	if (connection(args.pid))
		exiting(SIG_ERR, "connection:");
	while (1)
		pause();
	return (0);
}
