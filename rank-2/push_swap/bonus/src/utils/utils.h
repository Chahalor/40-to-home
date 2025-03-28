/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:15:45 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/28 12:06:56 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_H
# define _UTILS_H

# pragma once

/* -----| Header |----- */
// System
	//...

// Libs
	//...

// Local
	//...

/* -----| Define |----- */

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define BLUE		"\033[0;34m"
# define YELLOW		"\033[0;33m"
# define RESET		"\033[0m"

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef enum e_expect	t_expect;

/* -----| Enum |----- */

enum e_expect
{
	unexpected,
	expected,
};

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */

void	exiting(const int error, const char *message);
void	*reallocing(void *ptr, const size_t old, const size_t new);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* _UTILS_H */