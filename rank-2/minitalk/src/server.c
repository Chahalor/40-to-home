/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:56:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/13 09:23:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#if BUFF_MODE == 0

t_server	g_server = {.buff = {0}, .name_client = {0}, .status = name};

/**
 * @brief this function stores the received bits in a buffer, and flushes
 * the buffer when it is full or when the end of transmission is received.
 * 
 * @param val the value of the received signal
 * @param pid the pid of the sender
 * @return void
 * 
 * @note: the buffer is flushed when the end of transmission is received
 * 
 * @example manager(1, 868889, name); -> add the bit 1 to the name buffer
 * @example manager(0, 868889, msg); -> add the bit 0 to the msg buffer
 * @example manager(0, 868889, 3); -> should segfault, or have an strange
 *  memory access
 */
__attribute__((hot)) void	manager(const int val, const int pid,
	const int mode)
{
	char		*buff;
	static int	i = 0;
	static int	bit = 0;

	buff = g_server.buff + BUFF_SIZE * (mode == name);
	buff[i] = (buff[i] << 1) + val;
	if (++bit == 8)
	{
		bit = 0;
		if (buff[i] == EOT)
		{
			g_server.status = (mode == name) * print_name;
			write(1, buff, i * (mode != name));
			i *= (mode == name);
			ft_memset(buff, 0, BUFF_SIZE * (mode != name));
			kill(pid, SIGUSR2);
		}
		i += 1 * (buff[i] != EOT);
	}
	write(1, buff, i * (mode != name) * (i == BUFF_SIZE));
	i *= (i != BUFF_SIZE);
	kill(pid, SIGUSR1);
}

#else

t_server	g_server = {.buff = NULL, .name_client = NULL, .status = name};

/**
 * @brief this function stores the received bits in a heap-allocated buffer,
 * and writes the buffer when it is full or when the end of transmission is
 * received.
 * 
 * @param val the value of the received signal
 * @param pid the pid of the sender
 * @return void
 * 
 * @note the buffer is not freed when the end of transmission is received
 * 
 * @example manager(1, 868889, name); -> add the bit 1 to the name buffer
 * @example manager(0, 868889, msg); -> add the bit 0 to the msg buffer
 * @example manager(0, 868889, 3); -> should segfault, or have an strange
 *  memory access
 */
__attribute__((hot)) void	manager(const int val, const int pid,
	const int mode)
{
	char		*buff;
	char		**tmp;
	static int	nb_alloc = 0;
	static int	i = 0;
	static int	bit = 0;

	tmp = &g_server.buff + (mode == name);
	if (i == nb_alloc * BUFF_SIZE || !*tmp)
		*tmp = (char *)reallocator(*tmp, &nb_alloc);
	buff = *tmp;
	buff[i] = (buff[i] << 1) + val;
	if (++bit == 8)
	{
		bit = 0;
		if (buff[i] == EOT)
		{
			g_server.status = (mode == name) * print_name;
			write(1, buff, i * (mode != name));
			(kill(pid, SIGUSR2), i = 0, nb_alloc = 0);
		}
		else
			++i;
	}
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
 * @note: the function is called in a speparate thread when a signal is received
 */
__attribute__((hot)) void	handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (g_server.status == print_name)
	{
		if (g_server.name_client[0] == 0)
			ft_printf(GREEN "\n[%d] : \n" RESET, info->si_pid);
		else
			ft_printf(GREEN "\n[%s] : \n" RESET, g_server.name_client);
		g_server.status = msg;
	}
	manager(signal == SIGUSR2, info->si_pid, g_server.status);
}

/**
 * @author: nduvoid <nduvoid@student.42mulhouse.fr>
 * @date: 2025/03/13
 * 
 * @brief this function is the main function of the server
 * 
 * @param argc the number of arguments
 * @param argv the arguments
 * 
 * @return int
 */
int	main(int argc, char *argv[])
{
	const struct sigaction	sa = {.sa_flags = SA_SIGINFO | SA_RESTART,
		.sa_sigaction = handler};
	const struct sigaction	sa2 = {.sa_flags = SA_SIGINFO,
		.sa_sigaction = cleanup_server};

	parse_args_server(argc, argv);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		exiting(errno, "server: sigaction: unable to setup signal handler");
	else if (sigaction(SIGINT, &sa2, NULL) || sigaction(SIGQUIT, &sa2, NULL))
		exiting(errno, "server: sigaction: unable to setup signal handler");
	ft_printf("PID: %d \n", getpid());
	while (1)
		pause();
	return (0);
}
