/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:56:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 11:33:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#if BUFF_MODE == 0

/**
 * @brief this function stores the received bits in a buffer, and flushes
 * the buffer when it is full or when the end of transmission is received.
 * 
 * @param val the value of the received signal
 * @param pid the pid of the sender
 * @return void
 * 
 * @note: the buffer is flushed when the end of transmission is received
 */
__attribute__((hot)) void	manager(const int val, const int pid)
{
	static char	buff[BUFF_SIZE] = {0};
	static int	i = 0;
	static int	bit = 0;

	buff[i] = (buff[i] << 1) + val;
	if (++bit == 8)
	{
		if (__builtin_expect(buff[i] == EOT, UNEXPECTED))
		{
			write(1, buff, i);
			i = 0;
			ft_memset(buff, 0, BUFF_SIZE);
			kill(pid, SIGUSR2);
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
	kill(pid, SIGUSR1);
}

#else

/**
 * @brief this function stores the received bits in a heap-allocated buffer,
 * and writes the buffer when it is full or when the end of transmission is
 * received.
 * 
 * @param val the value of the received signal
 * @param pid the pid of the sender
 * @return void
 * 
 * @note the buffer is freed when the end of transmission is received
 */
__attribute__((hot)) void	manager(const int val, const int pid)
{
	static char	*buff = NULL;
	static int	nb_alloc = 0;
	static int	i = 0;
	static int	bit = 0;

	if (!buff)
		buff = (char *)allocator(buff, &nb_alloc);
	buff[i] = (buff[i] << 1) + val;
	if (++bit == 8)
	{
		if (__builtin_expect(buff[i] == EOT, UNEXPETED))
		{
			write(1, buff, i);
			(free(buff), buff = NULL, i = 0, nb_alloc = 0);
			kill(pid, SIGUSR2);
		}
		else
			++i;
		bit = 0;
	}
	if (i == nb_alloc * BUFF_SIZE && buff)
		buff = (char *)reallocator(buff, &nb_alloc);
	kill(pid, SIGUSR1);
}
#endif

/**
 * @brief this function handles the signals received from the client.
 * 
 * @param signal the signal received
 * @param info the info of the signal
 * @param context the context of the signal	
 * 
 * @note: the function is called when a signal is received in a speparate
 * thread
 * @note: this function only call the manager function
 */
__attribute__((hot)) void	handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	manager(signal == SIGUSR2, info->si_pid);
}

/**
 * @brief this function setup the signal handler for the server
 * 
 * @param hand the handler function
 * @return int
 * 
 * @note: the function is called when the server is started
 */
__attribute__((unused, cold)) int	setup_signal(
	void (*hand)(int, siginfo_t *, void *))
{
	const struct sigaction	sa = {.sa_flags = SA_SIGINFO | SA_RESTART,
		.sa_sigaction = hand};

	return (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL));
}

/**
 * @brief this function is the main function of the server
 * 
 * @return int
 */
int	main(int argc, const char *argv[])
{
	int				setup_status;
	const t_args	args = parse_args(argc, argv);

	if (args.err)
		exiting(args.err, "parse_args: invalid arguments", NULL);
	else if (setup_signal(handler))
		exiting(errno, "setup_signal", NULL);
	else
	{
		ft_printf("PID: %d \n", getpid());
		while (1)
			pause();
	}
	return (0);
}
