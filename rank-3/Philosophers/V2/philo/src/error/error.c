/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:58:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 09:15:50 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma region Headers

/* -----| Internal |----- */
	//...

/* -----| Modules  |----- */
#include "errors.h"

#pragma endregion Headers
#pragma region Functions

/** */
__attribute__((always_inline, used)) static inline void	print_error(
	const t_error error	/* the error to print */
)
{
	printf(RED ERROR "%s" RESET "(at %s)" "\n", error.message,
		error.localisation);
	printf(PADD5 "error code: %d\n", error.error);
	printf(PADD "%s\n" RESET, error.info);
}

/** */
__attribute__((cold))	int	error_manager(
	int request,		/* the request to manage */
	void *data			/* the data to manage */
)
{
	static t_error	errors[MAX_ERROR] = {0};
	static int		error_count = 0;
	static int		last_error = 0;
	register int	i;

	if (request == er_request_new)
	{
		last_error = error_count;
		errors[(error_count++) % MAX_ERROR] = *(t_error *)data;
	}
	else if (request == er_request_print)
	{
		print_error(errors[*(int *)data]);
		last_error = *(int *)data;
	}
	else if (request == er_request_rm)
	{
		if (error_count > 0)
			error_count--;
		errors[*(int *)data] = (t_error){0};
	}
	return (last_error);
}

#pragma endregion Functions