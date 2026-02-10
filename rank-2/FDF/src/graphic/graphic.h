/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:42:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 11:40:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# pragma once

/* -----| Header |----- */
// Global
//...

// Local
# include "struct.h"
# include "type.h"
# include "config.h"

// modules
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
//...

/* -----| Prototype |----- */

// HookProc.c

int		key_down_hook(int keycode, t_fdf *data);
int		key_up_hook(int keycode, t_fdf *data);
int		mouse_hook_down(int button, int x, int y, t_fdf *data);
int		mouse_hook_up(int button, int x, int y, t_fdf *data);
int		mouse_move_hook(int x, int y, t_fdf *data);

// model.c

void	draw_projection(t_fdf *fdf);
void	zoom_model(t_fdf *fdf, int zoom);
void	rotate_model(t_fdf *fdf, double rotationx, double rotationy);
void	translat_model(t_fdf *fdf, int x, int y);

// window.c

void	draw_line(t_fdf *fdf, t_point start, t_point end, void *ptr);
void	draw_line2(t_image *img, t_point start, t_point end);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif // GRAPHIC_H