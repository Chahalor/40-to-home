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
# include "get_next_line.h"

/* Defines */
// ...

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

t_bool	is_digits(char *str);
t_bool	in_array(int *array, int size, int value);
int		ft_atoi(const char *nptr);
void	extand_instruct(char ***instructions, char *line, int size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif