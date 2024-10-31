/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:47:30 by nduvoid           #+#    #+#             */
/*   Updated: 2024/10/27 08:47:30 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	// int fd_langueur = open("test/langueur.txt", O_RDONLY);
	// int	fd_endormie = open("test/a_ma_femme_endormie.txt", O_RDONLY);

	// char	*str_l = NULL;
	// char	*str_e = NULL;
	// str_l = get_next_line(fd_langueur);
	// str_e = get_next_line(fd_endormie);
	// while (str_e || str_l)
	// {

	// 	printf("langueur : %s", str_l);
	// 	printf("endormie : %s", str_e);
	// 	if (str_l)
	// 		free(str_l);
	// 	if (str_e)
	// 		free(str_e);
	// 	str_l = get_next_line(fd_langueur);
	// 	str_e = get_next_line(fd_endormie);
	// }
	// close(fd_langueur);
	// close(fd_endormie);

	// /*stdi reading*/
	// int i = 0;
	// while (i++ < BUFFER_SIZE)
	// {
	// 	printf("sti : %s", get_next_line(0));
	// }
	
	int	fd = open("test/1char.txt", O_RDONLY);
	char	*vide = NULL;
	printf("r : %s, exepted : %s", get_next_line(fd), "a");
	printf("r : %s, exepted : %s", get_next_line(fd), vide);
	close(fd);
}
