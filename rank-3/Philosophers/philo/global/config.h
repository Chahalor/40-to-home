/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:43:01 by nduvoid           #+#    #+#             */
/*   Updated: 2025/06/18 14:17:24 by nduvoid          ###   ########.fr       */
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
# endif	/* !DEBUG */

# ifndef BONUS
#  define BONUS		0		/* 0: bonus disabled, 1: bonus enabled   */
# endif	/* !BONUS */

# ifndef ALLOW_THOUGHTS
#  define ALLOW_THOUGHTS	1	/* 0: thoughts disabled, 1: thoughts enabled */
# endif	/* !ALLOW_THOUGHTS */

# define DISPLAY_MODE	1	/* 0: raw log, 2: vizualizer     */

# define _LIKELY	__glibc_likely		/* __builtin_expect((cond), 1) */
# define _UNLIKELY	__glibc_unlikely	/* __builtin_expect((cond), 0) */

#endif	/* !CONFIG_H */