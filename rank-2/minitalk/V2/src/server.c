/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:56:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 14:34:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

__attribute__((hot)) void	handler(int signal, siginfo_t *info, void *context)
{
	static char	buffer[1024] = {0};
	static int	pos = 0;
	static int	bit = 0;

	(void)info;
	(void)context;
	buffer[pos] = (buffer[pos] << 1) | (signal != SIGUSR1);
	if (++bit == 7)
		++pos;
	if (pos == 1024 || buffer[pos - 1] == EOT)
	{
		write(1, buffer, pos);
		pos = 0;
	}
	else
		bit = 0;
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

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	if (setup_signal())
		exiting(errno, "setup_signal");
	while (1)
		pause();
	return (0);
}
