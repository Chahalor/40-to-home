/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:49:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/21 09:30:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# pragma once

/* -----| Header |----- */
// Global
///...

// Local
//...

// Modules
//...

/* -----| Define |----- */
//...

/* -----| Enums |----- */

# ifndef E_BOOL
#  define E_BOOL

/**
 * @brief Boolean values. no need to explain more.
 */
typedef enum e_bool
{
	false,
	true
}	t_bool;

# endif	// E_BOOL

# ifndef E_ERROR
#  define E_ERROR

/**
 * @brief Error codes.
 * 
 * @note
 * - no_error: No error.
 * 
 * - invalid_argument: Invalid argument.
 * 
 * - invalid_file: Invalid file.
 * 
 * - invalid_map: Invalid map.
 * 
 * - mlx_error: MLX error.
 * 
 * - mlx_window_error: MLX window error.
 * 
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
	malloc_error,
	file_error,
};
# endif	// E_ERROR

# ifndef E_COLOR
#  define E_COLOR

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

# endif	// E_COLOR

# ifndef E_CMD
#  define E_CMD

/**
 * @brief Command codes for the cmd module.
 */
enum e_cmd
{
	cmd_exit,
	cmd_quit,
	cmd_help,
	cmd_reset,
	cmd_zoom,
	cmd_rotate,
	cmd_move,
	cmd_draw,
	cmd_status,
	cmd_type,
	cmd_not_found
};

# endif	// E_CMD

# ifndef E_KEY
#  define E_KEY

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
	k_pad_2 = 65433,
	k_pad_4 = 65431,
	k_pad_5 = 65437,
	k_pad_6 = 65432,
	k_pad_8 = 65430,
	k_ctrl = 65507,
	k_rtrn = 65293,
	k_spc = 32,
	k_w = 119,
	k_a = 97,
	k_s = 115,
	k_d = 100,
};

# endif	// E_KEY

/* -----| Structs |----- */
//...

/* -----| Typedefs |----- */

typedef unsigned int	t_uint;

typedef enum e_error	t_error;
typedef enum e_color	t_color;
typedef enum e_key		t_key;
typedef enum e_cmd		t_cmd;

#endif	// TYPE_H