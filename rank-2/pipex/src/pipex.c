/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:53:45 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/11 15:34:17 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Header |----- */
// Global
#include "struct.h"
#include "type.h"

// Modules
#include "init.h"
#include "parsing_args.h"
#include "parsing_env.h"

// Internes
//...

#ifdef BONUS && BONUS == 1

#include "bonus.h"	//@todo

int	main(int argc, const char *argv[], const char *envp[])
{
	
}

# else

int	main(int argc, const char *argv[], const char *envp[])
{
	const t_args	args = parse_args(argc, argv, envp);
	const t_cmd		cmd[2] = parse_cmd(args);
}

#endif	// BONUS
