/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:22:50 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/07 15:18:15 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cryptography.h"

static void	build_sbox(int *s_box, const char *key)
{
	int			i;
	int			j;
	int			temp;
	const int	key_length = ft_strlen(key);

	if (key_length == 0)
		return ;
	i = -1;
	while (++i < S_BOX_SIZE)
		s_box[i] = i;
	i = -1;
	j = 0;
	while (++i < S_BOX_SIZE)
	{
		j = (j + s_box[i] + key[i % key_length]) % 256;
		temp = s_box[i];
		s_box[i] = s_box[j];
		s_box[j] = temp;
	}
}

static void	encrypting(int *s_box, char *msg, char *cipher, int len_msg)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	while (len_msg--)
	{
		i = (i + 1) % 256;
		j = (j + s_box[i]) % 256;
		temp = s_box[i];
		s_box[i] = s_box[j];
		s_box[j] = temp;
		*cipher++ = *msg++ ^ s_box[(s_box[i] + s_box[j]) % 256];
	}
}

__attribute__((malloc)) char	*f_rc4(char *key, char *msg, int len_msg)
{
	int		S[S_BOX_SIZE];
	char	*cipher;

	if (!key || !msg)
		return (NULL);
	else if (key[0] == '\0' || msg[0] == '\0')
		return (ft_strdup(msg));
	build_sbox(S, key);
	cipher = malloc(len_msg + 1);
	if (!cipher)
		return (NULL);
	encrypting(S, msg, cipher, len_msg);
	return (cipher);
}
