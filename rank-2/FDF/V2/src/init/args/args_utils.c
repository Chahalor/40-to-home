/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:42:15 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/10 12:43:26 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/internal_args.h"

/**
 * @brief Check if the short option is valid.
 * 
 *  - type: 0 = no args after, 1 = 1 arg after.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @param pos The position of the argument.
 * @param nb_args The number of arguments after the option.
 * 
 * @return True if the option is valid, otherwise False.
 */
__attribute__((hot)) int	is_valid_soption(const int argc,
	const char *argv[], int pos, int nb_args)
{
	if (pos >= argc)
		return (false);
	if (argv[pos][0] != '-' || ft_strlen(argv[pos]) != 2
		|| pos + nb_args >= argc)
		return (false);
	return (true);
}

/**
 * @brief Check if the long option is valid.
 * 
 *  - type: 0 = no args after, 1 = 1 arg after.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @param pos The position of the argument.
 * @param nb_args The number of arguments after the option.
 * 
 * @return True if the option is valid, otherwise False.
 */
__attribute__((hot)) int	vl(const int argc, const char *argv[],
	int pos, int nb_args)
{
	if (pos >= argc)
		return (false);
	if (ft_strncmp(argv[pos], "--", 2) != 0 || pos + nb_args >= argc)
		return (false);
	return (true);
}
