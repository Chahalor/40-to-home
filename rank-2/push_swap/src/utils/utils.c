/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:22:11 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/18 15:46:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
// System
//...

// Global
#include "_utils.h"

// Modules
//...

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((cold, unused, noreturn, pure))
void	exiting(const int error, const char *message)
{
	if (message)
	{
		if (error)
			ft_printf(RED "%s\n" RESET, message);
		else
			ft_printf("%s\n", message);
	}
	exit(error);
}

#pragma endregion	/* Functions */