/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/17 09:56:21 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
#include "interne/_Listener.h"

/* -----| Functions |----- */

char	reverse_bits(char c, int base)
{
	char	r = 0;
	int		i = 0;

	while (i < 8 * base)
	{
		r = r << 1;
		r = r | (c & 1);
		c = c >> 1;
		++i;
	}
	return (r);
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
int	get_char_header(char c)
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

/**
 * @brief a basic version that work with 1 byte char (ASCII)
 */
void	signal_handler_ascii(int signum, siginfo_t *siginfo,
	void *context)
{
	static char	letter = 0;
	static int	count = 0;

	(void)siginfo;
	(void)context;
	if (signum == SIGUSR1)
		letter = (letter << 1) | 0;
	else if (signum == SIGUSR2)
		letter = (letter << 1) | 1;
	++count;
	if (count >= 8)
	{
		letter = reverse_bits(letter, 1);
		write(1, &letter, 1);
		letter = 0;
		count = 0;
	}
}

__attribute__((hot)) void	signal_handler3(int signum, siginfo_t *siginfo,
	void *context)
{
	static int	count = 0;
	static char	letter = 0;
	int			size = 0;

	(void)siginfo;
	(void)context;
	if (signum == SIGUSR1)
		letter = (letter << 1) | 0;
	else if (signum == SIGUSR2)
		letter = (letter << 1) | 1;
	++count;
	if (count % 8 != 0)
		return ;
	size = get_char_header(letter);
	// ft_printf("size: %d, cout: %d\n", size, count);
	if (count != 8 * size)
		return ;
	letter = reverse_bits(letter, size);
	write(1, &letter, 1);
	letter = 0;
	count = 0;
}

/** */
__attribute__((cold, unused)) t_bool	setup_signal(void)
{
	struct sigaction	handler;

	handler.sa_sigaction = signal_handler3;
	sigemptyset(&handler.sa_mask);
	if (sigaction(SIGUSR1, &handler, NULL) == -1)
		return (FALSE);
	if (sigaction(SIGUSR2, &handler, NULL) == -1)
		return (FALSE);
	return (TRUE);
}
