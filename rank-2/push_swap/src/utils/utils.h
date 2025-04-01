/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:24:38 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/01 12:06:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* -----| Header |----- */
// System
//...

// Global
//...

// Modules
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

void		exiting(const int error, const char *message);
void		freeing_array(char **array);
void		*mallocing(const size_t size);
void		*reallocing(void *ptr, const size_t old, const size_t new);

// extern int	max(int a, int b);
// extern int	min(int a, int b);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

/** */
__attribute__((always_inline, used, pure, leaf))
static inline int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/** */
__attribute__((always_inline, used, pure, leaf))
static inline int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

#endif	/* UTILS_H */