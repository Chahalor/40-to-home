/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:08:36 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/05 14:05:44 by nduvoid          ###   ########.fr       */
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
// Stack
void		free_stack(t_stack *stack);
t_bool		is_in_stack(t_stack *stack, int content);
t_bool		is_sorted(t_stack *stack);
t_bool		is_nbr(const char *str);
t_stack		*init_stack(int argc, const char **argv);


// Instructions
void		sa();
void		sb();
void		ss();
void		pa();
void		pb();
void		ra(t_bool w);
void		rb(t_bool w);
void		rr();
void		rra(t_bool w);
void		rrb(t_bool w);
void		rrr();


// radix sort msd
void		radix_sort(void);
int			max_value(t_stack *stack);
void		push_signi(t_stack **stack_a, t_stack **stack_b, int signi, int max);
int			get_digit(int value);

// debug
void	print_stack(t_stack *stack);

#endif	/* PUSH_SWAP_H */