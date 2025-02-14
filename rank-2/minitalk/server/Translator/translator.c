/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:47:25 by nduvoid           #+#    #+#             */
/*   Updated: 2025/02/14 16:44:49 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* -----| Headers |----- */
#include "interne/_Translator.h"

/* -----| Functions |----- */

__attribute__((hot))	t_serveur	*get_serveur(void)
{
	static t_serveur	serveur = {0};

	if (serveur.serveur_pid == 0)
		serveur = (t_serveur){
			.serveur_pid = getpid(),
			.hear = signal_handler,
			.translator = translator,
			.talker = ft_printf,
		};
	return (&serveur);
}

int	get_char_size(const int buff[HEAR_BUFF], const int count, int start)
{
	int	size;
	int	i;

	size = 0;
	i = start - 1;
	while (++i < count && buff[i] == 1)
		size++;
	return (size);
}

__attribute__((unused)) void	translator(const int buff[HEAR_BUFF],
	const int count)
{
	char	*msg;
	int		i;
	int		char_size;
	int		j;

	msg = (char *)malloc(sizeof(char) * count + 1);
	if (msg == NULL)
		return ;
	i = -1;
	j = 0;
	while (++i < count)
	{
		char_size = get_char_size(buff, count, i);
		while (char_size--)
		{
			msg[j] <<= 1;
			msg[j] |= buff[i++];
		}
		j++;
	}
	msg[j] = '\0';
}
