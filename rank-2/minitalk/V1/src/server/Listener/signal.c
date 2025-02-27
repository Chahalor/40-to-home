/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:17:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 13:53:27 by nduvoid          ###   ########.fr       */
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
		// write(1, str.str, str.len);
		free(str.str);
		str = (t_str){0};
		manager(0, alloc);
	}
	// ft_printf("manager: %s\n", str.str);	//rm
}

#if ALLOW_BUFF == 1

__attribute__((hot)) void	signal_handler(int signum, siginfo_t *siginfo,
	void *context)
{
	static char	buff[HEAR_BUFF] = {0};
	static int	count = 0;
	static int	i = 0;
	static int nb_sig = 0;

	++nb_sig;
	(void)siginfo;
	(void)context;
	buff[i] = (buff[i] << 1) | (signum == SIGUSR2);
	if (++count == 8)
	{
		count = 0;
		++i;
	}
	if (i >= HEAR_BUFF || buff[i - 1] == EOT)
	{
		write(1, buff, i);
		i = 0;
		ft_memset(buff, 0, HEAR_BUFF);
		count = 0;
	}
	ft_printf("nb_sig: %d\n", nb_sig);	//rm
}

#else

/** */
__attribute__((hot)) void	signal_handler(int signum, siginfo_t *siginfo,
	void *context)
{
	static char	letter = 0;
	static int	count = 0;

	(void)siginfo;
	(void)context;
	ft_printf("%d", signum == SIGUSR2);	//rm
	letter = (letter << 1) | (signum == SIGUSR2);
	++count;
	if (count >= 8)
	{
		ft_printf(" ");	//rm
		if (letter == EOT)
			manager('\0', print_str);
		else
			manager(letter, add_char);
		letter = '\0';
		count = 0;
		
	}
}

#endif

/** */
__attribute__((cold, unused)) t_bool	setup_signal(void)
{
	struct sigaction	handler;

	handler.sa_sigaction = signal_handler;
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