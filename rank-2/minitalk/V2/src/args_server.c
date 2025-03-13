/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:08:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/13 09:38:08 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#if (BUFF_MODE == 1)

/**
 * @brief this function is a destructor that is called when the program exits.
 * 
 * @param signal the signal received
 * @param info the info of the signal
 * @param context the context of the signal
 * 
 * @return void
 * 
 * @note: this function is also called when quit signal is received
 */
__attribute__((destructor)) void	cleanup_server(int signal, siginfo_t *info,
	void *context)
{
	extern t_server	g_server;

	(void)info;
	(void)context;
	if (signal == SIGCHLD || signal == SIGWINCH)
		return ;
	else if (signal == SIGINT)
		exiting(0, "\n");
	else if (BUFF_MODE == 0)
		return ;
	if (g_server.buff)
	{
		free(g_server.buff);
		g_server.buff = NULL;
	}
	if (g_server.name_client)
	{
		free(g_server.name_client);
		g_server.name_client = NULL;
	}
	exit(errno);
}

#else

/**
 * @brief this function is called when quit signal is received or as a
 *  destructor.
 * 
 * @param signal the signal received
 * @param info the info of the signal
 * @param context the context of the signal
 * 
 * @return void
 */
void	cleanup_server(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGCHLD || signal == SIGWINCH)
		return ;
	else if (signal == SIGINT)
		exiting(0, "\n");
	else
		exit(errno);
}

#endif

/**
 * @brief this function shows the help message and exits the program.
 * 
 * @param void
 * 
 * @return void
 */
__attribute__((unused, cold, noreturn, always_inline)) static inline void
	show_help(void)
{
	ft_printf("usage: ./server [options]\n");
	ft_printf("options:\n");
	ft_printf("  -h, --help\t\tshow this help message and exit\n");
	ft_printf("\nExemple:\n");
	ft_printf("  ./server\n");
	ft_printf("  ./server -h\n");
	exit(0);
}

/**
 * @brief this function parses the arguments of the server.
 * 
 * @param argc the number of arguments
 * @param argv the arguments
 * 
 * @return void
 */
__attribute__((unused, cold)) void	parse_args_server(int argc,
	char *argv[])
{
	if (argc <= 1)
		return ;
	if (argv[1][0] == '-')
	{
		if (argv[1][1] == '-')
		{
			if (ft_strncmp(argv[1], "--help", 6) == 0)
				show_help();
		}
		else if (argv[1][1] == 'h')
			show_help();
		else
			exiting(einval, "usage: ./server [options]");
	}
}
