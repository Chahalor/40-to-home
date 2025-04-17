/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:10:13 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/15 14:57:05 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* Global   */
#include "config.h"
#include "types.h"
#include <stdio.h>
#include <stdarg.h>

/* Internal */
// #include "_utils.h"
#include "debug.h"

/* Modules  */
#include "dico.h"
#include "args.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((used, always_inline)) inline void	debug_print_dico(
	const t_dico *dico
)
{
	#if DEBUG == 0
		(void)dico;
		return ;
	#else
		printf("dico (%p):\n", dico);
		if (__builtin_expect(dico == NULL, UNEXPECTED))
			return ;
		printf("├──path: %s\n", dico->path);
		printf("├──size: %d\n", dico->size);
		printf("└──error: %d\n", dico->error);
	#endif
}

/** */
__attribute__((used, always_inline)) inline void	debug_print_args(
	const t_args *args
)
{
	#if DEBUG == 0
		(void)args;
		return ;
	#else
		register int	i = 0;

		printf("args (%p):\n", args);
		if (__builtin_expect(args == NULL, UNEXPECTED))
			return ;
		printf("├──argc: %d\n", args->argc);
		printf("├──argv: %p\n", args->argv);
		while (++i < args->argc)
			printf("│   ├──argv[%d]: %s\n", i, args->argv[i]);
		printf("├──help: %d\n", args->help);
		printf("├──version: %d\n", args->version);
		printf("└──error: %d\n", args->invalid);
	#endif
}

/** */
__attribute__((used, always_inline)) inline void	debug_print(
	char *str, ...
)
{
	#if DEBUG == 0
		(void)str;
		return ;
	#else
		va_list	args;
		va_start(args, str);
		vfprintf(stdout, str, args);
		va_end(args);
	#endif
}

#pragma endregion Functions