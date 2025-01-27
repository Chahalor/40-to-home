/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:05:07 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 15:06:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_pos(t_fdf *fdf)
{
	fdf->pos->zoom = DEFAULT_ZOOM;
	fdf->pos->rotationx = 210.0;
	fdf->pos->rotationy = 45.0;
	fdf->pos->paddingx = fdf->mlx->width / 2;
	fdf->pos->paddingy = fdf->mlx->height / 2;
	fdf->pos->rclickdown = False;
	fdf->pos->lclickdown = False;
}

static void	init_mlx(t_mlx *ptr, t_args *args, t_fdf *fdf)
{
	ptr->width = args->width;
	ptr->height = args->height;
	ptr->mlx = mlx_init();
	if (ptr->mlx == NULL)
		exiting(fdf, mlx_error, "cannot initialize mlx");
	ptr->win = mlx_new_window(ptr->mlx, args->width, args->height,
		DEFAULT_TITLE);
	if (ptr->win == NULL)
		exiting(fdf, mlx_window_error, "cannot create window");
}

static void	init_img(t_fdf *fdf)
{
	fdf->img->width = fdf->mlx->width;
	fdf->img->height = fdf->mlx->height;
	fdf->img->img = mlx_new_image(fdf->mlx->mlx, fdf->mlx->width,
		fdf->mlx->height);
	if (fdf->img->img == NULL)
		exiting(fdf, mlx_image_error, "cannot create image");
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->bpp,
		&fdf->img->size_line, &fdf->img->endian);
	if (fdf->img->addr == NULL)
		exiting(fdf, mlx_image_error, "cannot get image address");
}

t_fdf	*init_fdf(t_args *args)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf) + sizeof(t_mlx) + sizeof(t_image)
		+ sizeof(t_pos));
	if (fdf == NULL)
		return (NULL);
	fdf->args = args;
	fdf->mlx = (t_mlx *)(fdf + 1);
	fdf->img = (t_image *)(fdf->mlx + 1);
	fdf->pos = (t_pos *)(fdf->img + 1);
	init_mlx(fdf->mlx, args, fdf);
	init_img(fdf);
	init_pos(fdf);
	if (!fdf->mlx || !fdf->img || !fdf->pos)
		exiting(fdf, mlx_error, "cannot initialize fdf");
	fdf->map = parse_map(args->file);
	if (fdf->map == NULL)
		exiting(fdf, invalid_map, "cannot parse map");
	return (fdf);
}

void	setup_hooks(t_fdf *data)
{
	mlx_hook(data->mlx->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx->win, 4, 1L << 2, mouse_hook_down, data);
	mlx_hook(data->mlx->win, 5, 1L << 3, mouse_hook_up, data);
	mlx_hook(data->mlx->win, 6, 1L << 6, mouse_move_hook, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, close_hook, data);
}
