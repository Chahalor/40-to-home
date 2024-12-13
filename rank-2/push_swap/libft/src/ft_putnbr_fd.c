/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:38:59 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 10:35:32 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
