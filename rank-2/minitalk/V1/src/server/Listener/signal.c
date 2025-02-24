/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/24 15:59:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
#include "interne/_Listener.h"
#include "utils.h"

/* -----| Functions |----- */

/** */
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
	// c = reverse_bits(c, 1);
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
	// ft_printf("%d", signum == SIGUSR1 ? 0 : 1);	//rm
	if (signum == SIGUSR1)
		letter = (letter << 1) | 0;
	else
		letter = (letter << 1) | 1;
	++count;
	if (count / 8 == get_char_header(letter))
	{
		write(1, &letter, 1);
		count = 0;
		letter = '\0';
	}
	// kill(siginfo->si_pid, SIGUSR1);
}

/** */
__attribute__((cold, unused)) t_bool	setup_signal(void)
{
	struct sigaction	handler;

	handler.sa_sigaction = signal_handler_ascii;
	handler.sa_flags = SA_SIGINFO;
	sigemptyset(&handler.sa_mask);
	if (sigaction(SIGUSR1, &handler, NULL) == -1)
		exiting(err_signal, "sigaction error\n", NULL);
	if (sigaction(SIGUSR2, &handler, NULL) == -1)
		exiting(err_signal, "sigaction error\n", NULL);
	return (TRUE);
}

// "Lorem ipsum odor amet, consectetuer adipiscing elit. Diam fusce faucibus aliquam netus vivamus condimentum convallis porttitor libero. Ornare inceptos consectetur, curae ligula lacus enim sem. Id ridiculus gravida fusce ante sodales, efficitur elit pellentesque proin. Semper rutrum viverra ante porta ultrices class vitae. Facilisi justo consectetur elit libero mi accumsan massa libero. Mi aliquam sapien neque nam inceptos proin. Amet dolor erat nullam rhoncus; facilisi iaculis. Rutrum non consequat metus felis nulla molestie?"