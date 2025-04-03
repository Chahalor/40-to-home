/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:39:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/03 14:38:59 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"

#include "_parsing.h"
#include "parsing.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief parse algorithm
 * 
 * @param algo the algo to parse
 * @param err the error code
 * 
 * @return t_algo the parsed algo
 */
__attribute__((used, cold, always_inline))
static inline t_algo	choose_algo(const char *algo, t_error *err)
{
	if (ft_strncmp(algo, "chunk", 7) == 0 || (algo[0] == '1'))
		return (e_chunk);
	else if (ft_strncmp(algo, "turkish", 5) == 0 || algo[0] == '2')
		return (e_turkish);
	else if (ft_strncmp(algo, "random", 6) == 0 || algo[0] == '3')
		return (e_random);
	else if (ft_strncmp(algo, "miracle", 7) == 0 || algo[0] == '4')
		return (e_miracle);
	else
	{
		*err = EINVAL;
		return (e_invalide);
	}
}

/**
 * @brief parse the short options
 * 
 * @param argc the number of args passed to the programme
 * @param argv the args passed to the programme
 * @param i the index of the current arg
 * @param args the args struct
 * 
 * @return void
 */
__attribute__((cold))
void	parse_short_options(const int argc, const char **argv,
	int *i, t_args *args)
{
	const char	c = argv[*i][1];

	if (c == 'h')
		args->help = true;
	else if (ft_isdigit(c))
		args->stack = _parse_stack(argc, argv, i, args);
	else if (*i + 1 >= argc)
		args->error = EINVAL;
	else if (c == 'a')
		args->algo = choose_algo(argv[++(*i)], &args->error);
	else
		args->error = EINVAL;
}

/**
 * @brief parse long options
 * 
 * @param argc the number of args passed to the programme
 * @param argv the args passed to the programme
 * @param i the index of the current arg
 * @param args the args struct
 * 
 * @return void
 */
__attribute__((cold))
void	parse_long_options(const int argc, const char **argv,
	int *i, t_args *args)
{
	const char	*option = argv[*i];

	if (ft_strncmp(option, "--help", 6) == 0)
		args->help = true;
	else if (*i + 1 >= argc)
		args->error = EINVAL;
	else if (ft_strncmp(option, "--algo", 6) == 0)
		args->algo = choose_algo(argv[++(*i)], &args->error);
	else
		args->error = EINVAL;
}

/**
 * @brief check if the stack is valid
 * 
 * @param stack the stack to check
 * 
 * @return t_error the error code
 */
__attribute__((cold))
t_error	check_stack(const char *stack)
{
	register int	i;

	if (stack == NULL)
		return (EINVAL);
	i = -1;
	while (stack[++i])
	{
		if (!ft_isdigit(stack[i]) && stack[i] != '-' && stack[i] != '+'
			&& stack[i] != ' ')
			return (EINVAL);
	}
	return (succes);
}

#pragma endregion	/* Functions */