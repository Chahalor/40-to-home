/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:13:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/27 18:55:38 by nduvoid          ###   ########.fr       */
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

/* -----| Defines |----- */

# ifndef DEBUG
#  define DEBUG 0
# endif

// Some default values
# define DEFAULT_WIDTH 800
# define DEFAULT_HEIGHT 600
# define DEFAULT_TITLE "FdF"
# define DEFAULT_TYPE 0
# define DEFAULT_ZOOM 4
# define DEFAULT_ROTATIONX 210.0
# define DEFAULT_ROTATIONY 45.0

# define ANGLE 0.5f
# define ROTA_FACTOR 5.0f
# define ZOOM_FACTOR 1
# define SCALE 10

# define PI 3.14159265358979323846

/* -----| Enums |----- */

/**
 * @brief Error codes.
 * 
 * @details
 * - no_error: No error.
 * - invalid_argument: Invalid argument.
 * - invalid_file: Invalid file.
 * - invalid_map: Invalid map.
 * - mlx_error: MLX error.
 * - mlx_window_error: MLX window error.
 * - mlx_image_error: MLX image error.
 */
enum e_error
{
	no_error = 0,
	invalid_argument,
	invalid_file,
	invalid_map,
	mlx_error,
	mlx_window_error,
	mlx_image_error,
};

/**
 * @brief Color codes.
 * 
 * @details
 * - black: Black color, 0x000000.
 * - white: White color, 0xFFFFFF.
 * - red: Red color, 0xFF0000.
 * - green: Green color, 0x00FF00.
 * - blue: Blue color, 0x0000FF.
 */
enum e_color
{
	black = 0x000000,
	white = 0xFFFFFF,
	red = 0xFF0000,
	green = 0x00FF00,
	blue = 0x0000FF,
};

/**
 * @brief Key codes for the 42 Imac (cause there special).
 */
enum e_key
{
	k_esc = 65307,
	k_up = 65362,
	k_down = 65364,
	k_left = 65361,
	k_right = 65363,
	k_reset = 65288,
	k_plus = 65451,
	k_minus = 65453,
};

/* -----| Structs |----- */

/**
 * @brief Arguments structure, it stores the arguments passed to the program.
 * 
 * @details
 * - argc: Number of arguments.
 * - argv: Array of arguments.
 * - file: File path. (if no -p/--path the last argument will be take as path)
 * - height: Window height.
 * - width: Window width.
 * - type: Type of projection. @todo
 * - help: Display help.
 * - invalid: Invalid argument.
 */
struct s_args
{
	int			argc;
	const char	**argv;
	const char	*file;
	int			height;
	int			width;
	int			type;
	Bool		help	: 1;
	Bool		invalid	: 1;
};

/**
 * @brief Point structure, it stores the coordinates of a point.
 */
struct s_point
{
	int	x;
	int	y;
	int	z;
};

/**
 * @brief MLX structure, it stores the MLX context.
 * 
 * @details
 * - mlx: MLX context.
 * - win: MLX window.
 * - width: Window width.
 */
struct s_mlx
{
	void			*mlx;
	void			*win;
	unsigned int	width;
	unsigned int	height;
};

/**
 * @brief Map structure, it stores the map.
 * 
 * @details
 * - map: Map, an array of integers.
 * - width: Map width.
 * - height: Map height.
 * - iso_map: Isometric map.
 * - @todo an other map projection.
 */
struct s_map
{
	int				**map;
	int				width;
	int				height;
	struct s_point	**iso_map;
};

/**
 * @brief Image structure, it stores the image.
 * 
 * @details
 * - img: Image.
 * - bpp: Bits per pixel.
 * - size_line: Size of a line.
 * - endian: Endian.
 * - addr: The image address, so me can change it.
 */
struct s_image
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	void	*addr;
	int		width;
	int		height;
};

/**
 * @brief Position structure, it stores the position of the camera.
 * 
 * @details
 * - zoom: Zoom.
 * - rotationx: Rotation on the x-axis.
 * - rotationy: Rotation on the y-axis.
 */
struct s_pos
{
	unsigned int	zoom;
	double			rotationx;
	double			rotationy;
	int				paddingx;
	int				paddingy;
	Bool			rclickdown	: 1;
	Bool			lclickdown	: 1;
};

/**
 * @brief FDF structure, it stores all the data of the program.
 * 
 * @details
 * - args: The argument gave to the programes.
 * - mlx: The MLX context.
 * - map: The map.
 * - img: The image.
 * - pos: The position of the camera.
 */
struct	s_fdf
{
	struct s_args	*args;
	struct s_mlx	*mlx;
	struct s_map	*map;
	struct s_image	*img;
	struct s_pos	*pos;
};

/* -----| Typedefs |----- */

typedef unsigned int	t_uint;

typedef enum e_error	t_error;
typedef enum e_color	t_color;
typedef enum e_key		t_key;

typedef struct s_args	t_args;
typedef struct s_point	t_point;
typedef struct s_mlx	t_mlx;
typedef struct s_map	t_map;
typedef struct s_image	t_image;
typedef struct s_pos	t_pos;
typedef struct s_fdf	t_fdf;

/* -----| Inlines |----- */

/**
 * @brief Convert degrees to radians.
 * 
 *  - dtr = degrees to radians.
 */
static inline double	dtr(double deg)
{
	return (deg * PI / 180);
}

/** @todo */
static inline t_point	calculate_coord(t_point pt, int zoom, int paddingx,
									int paddingy)
{
	return ((t_point){
		.x = pt.x * zoom / ZOOM_FACTOR + paddingx,
		.y = pt.y * zoom / ZOOM_FACTOR + paddingy,
		.z = pt.z});
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

int		key_hook(int keycode, t_fdf *data);
int		mouse_hook_down(int button, int x, int y, t_fdf *data);
int		mouse_hook_up(int button, int x, int y, t_fdf *data);
int		mouse_move_hook(int x, int y, t_fdf *data);
int		close_hook(t_fdf *data);

// parsing.c

t_map	*parse_map(const char *path);
void	free_map(t_map *map);

// isometric.c

t_point	**isometric(t_fdf *fdf, t_map *map, t_point **points);

// window.c

void	put_pixel(t_image *img, t_point pos, t_uint color);
void	draw_projection(t_fdf *fdf, t_color col_start, t_color col_end);
void	zoom_model(t_fdf *fdf, int zoom);
void	rotate_model(t_fdf *fdf, double rotationx, double rotationy);
void	translat_model(t_fdf *fdf, int x, int y);

// exit.c

void	exiting(t_fdf *fdf, t_error code, const char *message);

// debug.c ├──└──│

void	d_print_args(t_args *args);
void	d_print_mlx(t_mlx *mlx);
void	d_print_map(t_map *map);
void	d_print_image(t_image *img);
void	d_print_fdf(t_fdf *fdf);

#endif // FDF_H