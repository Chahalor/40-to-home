/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:36:28 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/09 10:36:28 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/tester.h"

/**
 * @brief check if the string is a number
 * 
 * @example "123" => TRUE
 * @example "-123" => TRUE
 * @example "+123" => TRUE
 * @example "123a" => FALSE
 * 
 * @param str: the string to check
 * @return
 * 
 * - TRUE if the string is a number
 * 
 * - FALSE if the string is not a number
 */
t_bool	is_digits(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * @brief check if the string is an white space
 * 
 * @example "sa" => FALSE
 * @example " " => TRUE
 * @example "\n" => TRUE
 * 
 * @param c: the character to check
 * @return
 * 
 * - TRUE if the character is a white space
 * 
 * - FALSE if the character is not a white space
 */
static int	is_space(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

/**
 * @brief convert a string to an integer
 * 
 * @example "123" => 123
 * @example "-123" => -123
 * @example "+123" => 123
 * @example "123a" => 123
 * 
 * @param nptr: the string to convert
 * @return the integer
 */
int	ft_atoi(const char *nptr)
{
	int		r;
	size_t	i;
	int		neg;

	neg = 1;
	r = 0;
	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	return (r * neg);
}

/**
 * @brief calloc a new array of instructions, copy the old one and free it
 * 
 * @param instructions: the instructions array
 * @param size: the new size
 * @return
 * 
 * - the new array of instructions
 * 
 * - NULL if an error occured (Most likely a malloc error)
 */
char	**extand_instruct(char **instructions, int size)
{
	char	**new;
	int		i;

	new = (char **)ft_calloc(size, sizeof(char *));
	if (!new)
		return (free_instructions(instructions), NULL);
	i = 0;
	while (i < size - 1)
	{
		new[i] = instructions[i];
		i++;
	}
	new[i] = NULL;
	free(instructions);
	instructions = NULL;
	return (new);
}

/**
 * @brief free the instructions array, by freeing each instruction and 
 * the array itself
 * 
 * @param instructions: the instructions array
 * @return void
 */
void	free_instructions(char **instructions)
{
	int	i;

	i = 0;
	while (instructions[i])
		free(instructions[i++]);
	free(instructions[i]);
	free(instructions);
	instructions = NULL;
}
