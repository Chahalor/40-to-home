/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:38:59 by marvin            #+#    #+#             */
/*   Updated: 2024/10/21 10:31:27 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_logic(int nb, int fd)
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

void	ft_putnbr_fd(int nb, int fd)
{
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
