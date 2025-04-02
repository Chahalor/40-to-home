/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:53:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 13:57:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
#include "debug.h"
#include "_debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((cold, unused))
void	print_stack(const t_stack *stack)
{
	return (_print_stack(stack));
}

/** */
__attribute__((cold, unused))
void	print_args(const t_args *args)
{
	return (_print_args(args));
}

#if DEBUG == 1

/** */
__attribute__((cold, unused))
void	print_debug(const char *str)
{
	ft_printf("%s\n", str);
}

#else

/** */
__attribute__((cold, unused))
void	print_debug(const char *str)
{
	(void)str;
}

#endif
#pragma endregion	/* Functions */