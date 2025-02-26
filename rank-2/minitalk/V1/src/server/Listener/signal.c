/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/26 12:34:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
#include "interne/_Listener.h"
#include "utils.h"

/* -----| Functions |----- */

/**
 * @brief Get the number of bits of a char
 * 
 * @param c the char to be checked
 * 
 * @return int the number of bits
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
__attribute__((hot)) int	get_char_header(char c)
{
	if ((c & 0x80) == 0)
		return (1);
	else if ((c & 0xE0) == 0xC0)
		return (2);
	else if ((c & 0xF0) == 0xE0)
		return (3);
	else if ((c & 0xF8) == 0xF0)
		return (4);
	else
		return (1);
}

/** */
__attribute__((hot)) void	manager(char c, t_mode mode)
{
	static t_str	str = {0};
	char			*tmp;

	if (mode == alloc)
	{
		tmp = str.str;
		str.str = (char *)ft_calloc(1, sizeof(char) * (2 * str.size + 1));
		if (!str.str)
			exiting(err_malloc, "malloc error\n", tmp);
		ft_memcpy(str.str, tmp, str.len);
		free(tmp);
		str.size = 2 * str.size + 1;
	}
	else if (mode == add_char)
	{
		if (!str.str || str.len + 1 == str.size)
			manager(c, alloc);
		str.str[str.len++] = c;
	}
	else
	{
		manager('\n', add_char);
		write(1, str.str, str.len);
		free(str.str);
		str = (t_str){0};
		manager(0, alloc);
	}
}

/** */
void	signal_handler_ascii(int signum, siginfo_t *siginfo,
	void *context)
{
	static char		letter = 0;
	static int		count = 0;

	(void)siginfo;
	(void)context;
	if (signum == SIGUSR1)
		letter = (letter << 1) | 0;
	else
		letter = (letter << 1) | 1;
	++count;
	ft_printf("letter: %c, count: %d, header: %d\n", letter, count, get_char_header(letter));
	if (count / 8 == get_char_header(letter))
	{
		if (letter == EOT)
			manager('\0', print_str);
		else
			manager(letter, add_char);
		count = 0;
		letter = '\0';
	}
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
	manager(0, alloc);
	return (TRUE);
}

// "Lorem ipsum odor amet, consectetuer adipiscing elit. Diam fusce faucibus aliquam netus vivamus condimentum convallis porttitor libero. Ornare inceptos consectetur, curae ligula lacus enim sem. Id ridiculus gravida fusce ante sodales, efficitur elit pellentesque proin. Semper rutrum viverra ante porta ultrices class vitae. Facilisi justo consectetur elit libero mi accumsan massa libero. Mi aliquam sapien neque nam inceptos proin. Amet dolor erat nullam rhoncus; facilisi iaculis. Rutrum non consequat metus felis nulla molestie?"