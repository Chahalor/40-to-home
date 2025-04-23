/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:28:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/23 13:53:53 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
	//...

/* -----| Modules  |----- */
#include "parsing.h"
#include "utils.h"
#include "debug.h"

#pragma endregion Headers
#pragma region Functions

int main(int argc, const char **argv)
{
	const t_args	args = parse_args(argc, argv);
	t_mutex			*forks;
	t_philo			*philosophers;

	if (unexpect(args.error || args.help))
		return (1);
	init_all(&forks, &philosophers, args.data);
	launch_simu(philosophers, args.data);
	destroy_mutex(&forks, args.data.nb_philo * 3);
	destroy_philos(&philosophers, args.data.nb_philo);
	return (0);
}
#pragma endregion Functions