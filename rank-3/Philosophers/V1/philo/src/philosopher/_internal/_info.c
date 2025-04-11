/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _info.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:03:53 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/11 14:45:18 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

// Global
#include "type.h"
#include "config.h"

// Modules
#include "_philosopher.h"
#include "philosopher.h"
#include "utils.h"
#include "debug.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
__attribute__((hot)) int	info_loop(
	void *data
)
{
	(void)data;
	return (0);
}

#pragma endregion "Functions"