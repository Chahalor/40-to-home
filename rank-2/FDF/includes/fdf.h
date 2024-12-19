/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:03:12 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/19 13:51:28 by nduvoid          ###   ########.fr       */
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
#  define DEBUG 1
# endif // DEBUG

# define ALLOW_NEGATIVE 1
# define ALLOW_FLOAT 0

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
}	t_key;

/* -----| Typedef |----- */

typedef int	t_uint;

# if (ALLOW_FLOAT == 1 && ALLOW_NEGATIVE == 1)

typedef double			t_type;
# elif ALLOW_FLOAT == 1

typedef float			t_type;
# elif ALLOW_NEGATIVE == 1

typedef int				t_type;
# else

typedef t_uint			t_type;
# endif // ALLOW_FLOAT && ALLOW_NEGATIVE

/* -----| Structures |----- */

/** @todo */
typedef struct s_map
{
	t_type	**map;
	t_type	width;
	t_type	height;
}	t_map;

/** @todo */
typedef struct s_image
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
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
}	t_data;

/* -----| Prototypes |----- */

// fdf.c

t_error	fdf(int argc, const char *argv[]);

// screen.c

t_data	*init_data(t_uint width, t_uint height, char *title);
void	destroy_window(t_data *data);

// interactions.c

int		key_hook(int keycode, t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
int		close_hook(t_data *data);

// parsing

int		get_line_size(const char *line);
void	line_to_map(t_map *map, char *line);
t_map	*realloc_map(t_map *map);
t_map	*parse_file(char *file);
void	free_map(t_map *map);

// Images

t_error	map_to_img_2d(t_data *data);

// utils

void	exiting(int code, char *message, t_data *mlx);
t_type	fdf_atoi(const char *nptr);
int	ft_min(int a, int b);

# if DEBUG

void	dbg_print_map(t_map *map);

# endif // DEBUG

#endif // FDF_H