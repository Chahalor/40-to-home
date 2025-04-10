/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:43:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/10 11:03:44 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

/* ************************************************************************** */
/*                                 Config                                     */
/* ************************************************************************** */

# ifndef DEBUG
#  define DEBUG		0
# endif	/* DEBUG */

# ifndef BONUS
#  define BONUS		0
# endif	/* BONUS */

# define ALLOW_COLORS	1
# if ALLOW_COLORS
#  define COLORS_START	0x0000FF
#  define COLORS_END	0xFF0000
# else
#  define COLORS_START	0
#  define COLORS_END	0
# endif	/* ALLOW_COLORS */

# define ALLOW_LOGS		1

#endif	/* CONFIG_H */