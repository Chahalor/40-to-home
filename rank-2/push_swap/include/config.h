/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:27:30 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/08 15:18:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# pragma once

# pragma region "Header"
// Systeme
	//...

// Libs
	//...

// Local
	//...

# pragma endregion	/* Header */

# pragma region "Define"

// Compilation configuration

# ifndef BONUS
#  define BONUS	0		// 1 to compile bonus part
# endif	/* BONUS */

# ifndef DEBUG
#  define DEBUG	0		// 1 to compile debug part
# endif	/* DEBUG */

# define NB_ALGO	3	// number of algorithms

# define PARSING_ALLOC_SIZE	1024

// miscellaneous define

# define ALLOW_COLOR	1	// 1 to allow color in printf
# if ALLOW_COLOR == 1

#  define RED		"\033[31m"	/* 255;0;0 */
#  define GREEN		"\033[32m"	/* 0;255;0 */
#  define BLUE		"\033[34m"	/* 0;0;255 */
#  define YELLOW	"\033[33m"	/* 255;255;0 */
#  define RESET		"\033[0m"	/* 255;255;255 */

# else

#  define RED		""	/* 255;0;0 */
#  define GREEN		""	/* 0;255;0 */
#  define BLUE		""	/* 0;0;255 */
#  define YELLOW	""	/* 255;255;0 */
#  define RESET		""	/* 255;255;255 */

# endif	/* ALLOW_COLOR */

# define STDIN	0			// standard input
# define STDOUT	1
# define STDERR	2

# pragma endregion	/* Define */

# pragma region "Macro"
//...
# pragma endregion	/* Macro */

# pragma region "Typedef"
//...
# pragma endregion	/* Typedef */

# pragma region "Enum"
//...
# pragma endregion	/* Enum */

# pragma region "Union"
//...
# pragma endregion	/* Union */

# pragma region "Struct"
//...
# pragma endregion	/* Struct */

# pragma region "Prototype"
//...
# pragma endregion	/* Prototype */

# pragma region "Static"
//...
# pragma endregion	/* Static */

# pragma region "Extern"
//...
# pragma endregion	/* Extern */

# pragma region "Inline"
//...
# pragma endregion	/* Inline */

#endif	/* CONFIG_H */