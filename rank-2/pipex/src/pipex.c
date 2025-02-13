/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:53:45 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 10:47:36 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Header |----- */
// Global
#include "struct.h"
#include "type.h"
#include <stdlib.h>

// Modules
#include "init.h"
#include "parsing_args.h"
#include "parsing_env.h"
#include "debug.h"
#include "utils.h"

// Internes
//...

#if defined(BONUS) && BONUS == 1

#include "bonus.h"	//@todo

int	main(int argc, const char *argv[], const char *envp[])
{
	
}

# else

int	main(int argc, const char *argv[], const char *envp[])
{

}

#endif	// BONUS
