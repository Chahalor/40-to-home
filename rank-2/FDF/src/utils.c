/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:42:56 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/07 08:58:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exiting(int code, char *message, t_data *mlx)
{
	if (mlx)
	{
		if (mlx->img)
		{
			if (mlx->img->img)
				mlx_destroy_image(mlx->mlx, mlx->img->img);
			free(mlx->img);
		}
		if (mlx->map)
			free_map(mlx->map);
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		if (mlx->mlx)
			mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		free(mlx);
	}
	if (message)
		perror(message);
	else if (code == NO_ERROR)
		ft_printf("Exiting with no error\n");
	else
		perror("Exiting with an error code\n");
	exit(code);
}

static int	is_space(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

/**
 * @brief Convert a string to an integer
 * 
 * @param nptr The string to convert
 * @return The integer value of the string
 */
t_type	fdf_atoi(const char *nptr)
{
	t_type			r;
	unsigned int	i;
	int				neg;

	neg = 1;
	r = 0;
	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	return (r * neg);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_type	abs(t_type n)
{
	if (n < 0)
		return (-n);
	return (n);
}
