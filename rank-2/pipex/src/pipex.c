/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 08:52:03 by nduvoid           #+#    #+#             */
/*   Updated: 2025/01/17 08:52:03 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

# ifdef DEBUG

/**
 * @file pipex.c
 * @brief This file contains the main function of the pipex program.
 * 
 * @format ./pipex  < file1 cmd1 | cmd2 > file2
 * @excemple ./pipex infile "ls -l" "wc -l" outfile
 */
int	main(int argc, const char *argv[])
{
	t_args	*args;

	args = parse_args(argc, argv);
	return (0);
}

# else

/**
 * @file pipex.c
 * @brief This file contains the main function of the pipex program.
 * 
 * @format ./pipex  < file1 cmd1 | cmd2 > file2
 * @excemple ./pipex infile "ls -l" "wc -l" outfile
 */
int	main(int argc, const char *argv[])
{
	t_args	*args;

	args = parse_args(argc, argv);
	return (0);
}

# endif

