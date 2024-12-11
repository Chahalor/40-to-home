/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:08:36 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/11 15:32:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
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

# ifndef DEBUG
#  define DEBUG 0
# endif

/* ENUM */

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum r_output
{
	GOOD,
	STACK_SORTED,
	MALLOC_ERROR,
	ARG_ERROR,
	STACK_ERROR
}	t_output;

/* STRUCTS */

typedef struct s_stack
{
	int	*stack;
	int	size;
}	t_stack;

typedef struct s_all
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_all;

/* PROTOTYPES */

// stack.c

t_bool	is_digits(const char *str);
t_bool	in_stack(t_stack *stack, int value);
t_all	*init_all(int argc, const char *argv[]);

// instructions 

void	sa(t_all *all);
void	sb(t_all *all);
void	ss(t_all *all);
void	pa(t_all *all);
void	pb(t_all *all);
void	ra(t_all *all);
void	rb(t_all *all);
void	rr(t_all *all);
void	rra(t_all *all);
void	rrb(t_all *all);
void	rrr(t_all *all);

// probalby not needed
t_bool	is_instruction(char *target);
void	do_instructions(t_all *all, char *instructs);

// utils.c

void	exiting(int code);
int		get_max(t_stack *stack);
int		get_poss(t_stack *stack, int max);
int		get_expo(int max);

// radix.c

void	radix(t_all *all);

# if DEBUG
// debuger.c

void	print_stack(t_stack *stack);
void	print_all(t_all *all);

# endif /* DEBUG */

#endif	/* PUSH_SWAP_H */