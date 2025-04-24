/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:53:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 13:18:57 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/time.h>

// Global
#include "type.h"

// Modules
#include "formating.h"
#include "utils.h"

#pragma endregion "Headers"
#pragma region "Functions"

/**
 * @brief Get the current time in milliseconds. (nb milliseconds since epoch)
 * 
 * @param void
 * 
 * @return int The current time in milliseconds, or -1 on error.
*/
__attribute__((always_inline, used)) inline int	get_ms_time(void)
{
	struct timeval	tv;

	if (__builtin_expect(gettimeofday(&tv, NULL), unexpected))
		return (-1);
	else
		return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/**
 * @brief Sleep for a given time in microseconds.
 * 
 * @param time Time to sleep in microseconds.
 * 
 * @return void
 */
__attribute__((hot)) void	ft_usleep(
	const int time
)
{
	const int	start = get_ms_time();

	while ((get_ms_time() - start) < time)
		usleep(100);
}

#pragma endregion "Functions"