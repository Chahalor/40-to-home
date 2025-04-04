/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:58:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 09:58:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_H
# define PUT_H

# pragma once

# pragma region "Includes"
/* Systeme */
#include "unistd.h"

/* Global */
	//...

/* Modules */
	//...

# pragma endregion	/* Includes */
# pragma region "Macros"
//...

# pragma endregion	/* Macros */
# pragma region "Typedefs"
//...

# pragma endregion	/* Typedefs */
# pragma region "Enums"
//...

# pragma endregion	/* Enums */
# pragma region "Structs"
//...

# pragma endregion	/* Structs */
# pragma region "Prototypes"
/* Extern */
	//...

/* Global */
	// put.c

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);

/* Static */
	//...

# pragma endregion	/* Prototypes */

#endif	/* PUT_H */