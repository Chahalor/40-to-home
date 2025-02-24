/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_args.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:13:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/21 09:29:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_ARGS_H
# define INTERNAL_ARGS_H

# pragma once

/* -----| Header |----- */
// Global
# include <stdlib.h>

// Local
# include "type.h"
# include "struct.h"
# include "config.h"
# include "libft.h"

// Modules
# include "utils.h"
# include "debug.h"

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
// args_parsing.c

void	parseur_v2(int argc, const char *argv[], t_args *args);

// args_utils.c

int		vl(const int argc, const char *argv[], int pos, int nb_args);
int		is_valid_soption(const int argc, const char *argv[], int pos,
			int nb_args);

/* -----| Static |----- */
//...

/* -----| Extern |----- */
//...

/* -----| Inline |----- */

__attribute__((cold, unused)) static inline int ask_validation(void)
{
	char	buff[2];

	ft_printf("Do you want to validate the arguments? [Y/n] ");
	read(0, buff, 2);
	if (buff[0] != 'Y' && buff[0] != 'y')
		return (1);
	return (0);
}

__attribute__((cold, unused)) static inline int	is_fdf_file(const char *file)
{
	int		i;

	i = ft_strlen(file);
	if (i < 5)
		return (0);
	if (file[i - 1] != 'f' || file[i - 2] != 'd' || file[i - 3] != 'f'
		|| file[i - 4] != '.')
		return (ask_validation());
	return (1);
}
#endif	// INTERNAL_ARGS_H