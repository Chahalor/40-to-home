/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:13:10 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/25 16:59:37 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	printf("\nPrintf : %d \n ft_printf : %d",printf(" salut %%"),ft_printf(" salut %%"));
	// char	*txt = "ptr=%x\n";
	// int		data = -2147483647 - 1;
	// int	ft_nb = ft_printf(txt, data);
	// int	nb	  = printf(txt, data);
	// printf("ft_nb=	%d\n", ft_nb);
	// printf("nb=	%d\n", nb);
	// return (0);
}
