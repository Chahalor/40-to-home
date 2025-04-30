/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _info.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:01:46 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/29 13:57:11 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region "Headers"

// _internal
#include "_parsing.h"

// interface
#include "parsing.h"

#pragma endregion "Headers"
#pragma region "Functions"

/**
 * @brief Show the usage message
 * 
 * @param prog The program name
 * 
 * @return void
 */
__attribute__((always_inline, used)) inline void	_show_usage(
	const char *prog	/* program name */
)
{
	if (prog)
		printf(BLUE USAGE RESET SUSAGE_INFO, prog);
	else
		printf(BLUE USAGE RESET USAGE_INFO);
}

/**
 * @brief Show the help message (what could i say more)
 * 
 * @param void
 * 
 * @return void
 */
__attribute__((used, always_inline)) inline void	_show_help(void)
{
	_show_usage(NULL);
	printf(YELLOW "\nOptions:\n" RESET);
	printf("  -h, --help\t\t\tShow this help message\n"
		"  -d [val], --display=[val]\tChoose the display mode\n");
	printf(YELLOW "\nArguments:\n" RESET
		"  <nb_philo>\t\tNumber of philosophers\n"
		"  <time_to_die>\t\tTime to die\n"
		"  <time_to_eat>\t\tTime to eat\n"
		"  <time_to_sleep>\tTime to sleep\n"
		"  <nb_meals>\t\tNumber of meals (optional)\n"
		YELLOW "\nExamples:\n" RESET);
	printf("  philo -h\n"
		"  philo --help\n"
		"  philo -d 1\n"
		"  philo --display=0\n"
		"  philo 5 800 200 200\n");
	printf(YELLOW "\nAuthor:\n" RESET);
	printf("  - nduvoid <" BLUE UNDERLINE "nduvoid@student.42mulhouse.fr" \
		RESET ">\n");
}

#pragma endregion "Functions"