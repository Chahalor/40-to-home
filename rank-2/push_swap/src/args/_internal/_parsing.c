/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:39:09 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 13:24:42 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Header"

#include "_parsing.h"
#include "parsing.h"

#pragma endregion	/* Header */
#pragma region "Functions"

/** */
__attribute__((unused, cold))
t_algo	choose_algo(const char *algo, t_error *err)
{
	if (ft_strncmp(algo, "turkish", 7) == 0 || (algo[0] == '1'))
		return (e_turkish);
	else if (ft_strncmp(algo, "radix", 5) == 0 || algo[0] == '0')
		return (e_radix);
	else if (ft_strncmp(algo, "random", 6) == 0 || algo[0] == '2')
		return (e_random);
	else if (ft_strncmp(algo, "miracle", 7) == 0 || algo[0] == '3')
		return (e_miracle);
	else
	{
		*err = EINVAL;
		return (e_invalide);
	}
}

/** */
__attribute__((cold))
void	parse_short_options(const int argc, const char **argv,
	int *i, t_args *args)
{
	const char	c = argv[*i][1];

	if (c == 'h')
		args->help = true;
	else if (*i + 1 <= argc)
		args->error = EINVAL;
	else if (c == 's')
		args->stack = _parse_stack(argc, argv, i, args);
	else if (c == 'a')
		args->algo = choose_algo(argv[++(*i)], &args->error);
	else
		args->error = EINVAL;
}

/** */
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
	else if (ft_strncmp(option, "--algo", 6) == 0)
		args->algo = choose_algo(argv[++(*i)], &args->error);
	else
		args->error = EINVAL;
}
/** */
__attribute__((cold))
t_error	check_stack(const char *stack)
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
	return (succes);
}

#pragma endregion	/* Functions */