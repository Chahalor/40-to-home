/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:42:10 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/11 13:05:40 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

/* ************************************************************************** */
/*                                 Config                                     */
/* ************************************************************************** */

# ifndef DEBUG
#  define DEBUG		0		/* 0: debug disabled, 1: debug enabled   */
# endif	/* DEBUG */

# ifndef BONUS
#  define BONUS		0		/* 0: bonus disabled, 1: bonus enabled   */
# endif	/* BONUS */

# define ALLOW_COLORS	1	/* 0: colors disabled, 1: colors enabled */
# if ALLOW_COLORS
#  define COLORS_START	0xFF0000
#  define COLORS_END	0x0000FF
# else
#  define COLORS_START	0x000000
#  define COLORS_END	0x000000
# endif	/* ALLOW_COLORS */

# define ALLOW_LOGS		1	/* 0: logs disabled, 1: logs enabled     */
# define ALLOW_VIZUAL	1	/* 0: vizual disabled, 1: vizual enabled */

#endif	/* CONFIG_H */