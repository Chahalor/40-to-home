/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:54:16 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 09:59:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */
	//...

/* Global */
	//...

/* Modules */
#include "put.h"

#pragma endregion	/* Includes */
#pragma region "Functions"

/**
 * @brief Outputs the character c to the given file descriptor.
 * 
 * @param c Character to be output.
 * @param fd File descriptor on which to write.
 * @return void
 */
void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

/**
 * @brief Outputs the string s to the given file descriptor
 * followed by a newline.
 * 
 * @param s String to be output.
 * @param fd File descriptor on which to write.
 * @return void
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

static void	write_logic(int nb, int fd)
{
	int	r;

	if (nb <= 9)
	{
		r = '0' + nb;
		write(fd, &r, 1);
		return ;
	}
	write_logic(nb / 10, fd);
	write_logic(nb % 10, fd);
}

/**
 * @brief Outputs the integer n to the given file descriptor.
 * 
 * @param nb Integer to be output.
 * @param fd File descriptor on which to write.
 * @return void
 */
void	ft_putnbr_fd(int nb, int fd)
{
	char	r;

	if (fd < 0)
		return ;
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb == 0)
		write(fd, "0", 1);
	else if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
		write_logic(nb, fd);
	}
	else
		write_logic(nb, fd);
}

/**
 * @brief Outputs the string s to the given file descriptor.
 * 
 * @param s String to be output.
 * @param fd File descriptor on which to write.
 * @return void
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

#pragma endregion	/* Functions */