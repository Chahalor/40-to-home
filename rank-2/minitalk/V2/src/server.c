/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:56:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/03 15:47:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#if BUFF_MODE == 0

__attribute__((hot)) void	manager(int val)
{
	static char	buff[BUFF_SIZE] = {0};
	static int	i = 0;
	static int	bit = 0;

	buff[i] <<= 1;
	buff[i] += val;
	if (++bit == 8)
	{
		if (buff[i] == EOT)
		{
			write(1, buff, i);
			i = 0;
			ft_memset(buff, 0, BUFF_SIZE);
		}
		else
			++i;
		bit = 0;
	}
	if (i == BUFF_SIZE)
	{
		write(1, buff, BUFF_SIZE);
		i = 0;
	}
}

#else

void	manager(int val)
{
	static char	*buff = NULL;
	static int	nb_alloc = 0;
	static int	i = 0;
	static int	bit = 0;
	char	*tmp;

	if (!buff)
	{
		buff = (char *)malloc(BUFF_SIZE * sizeof(char));
		if (!buff)
			return ;
		nb_alloc = 1;
	}
	buff[i] <<= 1;
	buff[i] += val;
	if (++bit == 8)
	{
		if (buff[i] == EOT)
		{
			write(1, buff, i);
			free(buff);
			i = 0;
			buff = NULL;
			nb_alloc = 0;
		}
		else
			++i;
		bit = 0;
	}
	if (i == nb_alloc * BUFF_SIZE && buff)
	{
		tmp = buff;
		buff = (char *)malloc(++nb_alloc * BUFF_SIZE);
		if (!buff)
			return ;
		ft_memcpy(buff, tmp, (nb_alloc - 1) * BUFF_SIZE);
		free(tmp);
	}
}
#endif

__attribute__((hot)) void	handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	manager(signal == SIGUSR2);
	kill(info->si_pid, SIGUSR1);
}

__attribute__((unused, cold)) int	setup_signal(
	void (*hand)(int, siginfo_t *, void *))
{
	const struct sigaction	sa = {.sa_flags = SA_SIGINFO | SA_RESTART,
		.sa_sigaction = hand};

	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		return (1);
	else
		return (0);
}

/**
 * @todo: add the args handler to handler the different modes of the server
 */
int	main(void)
{
	int	setup_status;

	ft_printf("PID: %d \n", getpid());
	setup_status = setup_signal(handler);
	if (setup_status)
		exiting(errno, "setup_signal");
	while (1)
		pause();
	return (0);
}
