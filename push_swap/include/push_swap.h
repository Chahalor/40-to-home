/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:08:36 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/04 12:46:38 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>	// rm

/* DEFINE */
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

/* STRUCT */
typedef struct s_stack
{
	int *stack;
	int size;
}	t_stack;

/* ENUM */
enum e_error 
{
	SUCCESS,
	SORTED,
	MALLOC_ERROR,
	INVALIDE_STACK
};

/* TYPEDEF */
typedef enum e_bool
{
	false,
	true
}	t_bool;

/* PROTOTYPE */


t_list	*create_node(void *value);
void	free_stack(t_list **stack);
t_bool	is_in_stack(t_list *stack, void *value);
t_list	*init_stack(int argc, const char **argv);
int		get_stack_size(t_list *stack);
void	add_top_stack(t_list **stack, t_list *new);
t_bool	is_sorted(t_list *stack);

// debug
void	print_stack(t_list *stack);

#endif	/* PUSH_SWAP_H */