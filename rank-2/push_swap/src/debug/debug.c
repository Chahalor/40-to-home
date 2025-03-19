/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:53:58 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/19 13:57:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"
#include "debug.h"

#pragma endregion	/* Header */
#pragma region "Functions"

#if DEBUG == 0

/** */
__attribute__((cold, unused))
void	print_stack(const t_stack *stack)
{
	(void)stack;
}

/** */
__attribute__((cold, unused))
void	print_args(const t_args *args)
{
	(void)args;
}

#else

/*
	ft_printf("├──map->max = %d\n", map->max);
	ft_printf("├──map->width = %d\n", map->width);
	ft_printf("└──map->height = %d\n", map->height);
*/

/** */
__attribute__((cold, unused))
void	print_stack(const t_stack *stack)
{
	int	i;

	if (stack == NULL)
	{
		ft_printf("stack is" RED "NULL\n" RESET);
		return ;
	}
	ft_printf("stack %c (%p):\n", stack->name, stack);
	ft_printf("├──stack->size = %d\n", stack->size);
	ft_printf("├──stack->max_size = %d\n", stack->max_size);
	ft_printf("├──stack->array = %p\n", stack->array);
	i = -1;
	while (++i < stack->size)
	{
		if (i == stack->size - 1)
			ft_printf("   └──");
		else
			ft_printf("   ├──");
		ft_printf("stack->array[%d] = {.value=%d, .index=%d}\n", i, stack->array[i].value,
			stack->array[i].index);
	}
}

/** */
__attribute__((cold, unused))
void	print_args(const t_args *args)
{
	if (args == NULL)
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

#endif	/* DEBUG */
#pragma endregion	/* Functions */