/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:13:12 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 15:33:45 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Header |----- */
// Global
#include "struct.h"
#include "type.h"

// Modules
//...

// Internes
# include "interne/i_parsing_args.h"

/**
 * 
 */
__attribute__((cold, unused)) static char *p_getenv(const char *envp[],
	const char *target)
{
	char	*path;

	while (*envp && ft_strncmp(*envp, target, ft_strlen(target)) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	path = ft_strdup(*envp + ft_strlen(target) + 1);
	if (!path)
		exiting(malloc_error, "Malloc error", NULL, NULL);
	return (path);
}

__attribute__((cold)) t_args	parse_args(int argc, const char *argv[],
	const char *envp[])
{
	t_args	args;

	if (argc < 5)
		exiting(invalid_arg, "Invalid arguments", NULL, NULL);
	args.file_in = argv[1];
	args.file_out = argv[argc - 1];
	args.path = p_getenv(envp ,"PATH");
	args.envp = envp;
	args.cmd = argv + 2;
	return (args);
}
