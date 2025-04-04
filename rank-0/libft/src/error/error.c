/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:24:18 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/04 10:58:26 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Includes"

/* Systeme */
	//...

/* Global */
	//...

/* Modules */
#include "formating.h"
#include "error.h"
#include "str.h"

#pragma endregion	/* Includes */
#pragma region "Functions"

/** */
__attribute__((cold, unused, noreturn)) void ft_exit(const int code,
	const char *msg)
{
	if (msg)
	{
		if (code)
			write(1, RED "Error: " RESET, 17);
		write(1, msg, ft_strlen(msg));
	}
	exit(code);
}

/** */
__attribute__((cold, unused, noreturn)) void exiting(const int errno,
	const char *msg)
{
	if (msg)
	{
		if (errno)
			write(1, RED "Error: " RESET, 17);
		write(1, msg, ft_strlen(msg));
	}
	exit(errno);
}

#pragma endregion	/* Functions */