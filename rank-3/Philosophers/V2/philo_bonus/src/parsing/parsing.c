/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:16:54 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/12 17:45:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"

// _internal
#include "_parsing.h"

// interface
#include "parsing.h"
#include "debug.h"

#pragma endregion "Headers"
#pragma region "Functions"

/**
 * @brief Parse the long options
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * @param args The arguments structure
 * @param i The index of the argument
 * 
 * @return The number of arguments parsed
 */
__attribute__((cold)) static int	_parse_long_options(
	const int argc,
	const char *argv[],
	t_args *args,
	const int i
)
{
	(void)argc;
	if (ft_strncmp(argv[i], "--help", 6) == 0)
		args->help = 1;
	else if (ft_strncmp(argv[i], "--display=", 10) == 0)
		args->display = argv[i][10] == '1';
	else
	{
		ft_error("Invalid option");
		printf(PADD "invalid option: \"%s\"\n", argv[i]);
		args->error = EINVAL;
	}
	return (1);
}

/**
 * @brief Parse the short options
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * @param args The arguments structure
 * @param i The index of the argument
 * 
 * @return The number of arguments parsed
 */
__attribute__((cold)) static int	_parse_short_options(
	const int argc,
	const char *argv[],
	t_args *args,
	const int i
)
{
	(void)argc;
	if (ft_strncmp(argv[i], "-h", 2) == 0)
		args->help = 1;
	else if (ft_strncmp(argv[i], "-d", 2) == 0)
	{
		args->display = argv[i + 1][0] == '1';
		return (2);
	}
	else
	{
		ft_error("Invalid option");
		printf(PADD "invalid option: \"%s\"\n", argv[i]);
		args->error = EINVAL;
	}
	return (1);
}

/**
 * @brief Parse the data arguments
 * 
 * @param argc The number of arguments
 * @param args The arguments
 * @param data The arguments structure
 * @param i The index of the argument
 * 
 * @return The number of arguments parsed
 */
__attribute__((cold)) static int	_parse_data(
	const int argc,
	const char *restrict *restrict args,
	t_args *restrict data,
	register int i
)
{
	register int	j;

	if (!_is_valide_args(args, i, argc))
		return (data->error = EINVAL, -1);
	j = -1;
	while (++j < 4)
		((int *)&data->data)[j] = ft_atoi(args[i + j]);
	if (argc - i > 4)
		((int *)&data->data)[j] = ft_atoi(args[i + j]);
	if (__builtin_expect(data->data.nb_philo < 1, unexpected))
	{
		ft_error("Invalid number of philosophers, must be > 0");
		data->error = EINVAL;
		return (-1);
	}
	return (j + 1);
}

/**
 * @brief Parse the arguments
 * 
 * @param argc The number of arguments
 * @param argv The arguments
 * 
 * @return The arguments structure
*/
__attribute__((cold, unused))
t_args	parse_args(
	register int argc,
	const char *argv[]
)
{
	t_args			args;
	register int	i;

	if (argc < 2)
		return (_show_usage(argv[0]), (t_args){.error = EINVAL});
	args = (t_args){.argc = argc, .argv = argv, .data = {-1, 0, -1, -1, -1}};
	i = 1;
	while (i < argc && !args.error && !args.help)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-')
				i += _parse_long_options(argc, argv, &args, i);
			else
				i += _parse_short_options(argc, argv, &args, i);
		}
		else
			i += _parse_data(argc, argv, &args, i);
	}
	if (args.help)
		_show_help();
	print_args(&args);
	return (args);
}

#pragma endregion "Functions"