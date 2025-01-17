/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:53:51 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/17 08:53:51 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*=- Header -=*/

// Global
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

// Local
# include "libft.h"

/*=- Defines -=*/
//...

/*=- enums -=*/

enum	e_error
{
	NO_ERROR,
	ARG_ERROR,
	OPEN_ERROR,
	CLOSE_ERROR,
	FORK_ERROR,
	PIPE_ERROR,
}

/*=- Typedef -=*/

typedef enum e_error	t_error;

/*=- Struct -=*/

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	char	**cmd1;
	char	**cmd2;
}			t_pipex;

/*=- Functions -=*/
//...

#endif // PIPEX_H