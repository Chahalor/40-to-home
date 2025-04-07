/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:55:35 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/07 14:55:33 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
	//...

// Global
#include "type.h"

// Modules
#include "parsing.h"
#include "debug.h"

#pragma endregion "Headers"
#pragma region "Functions"

/** */
int	main(int argc, const char *argv[])
{
	const t_args		args = parse_args(argc, argv);
	const t_philo_data	philo_data = args.data;	// can change
	t_philo			*philos;

	(void)philo_data;
	(void)philos;
	if (args.error || args.help)
		return (args.error);
	print_args(&args);
	// philo = build_philos(philo_data);
	// while (???)
	// {
	// 	// philosophers day i suppose
	// }
	// chainsaw(philos);	// should free all the philosophers
	return (0);
}

#pragma endregion "Functions"