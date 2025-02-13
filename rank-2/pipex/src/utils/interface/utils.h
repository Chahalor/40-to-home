/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:22:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 10:35:39 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# pragma once

/* -----| Header |----- */
// Global
//...

// Local
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

void	exiting(const int exit_code, char *msg, void *ptr, void *(*f)());
char	*ft_getenv(const char *envp[], const char *target);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */
//...

#endif	// UTILS_H