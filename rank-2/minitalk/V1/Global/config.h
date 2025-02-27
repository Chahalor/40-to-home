/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:34:05 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/27 13:23:43 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

/* -----| Header |----- */
// Libs
//...

// Global
//...

// Modules
//...

/* -----| Define |----- */

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef HEAR_BUFF
#  define HEAR_BUFF 1024
# endif

# ifndef BONUS
#  define BONUS 0
# endif

# define EOT 0x0
# define SLEEP_TIME 100

// params area

# ifndef ALLOW_BUFF
#  define ALLOW_BUFF 1	// @todo change to 0
# endif

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
//...

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// CONFIG_H