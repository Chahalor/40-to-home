/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:17:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/14 15:32:47 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <string.h>
#include <unistd.h>
#include <stdio.h>

// Global
#include "type.h"
#include "config.h"

// Modules
#include "utils.h"

#pragma endregion "Headers"
#pragma region "Functions"

/**
 * @brief	print the ANSI color code for the given RGB value.
 * 
 * @param rgb The RGB value to print.
 * 
 * @return void
 * 
 * @note - The RGB value is expected to be in the format 0xRRGGBB.
 * @note - This function is always inlined
 */
__attribute__((always_inline, used)) void	print_rgb_ansi(
	const int rgb
)
{
	printf("\033[38;2;%d;%d;%dm", (rgb >> 16) & 0xFF,
		(rgb >> 8) & 0xFF, rgb & 0xFF);
}

#pragma endregion "Functions"