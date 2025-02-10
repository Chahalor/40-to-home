/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:13:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 12:29:22 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* -----| Header |----- */

// Global
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

// Local
# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include "type.h"
# include "struct.h"

// module
# include "args.h"
# include "cmd.h"
# include "debug.h"
# include "init.h"
// # include "window.h"	@todo
// @todo add all the modules.

/* -----| Defines |----- */

# ifndef DEBUG
#  define DEBUG 0
# endif

// Some default values
# define DEFAULT_WIDTH 800
# define DEFAULT_HEIGHT 600
# define DEFAULT_TITLE "FdF"
# define DEFAULT_TYPE -1
# define DEFAULT_ZOOM 1
# define DEFAULT_ROTATIONX 0	//120
# define DEFAULT_ROTATIONY 30	//90
# define DEFAULT_COLOR1 0xFFFFFF
# define DEFAULT_COLOR2 0xFF0000

# define SCALE 10

# define PI 3.1415


/* -----| Inlines |----- */

/**
 * @brief Convert degrees to radians.
 * 
 *  - dtr = degrees to radians.
 * 
 * @todo posibly useless.
 */
__attribute__((cold, unused)) static inline double	dtr(double deg)
{
	return (deg * PI / 180);
}

/**
 * @brief add the padding and the zoom to the point.
 * 
 * @param pt The point.
 * @param pos The position.
 * 
 * @return t_point The new point.
 */
__attribute__((hot)) static inline t_point	calc_c(t_point pt, t_pos *pos)
{
	return ((t_point){
		.x = pt.x * pos->zoom + pos->paddingx,
		.y = pt.y * pos->zoom + pos->paddingy,
		.z = pt.z});
}

/** @todo */
__attribute__((hot)) static inline int	get_sign(int a, int b)
{
	if (a > b)
		return (-1);
	return (1);
}

/** @todo */
__attribute__((cold, unused)) static inline void	get_map_min(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->height - 1)
	{
		y = -1;
		while (++y < map->width - 1)
			if (map->map[x][y] < map->min)
				map->min = map->map[x][y];
	}
}

/** @todo */
__attribute__((cold, unused)) static inline void	get_map_max(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->height - 1)
	{
		y = -1;
		while (++y < map->width - 1)
			if (map->map[x][y] > map->max)
				map->max = map->map[x][y];
	}
}

/* -----| Prototypes |----- */

// args.c

t_args	*parse_args(int argc, const char *argv[]);

// fdf.c

void	fdf(t_args *args);

// init.c

t_fdf	*init_fdf(t_args *args);
void	setup_hooks(t_fdf *data);

// hookProc.c

int		key_down_hook(int keycode, t_fdf *data);
int		key_up_hook(int keycode, t_fdf *data);
int		mouse_hook_down(int button, int x, int y, t_fdf *data);
int		mouse_hook_up(int button, int x, int y, t_fdf *data);
int		mouse_move_hook(int x, int y, t_fdf *data);

// parsing.c

t_map	*parse_map(const char *path);
void	free_map(t_map *map);

// isometric.c

t_point	**isometric(t_fdf *fdf, t_map *map, t_point **points);

// projection.c

t_point	**projection(t_fdf *fdf, t_map *map, t_point **points);
t_point	calculate_rev(t_fdf *fdf, t_map *map, int x, int y);
t_point	calculate_iso(t_fdf *fdf, t_map *map, int i, int j);

// window.c

void	put_pixel(t_image *img, t_point coord, t_uint color);
void	draw_line(t_fdf *fdf, t_point start, t_point end, void *ptr);
void	draw_line2(t_fdf *fdf, t_point p1, t_point p2, void *buffer);

// model.c

void	draw_projection(t_fdf *fdf);
void	zoom_model(t_fdf *fdf, int zoom);
void	rotate_model(t_fdf *fdf, double rotationx, double rotationy);
void	translat_model(t_fdf *fdf, int x, int y);

// color.c

t_uint	get_point_color(t_fdf *fdf, t_point start, t_point end, t_point cur);
t_uint	calc_line_color(t_fdf *fd, t_color start, t_color end, int percent);

// cmd.c

void	cmd(t_fdf *data);

// utils.c

int		close_hook(t_fdf *data);
void	exiting(t_fdf *fdf, t_error code, const char *message);
void	print_help(const char *name);

// debug.c ├──└──│

void	d_print_args(t_args *args);
void	d_print_mlx(t_mlx *mlx);
void	d_print_map(t_map *map);
void	d_print_image(t_image *img);
void	d_print_fdf(t_fdf *fdf);

#endif // FDF_H