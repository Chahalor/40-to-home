/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:08:04 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/09 11:08:04 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(int *stack_a, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
}

void	sb(int *stack_b, int size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = tmp;
}

void	ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	sa(stack_a, size_a);
	sb(stack_b, size_b);
}

void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;

	if (*size_b < 1)
		return ;
	i = *size_a;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < *size_b - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	(*size_a)++;
	(*size_b)--;
}

void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	i;

	if (*size_a < 1)
		return ;
	i = *size_b;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < *size_a - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	(*size_b)++;
	(*size_a)--;
}
