/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:58:17 by nduvoid           #+#    #+#             */
/*   Updated: 2025/04/24 13:36:30 by nduvoid          ###   ########.fr       */
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
	printf(RED ERROR RESET "%s", error.message);
	if (error.localisation)
		printf("(at %s)\n", error.localisation);
	else
		printf("\n");
	printf(PADD5 "error code: %d\n", error.error);
	printf(PADD "%s\n", error.info);
}

/** */
__attribute__((cold))	int	error_manager(
	int request,
	void *data
)
{
	static t_error	errors[MAX_ERROR] = {0};
	static int		error_count = 0;
	static int		last_error = 0;

	if (request == er_request_new)
	{
		last_error = error_count;
		errors[(error_count + 1) % MAX_ERROR] = *(t_error *)data;
		error_count = error_count + (1 * (error_count < MAX_ERROR));
	}
	else if (request == er_request_print)
	{
		if (!error_count || !data)
			return (0);
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