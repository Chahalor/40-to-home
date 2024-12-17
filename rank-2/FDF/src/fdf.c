/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:02 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/17 15:01:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#if DEBUG

/**
 * @todo
 */
int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	map = parse_file(argv[1]);
	if (!map)
	{
		ft_printf("(null)\n");
		return (1);
	}
	ft_printf("Width: %d\n", map->width);
	ft_printf("Height: %d\n", map->height);
	return (0);
}

#else

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
	{
		ft_printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	map = parse_file(argv[1]);
	(void)map;
	return (0);
}

#endif // DEBUG