/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:25:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/24 10:05:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	reverse_bits(char c, int size)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ret <<= 1;
		ret |= c & 1;
		c >>= 1;
		++i;
	}
	return (ret);
}

/**
 * @brief Get the number of bits of a char
 * 
 * @note
 * 
 * - if 0xxxxxxx → ASCII 1 bytes.
 * 
 * - if 110xxxxx → UTF-8 2 bytes.
 * 
 * - if 1110xxxx → UTF-8 3 bytes.
 * 
 * - if 11110xxx → UTF-8 4 bytes.
 */
int	get_size(char c)
{
	c = reverse_bits(c, 1);
	if ((c & 0x80) == 0)
		return (1);
	else if ((c & 0xE0) == 0xC0)
		return (2);
	else if ((c & 0xF0) == 0xE0)
		return (3);
	else if ((c & 0xF8) == 0xF0)
		return (4);
	return (1);
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char		*str = NULL;
	static t_bool	is_size = true;
	static int		count = 0;
	static int		i = 0;
	static int		size = 0;

	(void)context;
	if (is_size)
	{
		size = (size << 1) | translate(signum);
		++count;
		if (count == 32)
		{
			is_size = false;
			count = 0;
		}
		ft_printf("killing %d\n", info->si_pid);
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	if (!str)
	{
		str = (char *)ft_calloc(sizeof(char), size + 1);
		if (!str)
			exiting(ENOMEM, "malloc failed\n");
	}
	str[i] = (str[i] << 1) | translate(signum);
	if (!(count % 8))
	{
		size = get_size(str[i]);
		if (count / size == 8)
		{
			str[i] = reverse_bits(str[i - 1], 8);
			++i;
			count = 0;
		}
	}
	if (str[i - 1] == EOT)
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
	}
	kill(info->si_pid, SIGUSR2);
}

void	setup_signal(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(void)
{
	setup_signal();
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}