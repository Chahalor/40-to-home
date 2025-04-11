/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:26:45 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/09 14:46:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

// Global
#include "../global/type.h"

// Modules
#include "formating.h"
#include "utils.h"

#pragma endregion "Headers"
#pragma region "Functions"

/**
 * @brief Write a formatted error message to stderr
 * 
 * @param msg The error message
 * 
 * @return void
 * 
 * @note It take the error message from the set_error function to write it
 */
__attribute__((always_inline)) inline void	ft_error(const char *msg)
{
	if (msg)
		printf(RED ERROR RESET "%s\n", msg);
	else
		printf(RED ERROR RESET "Unknown error\n");
}

#pragma endregion "Functions"