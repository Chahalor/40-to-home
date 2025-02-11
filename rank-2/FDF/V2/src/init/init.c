/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:05:07 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 09:50:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_init.h"

/**
 * @brief Initialize the position of the camera and some user input information
 *  on default.
 * 
 * @param fdf Fdf structure.
 * @param color1 The first color.
 * @param color2 The second color.
 * 
 * @note The position is composed of:
 * 
 * - zoom: The zoom, default=4.
 * 
 * - rotationx: The rotation on the x axis, default=-45.0.
 * 
 * - rotationy: The rotation on the y axis, default=35.26.
 * 
 * - paddingx: The padding on the x axis.
 * 
 * - paddingy: The padding on the y axis.
 * 
 * - color1: The first color.
 * 
 * - color2: The second color.
 * 
 * - and some user input information.
 * */
static void	init_pos(t_fdf *fdf, t_uint color1, t_uint color2)
{
	fdf->pos->zoom = DEFAULT_ZOOM;
	fdf->pos->rotationx = DEFAULT_ROTATIONX;
	fdf->pos->rotationy = DEFAULT_ROTATIONY;
	fdf->pos->paddingx = fdf->mlx->width / 2;
	fdf->pos->paddingy = fdf->mlx->height / 2;
	fdf->pos->color1 = color1;
	fdf->pos->color2 = color2;
	fdf->pos->rclickdown = False;
	fdf->pos->lclickdown = False;
	fdf->pos->ctrldown = False;
}

/**
 *  @brief Initialize the MLX context.
 * 
 * @note If the MLX context cannot be created, the program will exit.
 * 
 * @param ptr MLX structure.
 * @param args Arguments.
 * @param fdf Fdf structure.
 */
static void	init_mlx(t_mlx *ptr, t_args *args, t_fdf *fdf)
{
	ptr->width = args->width;
	ptr->height = args->height;
	ptr->mlx = mlx_init();
	if (ptr->mlx == NULL)
		exiting(fdf, mlx_error, "cannot initialize mlx");
	ptr->win = mlx_new_window(ptr->mlx, args->width, args->height,
			(char *)args->file);
	if (ptr->win == NULL)
		exiting(fdf, mlx_window_error, "cannot create window");
}

/**
 * @brief Initialize the fdf image.
 * 
 * @note If the image cannot be created, the program will exit.
 * 
 * @param fdf Fdf structure.
 * 
 * @note The image is composed of:
 * 
 * - width: The width of the image.
 * 
 * - height: The height of the image.
 * 
 * - img: The image.
 * 
 * - addr: The address of the image.
 * 
 * - bpp: The bits per pixel.
 * 
 * - size_line: The size of a line.
 * 
 * - endian: The endian.
 * 
 */
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

/**
 * @brief Initialize the Fdf structure.
 * 
 * @param args Arguments.
 * 
 * @return The Fdf structure.
 * 
 * @note The Fdf structure is composed of:
 * 
 * - args: The arguments.
 * 
 * - mlx: The MLX context.
 * 
 * - img: The image.
 * 
 * - pos: The position of the camera and some other user informations.
 * 
 * - map: The map.
 * */
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
	init_pos(fdf, args->color1, args->color2);
	if (!fdf->mlx || !fdf->img || !fdf->pos)
		exiting(fdf, mlx_error, "cannot initialize fdf");
	fdf->map = parse_map(args->file);
	if (fdf->map == NULL)
		exiting(fdf, invalid_map, "cannot parse map");
	get_map_min(fdf->map);
	get_map_max(fdf->map);
	if (args->type == -1 || args->type == 0)
		fdf->algo = calculate_iso;
	else
		fdf->algo = calculate_rev;
	return (fdf);
}

/**
 * @brief Setup the different events hooks.
 * 
 * @param data Fdf structure.
 * 
 * @note The hooks are:
 * 
 * - key_down_hook: Key down event.
 * 
 * - key_up_hook: Key up event.
 * 
 * - mouse_hook_down: Mouse down event.
 * 
 * - mouse_hook_up: Mouse up event.
 * 
 * - mouse_move_hook: Mouse move event.
 * 
 * - close_hook: Close event.
 */
void	setup_hooks(t_fdf *data)
{
	mlx_hook(data->mlx->win, 2, 1L << 0, key_down_hook, data);
	mlx_hook(data->mlx->win, 3, 1L << 1, key_up_hook, data);
	mlx_hook(data->mlx->win, 4, 1L << 2, mouse_hook_down, data);
	mlx_hook(data->mlx->win, 5, 1L << 3, mouse_hook_up, data);
	mlx_hook(data->mlx->win, 6, 1L << 6, mouse_move_hook, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, close_hook, data);
}
