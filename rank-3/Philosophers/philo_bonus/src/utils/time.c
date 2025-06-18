/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:53:04 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 09:13:48 by nduvoid          ###   ########.fr       */
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
__attribute__((always_inline, used)) inline t_time	get_ms_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
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
	register const t_time time
)
{
	register const t_time	start = get_ms_time();

	if (__builtin_expect(time <= 0, unexpected))
		return ;
	else if (time < USLEEP_MAGIC_VALUE)
		usleep(time);
	else
		while ((get_ms_time() - start) < time / 1000)
			usleep(USLEEP_MAGIC_VALUE);
}

#pragma endregion "Functions"