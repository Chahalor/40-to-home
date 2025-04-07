/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:13:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/07 11:15:09 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
	//...

// Global
#include "type.h"

// Modules
#include "formating.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
int	is_nbr(const char *str)
{
	register int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		else
			++i;
	}
	return (1);
}

#pragma endregion "Functions"