/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _debug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:28:37 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/02 13:57:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
#include "_debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/*
	ft_printf("├──map->max = %d\n", map->max);
	ft_printf("├──map->width = %d\n", map->width);
	ft_printf("└──map->height = %d\n", map->height);
*/

/** */
__attribute__((cold, unused))
void	_print_stack(const t_stack *stack)
{
	int	i;

	if (DEBUG == 0)
		return ;
	else if (stack == NULL)
	{
		ft_printf("stack is" RED "NULL\n" RESET);
		return ;
	}
	ft_printf("stack %c (%p):\n", stack->name, stack);
	ft_printf("├──stack->size = %d\n", stack->size);
	ft_printf("├──stack->max_size = %d\n", stack->max_size);
	ft_printf("└──stack->array = %p\n", stack->array);
	i = -1;
	while (++i < stack->size)
	{
		if (i == stack->size - 1)
			ft_printf("   └──");
		else
			ft_printf("   ├──");
		ft_printf("stack->array[%d] = {.value=%d, .index=%d}\n", i,
			stack->array[i].value, stack->array[i].index);
	}
}

/** */
__attribute__((cold, unused))
void	_print_args(const t_args *args)
{
	if (DEBUG == 0)
		return ;
	else if (args == NULL)
	{
		ft_printf("args is" RED "NULL\n" RESET);
		return ;
	}
	ft_printf("args (%p):\n", args);
	ft_printf("├──args->argc = %d\n", args->argc);
	ft_printf("├──args->argv = %p\n", args->argv);
	ft_printf("├──args->stack = %p\n", args->stack);
	ft_printf("├──args->len_stack = %d\n", args->len_stack);
	ft_printf("├──args->algo = %d\n", args->algo);
	ft_printf("├──args->error = %d\n", args->error);
	ft_printf("└──args->help = %d\n", args->help);
}

#pragma endregion	/* Functions */