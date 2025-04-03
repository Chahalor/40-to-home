/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:53:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 13:52:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
#include "debug.h"
#include "_debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief this function is used to print the stack struct
 * 
 * @param stack the stack to print
 * 
 * @return void
 * 
 * @note if DEBUG is set to 0, this function will do nothing
*/
__attribute__((cold, unused))
void	print_stack(const t_stack *stack)
{
	return (_print_stack(stack));
}

/**
 * @brief this function is used to print the args struct
 * 
 * @param args the args to print
 * 
 * @return void
 * 
 * @note if DEBUG is set to 0, this function will do nothing
 */
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

/**
 * @brief this function is used to print debug messages
 * 
 * @param str the string to print
 * 
 * @return void
 * 
 * @note if DEBUG is set to 0, this function will do nothing
*/
__attribute__((cold, unused))
void	print_debug(const char *str)
{
	(void)str;
}

#endif
#pragma endregion	/* Functions */