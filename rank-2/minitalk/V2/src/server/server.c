/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:56:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/10 18:05:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/** */
t_server	g_server = {0};

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
		bit = 0;
		if (buff[i] == EOT)
		{
			write(1, buff, i);
			i = 0;
			ft_memset(buff, 0, BUFF_SIZE);
			kill(pid, SIGUSR2);
			g_server.status = 0;
		}
		else
			++i;
	}
	if (i == BUFF_SIZE)
	{
		write(1, buff, BUFF_SIZE);
		i = 0;
	}
	kill(pid, SIGUSR1);
}

__attribute__((hot)) void	manager_name(const int val, const int pid)
{
	static char buff[MAX_NAME_SIZE] = {0};
	static int	i = 0;
	static int	bit = 0;

	buff[i] = (buff[i] << 1) + val;
	if (++bit == 8)
	{
		bit = 0;
		if (buff[i] == '\0' || i + 1 == MAX_NAME_SIZE)
		{
			i = 0;
			ft_memcpy(g_server.client_name, buff, MAX_NAME_SIZE);
			ft_memset(buff, 0, MAX_NAME_SIZE);
			g_server.mode = msg;
			g_server.status = 0;
			kill(pid, SIGUSR1);
		}
		else
			++i;
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
		bit = 0;
		if (buff[i] == EOT)
		{
			write(1, buff, i);
			(free(buff), buff = NULL, i = 0, nb_alloc = 0);
			kill(pid, SIGUSR2);
			g_server.status = 0;
		}
		else
			++i;
	}
	if (i == nb_alloc * BUFF_SIZE && buff)
		buff = (char *)reallocator(buff, &nb_alloc);
	kill(pid, SIGUSR1);
}

#endif	/* BUFF_MODE */

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
	if (!g_server.status)
	{
		if (g_server.client_name[0])
			ft_printf(GREEN "\n[%s]" RESET " : \n", g_server.client_name);
		else
			ft_printf(GREEN "\n[%d]" RESET " : \n", info->si_pid);
		g_server.status = 1;
	}
	if (g_server.mode == msg)
		manager(signal == SIGUSR1, info->si_pid);
	else if (g_server.mode == name)
		manager_name(signal == SIGUSR1, info->si_pid);
	else
		manager(signal == SIGUSR2, info->si_pid);
}

/**
 * @brief this function is the main function of the server
 * 
 * @return int
 */
int	main(void)
{
	const struct sigaction	sa = {.sa_flags = SA_SIGINFO | SA_RESTART,
		.sa_sigaction = handler, .sa_mask = {0}};

	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		exiting(errno, "sigaction");
	ft_printf("PID: %d \n", getpid());
	g_server.status = 1;
	g_server.mode = name;
	while (1)
		pause();
	return (0);
}
