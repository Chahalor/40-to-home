/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 08:19:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 08:36:24 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_H
# define IS_H

# pragma once

# pragma region "Includes"
/* Systeme */
	//...

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
	// is_char.c

int	ft_isdigit(const int c);
int	ft_isalpha(const int c);
int	ft_isalnum(const int c);
int	ft_isascii(const int c);
int	ft_isprint(const int c);

	// is_str.c

int	ft_isnumber(const char *str);

/* Static */
	//...

# pragma endregion	/* Prototypes */

#endif	/* IS_H */