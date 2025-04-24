/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:21:12 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 13:27:16 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"
// System
#include <stdio.h>
#include <errno.h>

// Global
#include "../global/type.h"
#include "../global/config.h"

// Modules
#include "debug.h"

#pragma endregion "Headers"
#pragma region "Functions"

#if DEBUG == 1

/** */
__attribute__((used, always_inline)) inline void	print_args(
	const t_args *args	/* the args structure to print */
)
{
	register int	i;

	printf("args (%p):\n", args);
	if (!args)
		return ;
	printf("├──args->argc = %d\n├──argv (%p)", args->argc, args->argv);
	if (!args->argv || args->argc < 2)
		printf("\n");
	else
	{
		printf(":\n│  └──");
		i = 0;
		while (++i < args->argc)
			printf("\"%s\" ", args->argv[i]);
	}
	printf("\n├──args->help = %d\n", args->help);
	printf("├──args->debug = %d\n", args->debug);
	printf("├──args->data_get = %d\n", args->data_get);
	printf("├──args->error = %d\n", args->error);
	printf("└──args->data = %p\n", &args->data);
	printf("   ├──args->data.nb_philo = %d\n", args->data.nb_philo);
	printf("   ├──args->data.time_to_die = %d\n", args->data.time_to_die);
	printf("   ├──args->data.time_to_eat = %d\n", args->data.time_to_eat);
	printf("   ├──args->data.time_to_sleep = %d\n", args->data.time_to_sleep);
	printf("   └──args->data.nb_meals = %d\n", args->data.nb_meals);
}

/** */
__attribute__((unused, always_inline)) inline void	print_philo(
	const t_philo *philo	/* the philosopher structure to print */
)
{
	printf("philo (%p):\n", philo);
	if (!philo)
		return ;
	printf("├──philo->id = %d\n", philo->id);
	printf("├──philo->left_fork = %p\n", philo->left_fork);
	printf("├──philo->right_fork = %p\n", philo->right_fork);
	printf("├──philo->lock = %p\n", philo->lock);
	printf("├──philo->nb_meals = %d\n", philo->nb_meals);
	printf("├──philo->last_meal = %d\n", philo->last_meal);
	printf("└──philo->state = %d\n", philo->status);
}

#else

/** */
__attribute__((unused, always_inline))
extern inline void	print_args(const t_args *args)
{
	(void)args;
}

/** */
__attribute__((unused, always_inline))
extern inline void	print_philo(const t_philo *philo)
{
	(void)philo;
}

#endif

/** */
__attribute__((unused, always_inline)) extern inline void	print_debug(
	const char *msg
)
{
	if (DEBUG != 0)
		printf("%s\n", msg);
}

#pragma endregion "Functions"