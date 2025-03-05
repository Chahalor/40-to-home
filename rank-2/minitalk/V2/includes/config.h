/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:58:23 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/05 11:08:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

/* -----| Header |----- */
// Glibc
//...

// Libs
//...

// Local
//...

/* -----| Define |----- */

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef DEBUG
#  define DEBUG 0
# endif

# define BUFF_MODE 0	// 0: buffered, 1: reallocing
# define BUFF_SIZE 1024

# define EOT 0x0

# define EXPECTED 1
# define UNEXPECTED 0

# define SLEEP 100

/* -----| Macro |----- */
//...

/* -----| Typedef |----- */

typedef enum e_connection	t_connection;

/* -----| Enum |----- */

enum e_connection
{
	ack,
	nack,
	acknack
};

/* -----| Union |----- */
//...

/* -----| Struct |----- */
//...

/* -----| Prototype |----- */
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	/* CONFIG_H */