/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:54:14 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 09:47:10 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# pragma once

/* -----| Header |----- */
// Global
 //...

// Local
 //...

/* -----| Define |----- */
//...

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */
//...

/* -----| Enum |----- */
//...

/* -----| Union |----- */
//...

/* -----| Struct |----- */

/**
 * @brief Arguments structure, it stores the arguments passed to the program.
 * 
 * @note
 * 
 * - argc: Number of arguments.
 * 
 * - argv: Array of arguments.
 * 
 * - file: File path. (if no -p/--path the last argument will be take as path)
 * 
 * - height: Window height.
 * 
 * - width: Window width.
 * 
 * - type: Type of projection. @todo
 * 
 * - help: Display help.
 * 
 * - invalid: Invalid argument.
 */
typedef struct s_args
{
	int			argc;
	const char	**argv;
	const char	*file;
	int			height;
	int			width;
	int			type;
	int			color1;
	int			color2;
	int		help	: 2;
	int		invalid	: 2;
}	t_args;

/**
 * @brief Point structure, it stores the coordinates of a point.
 * 
 * @details
 * - x: X position.
 * - y: Y position.
 * - z: Z position.
 */
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

/**
 * @brief MLX structure, it stores the MLX context.
 * 
 * @details
 * - mlx: MLX context.
 * - win: MLX window.
 * - width: Window width.
 */
typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	unsigned int	width;
	unsigned int	height;
}	t_mlx;

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
typedef struct s_map
{
	int				**map;
	int				width;
	int				height;
	int				min;
	int				max;
	int				nb_high;
	struct s_point	**iso_map;
}	t_map;

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
typedef struct s_image
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	void	*addr;
	int		width;
	int		height;
}	t_image;

/**
 * @brief Position structure, it stores the position of the camera.
 * 
 * @details
 * - zoom: Zoom.
 * - rotationx: Rotation on the x-axis.
 * - rotationy: Rotation on the y-axis.
 * - paddingx: Padding on the x-axis.
 * - paddingy: Padding on the y-axis.
 * - color1: Color 1.
 * - color2: Color 2.
 * - rclickdown: Right click down.
 * - lclickdown: Left click down.
 * - ctrldown: Control key down.
 */
typedef struct s_pos
{
	unsigned int	zoom;
	double			rotationx;
	double			rotationy;
	int				paddingx;
	int				paddingy;
	unsigned int	color1;
	unsigned int	color2;
	int			rclickdown	: 2;
	int			lclickdown	: 2;
	int			ctrldown	: 2;
}	t_pos;

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
typedef struct	s_fdf
{
	t_args	*args;
	t_mlx	*mlx;
	t_map	*map;
	t_image	*img;
	t_pos	*pos;
	t_point	(*algo)(struct s_fdf *, t_map *, int, int);
}	t_fdf;

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// STRUCT_H