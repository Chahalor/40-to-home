/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:08:48 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/09 10:08:48 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

/* Includes */

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include "get_next_line.h"

/* Defines */
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
# define ERROR "Error\n"
# define ALL {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR}

/* Enum */

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_error
{
	GOOD,
	ARG_ERROR,
	INSTRUCTIONS_ERROR,
	MALLOC_ERROR,
	READ_ERROR
}	t_error;

/* Structures */

typedef	struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}	t_stack;

/* Prototypes */

// utils 

t_bool	is_digits(char *str);
void	free_instructions(char **instructions);
int		ft_atoi(const char *nptr);
char	**extand_instruct(char **instructions, int size);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);

// stacks

t_stack	*init_stacks(int argc, char **argv);
t_bool	is_sorted(int *stack, int size);

// instructions

void	sa(t_stack *stacks);
void	sb(t_stack *stacks);
void	ss(t_stack *stacks);
void	pa(t_stack *stacks);
void	pb(t_stack *stacks);
void	ra(t_stack *stacks);
void	rb(t_stack *stacks);
void	rr(t_stack *stacks);
void	rra(t_stack *stacks);
void	rrb(t_stack *stacks);
void	rrr(t_stack *stacks);
t_bool	is_instruction(char *target);
void	do_instructions(t_stack *stacks, char *instructs);

#endif