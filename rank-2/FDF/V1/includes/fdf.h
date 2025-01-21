/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:12 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/21 09:17:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* -----| Library |----- */

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* -----| Header Files |----- */

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"

/* -----| Defines |----- */

# ifndef DEBUG
#  define DEBUG 0
# endif // DEBUG

# define ALLOW_NEGATIVE 1
# define ALLOW_FLOAT 0

# define ANGLE 0.523599
# define SCALE 1

# define ZOOM_FACTOR 5
# define ROTA_FACTOR 1

/* -----| Enums |----- */

typedef enum e_error
{
	NO_ERROR,
	OPEN_ERROR,
	READ_ERROR,
	MALLOC_ERROR,
	PARSE_ERROR,
	MLX_INIT_ERROR,
	MLX_WIN_ERROR,
	MLX_IMG_ERROR,
}	t_error;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_key
{
	K_ESC = 65307,
	K_UP = 65362,
	K_DOWN = 65364,
	K_LEFT = 65361,
	K_RIGHT = 65363,
	K_RESET = 65288,
	K_PLUS = 65451,
	K_MINUS = 65453,
}	t_key;

typedef enum e_color
{
	BLACK = 0x00000000,
	WHITE = 0x00FFFFFF,
	RED = 0x00FF0000,
	GREEN = 0x0000FF00,
	BLUE = 0x000000FF,
}	t_color;

/* -----| Typedef |----- */

typedef int		t_uint;

# if (ALLOW_FLOAT == 1 && ALLOW_NEGATIVE == 1)

typedef double	t_type;
# elif ALLOW_FLOAT == 1

typedef float	t_type;
# elif ALLOW_NEGATIVE == 1

typedef int		t_type;
# else

typedef t_uint	t_type;
# endif // ALLOW_FLOAT && ALLOW_NEGATIVE

/* -----| Structures |----- */

/** @todo */
typedef struct s_args
{
	int			argc;
	const char	**argv;
	int			width;
	int			height;
	char		*title;
	char		*path;
	t_bool		help	: 1;
	t_bool		invalid	: 1;
	t_bool		header	: 1;
}				t_args;

/** @todo */
typedef struct s_point
{
	t_type	u;
	t_type	v;
	t_type	z;
}	t_point;

/** @todo */
typedef struct s_map
{
	t_type	**map;
	t_type	width;
	t_type	height;
	t_point	*iso_map;
}	t_map;

/** @todo */
typedef struct s_image
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	void	*addr;
}	t_image;

/** @todo */
typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_uint	width;
	t_uint	height;
	t_map	*map;
	t_image	*img;
	t_type	zoom;
	float	rotationx;	// @todo
	float	rotationy;
}	t_data;

/* -----| Inlines |----- */

/** @todo */
static inline int	get_sign(int n)
{
	return ((n > 0) - (n < 0));
}

/* -----| Prototypes |----- */

// fdf.c

t_error	fdf(t_args *args);

// screen.c

t_data	*init_data(t_uint width, t_uint height, char *title);
void	destroy_window(t_data *data);

// interactions.c

int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		mouse_move_hook(int x, int y, t_data *data);
int		close_hook(t_data *data);

// parsing

int		get_line_size(const char *line);
void	line_to_map(t_map *map, char *line);
t_map	*realloc_map(t_map *map);
t_map	*parse_file(char *file);
void	free_map(t_map *map);

// Images

void	color_pixel(void *addr, t_data *data, t_point p, t_color color);
t_point	*map_to_iso(t_data *data);
t_error	map_to_img_3d(t_data *data);

// utils

void	exiting(int code, char *message, t_data *mlx);
t_type	fdf_atoi(const char *nptr);
int		ft_min(int a, int b);
t_type	abs(t_type n);

// drawing

t_error	draw_line(t_data *data, t_point p1, t_point p2, t_color color);
t_error	map_drawer(t_data *data, t_point *iso_map, t_color color, Bool scaling);
t_error	draw_rotation(t_data *data);
t_error	draw_zoom(t_data *data, t_type zoom);
t_error	draw_fdf(t_data *data);

// args.c

t_args	*parse_args(int argc, const char *argv[]);
t_args	*do_args(t_args *args);
void	help(void);

// debug.c

void	dbg_print_map(t_map *map);
void	dbg_print_image(t_image *img);
void	dbg_print_data(t_data *data);
int		dbg_print(char *str, ...);
void	dbg_print_iso(t_data *data, t_point *iso);

#endif // FDF_H 