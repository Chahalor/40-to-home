/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:41:39 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/13 09:52:12 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Header |----- */
// Global
#include "struct.h"
#include "type.h"

// Modules
//...

// Internes
# include "interne/_init.h"

__attribute__((cold, unused)) t_args	*init_args(t_args *args)
{
	if (!args)
		return (NULL);
	args->file_in = NULL;
	args->file_out = NULL;
	args->path = NULL;
	args->envp = NULL;
	args->cmd = NULL;
	return (args);
}
