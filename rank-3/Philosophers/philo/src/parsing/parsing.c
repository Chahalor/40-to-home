/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:16:54 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/08 11:06:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"

// _internal
#include "_parsing.h"

// interface
#include "parsing.h"

#pragma endregion "Headers"
#pragma region "Functions"

/**
 * @brief Show the help message (what could i say more)
 * 
 * @param void
 * 
 * @return void
 */
__attribute__((cold, unused, always_inline))
static inline void	_show_help(void)
{
	printf(BLUE "Usage: " RESET "philo [options] [args]\n");
	printf(YELLOW "\nOptions:\n" RESET);
	printf("  -h, --help\t\tShow this help message\n");
	printf("  -d, --debug\t\tEnable debug mode\n");
	printf(YELLOW "\nArguments:\n" RESET);
	printf("  <nb_philo>\t\tNumber of philosophers\n");
	printf("  <time_to_die>\t\tTime to die\n");
	printf("  <time_to_eat>\t\tTime to eat\n");
	printf("  <time_to_sleep>\tTime to sleep\n");
	printf("  <nb_meals>\t\tNumber of meals (optional)\n");
	printf(YELLOW "\nExamples:\n" RESET);
	printf("  philo -h\n");
	printf("  philo --help\n");
	printf("  philo 5 800 200 200\n");
	printf(YELLOW "\nAuthor:\n" RESET);
	printf("  - nduvoid " UNDERLINE "<nduvoid@student.42mulhouse.fr>\n" RESET);
}

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
__attribute__(())
static int	_parse_long_options(const int argc, const char *argv[],
	t_args *args, const int i)
{
	(void)argc;
	if (ft_strncmp(argv[i], "--help", 6) == 0)
		args->help = 1;
	else if (ft_strncmp(argv[i], "--debug", 7) == 0)
		args->debug = 1;
	else
	{
		ft_error("Invalid option");
		printf(PADD "invalid option: %s\n", argv[i]);
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
__attribute__(())
static int	_parse_short_options(const int argc, const char *argv[],
	t_args *args, const int i)
{
	(void)argc;
	if (ft_strncmp(argv[i], "-h", 2) == 0)
		args->help = 1;
	else if (ft_strncmp(argv[i], "-d", 2) == 0)
		args->debug = 1;
	else
	{
		ft_error("Invalid option");
		printf(PADD "invalid option: %s\n", argv[i]);
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
__attribute__((cold))
static int	_parse_data(const int argc, const char **args, t_args *data, int i)
{
	if (argc - i < 4 || argc - i > 5)
	{
		ft_error("Invalid number of arguments");
		printf(PADD "get %d arguments, need 4 or 5\n", argc - 1);
		return (data->error = EINVAL, -1);
	}
	else
	{
		while (i < 5 && is_nbr(args[i]))
		{
			((int *)&data->data)[i - 1] = ft_atoi(args[i]);
			++i;
		}
		if (i != 5)
		{
			ft_error("Invalid argument");
			printf(PADD "invalide number: %s\n", args[i]);
			return (data->error = EINVAL, -1);
		}
		if (i < argc && args[i] && is_nbr(args[i]))
			data->data.nb_meals = ft_atoi(args[i]);
		else
			data->data.nb_meals = -1;
		return (i);
	}
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
t_args	parse_args(int argc, const char *argv[])
{
	t_args	args;
	int		i;

	if (argc <= 1)
	{
		printf(BLUE "Usage: " RESET "%s [options] [args]\n", argv[0]);
		return ((t_args){.error = EINVAL});
	}
	args = (t_args){.argc = argc, .argv = argv, .error = 0};
	i = 0;
	while (++i < argc && !args.error && !args.help)
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
	return (args);
}

#pragma endregion "Functions"