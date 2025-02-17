/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/17 09:08:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
#include "interne/_Listener.h"

/* -----| Functions |----- */

/** */
__attribute__((unused)) void	signal_handler(int signum, siginfo_t *siginfo,
	void *context)
{
	static int	count = 0;
	static int	buffer[HEAR_BUFF] = {0};

	(void)siginfo;
	(void)context;
	ft_printf("signum: %d\n", signum);
	if (signum == SIGUSR1)
		buffer[count++] = 0;
	else if (signum == SIGUSR2)
		buffer[count++] = 1;
	ft_printf("count: %d\n", count);
	if (count == 1023 || is_EOT(buffer, count))
	{
		translator(buffer, count);	// @todo
		ft_memset(buffer, 0, HEAR_BUFF);
		count = 0;
	}
}

char	reverse_bits(char c)
{
	char	r = 0;
	int		i = 0;

	while (i < 8)
	{
		r = r << 1;
		r = r | (c & 1);
		c = c >> 1;
		++i;
	}
	return (r);
}
//*
int	get_char_size(char c)
{
	int	size = 0;

	while (c >> 1)77
	{
		++size;
		c >>= 1;
	}
	return (size);
}

void	signal_handler2(int signum, siginfo_t *siginfo,
	void *context)
{
	static char	letter = 0;
	static int	count = 0;
	int			size;

	(void)siginfo;
	(void)context;
	if (signum == SIGUSR1)
		letter = (letter << 1) | 0;
	else if (signum == SIGUSR2)
		letter = (letter << 1) | 1;
	++count;
	if (count == 8)
		size = get_char_size(letter);
	{
		letter = reverse_bits(letter);
		write(1, &letter, 1);
		letter = 0;
		count = 0;
	}
}

/** */
__attribute__((cold, unused)) t_bool	setup_signal(void)
{
	struct sigaction	handler;

	handler.sa_sigaction = signal_handler2;
	sigemptyset(&handler.sa_mask);
	if (sigaction(SIGUSR1, &handler, NULL) == -1)
		return (FALSE);
	if (sigaction(SIGUSR2, &handler, NULL) == -1)
		return (FALSE);
	return (TRUE);
}
