/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stack.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:33:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/14 15:51:26 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_H
# define _STACK_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_nb		t_nb;
typedef struct s_stack	t_stack;
typedef struct s_func	t_func;

struct s_nb
{
	int	value;	// the nb value in the stack
	int	index;	// the index of the nb in the sorted stack
};

struct s_stack
{
	t_nb		*array;	// the array of nb
	const int	size;	// the size of the stack
	const char	name;	// the name of the stack
};


#endif	/* STACK_H */