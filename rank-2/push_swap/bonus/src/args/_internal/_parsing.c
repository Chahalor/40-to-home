/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:39:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/01 16:34:25 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"

#include "_parsing.h"
#include "parsing.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/**
 * @brief	Parses the short options from the command line arguments.
 * 
 * @param	argc	The number of arguments.
 * @param	argv	The arguments.
 * @param	i		The index of the current argument.
 * @param	args	The arguments structure.
 * 
 * @return	void
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
	else if (*i + 1 <= argc)
		args->error = EINVAL;
	else if (c == 's')
		args->stack = _parse_stack(argc, argv, i, args);
	else
		args->error = EINVAL;
}

/**
 * @brief	Parses the long options from the command line arguments.
 * 
 * @param	argc	The number of arguments.
 * @param	argv	The arguments.
 * @param	i		The index of the current argument.
 * @param	args	The arguments structure.
 * 
 * @return	void
*/
__attribute__((cold))
void	parse_long_options(const int argc, const char **argv,
	int *i, t_args *args)
{
	const char	*option = argv[*i];

	if (ft_strncmp(option, "--help", 6) == 0)
		args->help = true;
	else if (*i + 1 <= argc)
		args->error = EINVAL;
	else if (ft_strncmp(option, "--stack", 8) == 0)
		args->stack = _parse_stack(argc, argv, i, args);
	else
		args->error = EINVAL;
}

/** */
__attribute__((cold))
int	check_stack(const char *stack)
{
	int	i;

	if (stack == NULL)
		return (EINVAL);
	i = -1;
	while (stack[++i])
	{
		if (!ft_isdigit(stack[i]) && stack[i] != '-' && stack[i] != '+'
			&& stack[i] != ' ')
			return (EINVAL);
	}
	return (0);
}

#pragma endregion	/* Functions */