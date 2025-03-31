/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:53:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 10:14:26 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
#include "debug.h"
#include "_debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * * @brief	Prints the stack.
 * 
 * * @param	stack	The stack to print.
 * 
 * * * @return	void
 */
__attribute__((cold, unused))
void	print_stack(const t_stack *stack)
{
	return (_print_stack(stack));
}

/**
 * @brief	Prints the arguments.
 * 
 * @param	args	The arguments to print.
 * 
 * @return	void
 */
__attribute__((cold, unused))
void	print_args(const t_args *args)
{
	return (_print_args(args));
}
#pragma endregion	/* Functions */