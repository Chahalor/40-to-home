/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 08:47:30 by nduvoid           #+#    #+#             */
/*   Updated: 2024/11/19 15:58:34 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "../get_next_line.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define NC "\033[0m"

TEST(input, expted) {strcmp(input, expted) == 0 ? printf(GREEN "OK\n" NC) : printf(RED "KO\n" NC); free(input);}

/**
 * @brief Test the get_next_line function
 * @author nduvoid
 * @todo Add more tests, especially for BUFFER_SIZE > 1
 * @todo using argc/v pour commencer a un test en particulier
 */
int main(int argc, const char *argv[])
{
	/* 1char */
	char	*file = ".my_test/1char";
	int		fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" NC, file);
	else
	{
		printf(NC "Test 1char\n");
		TEST(get_next_line(fd), "0");
		TEST(get_next_line(fd), NULL);
	}
	/* one_line */
	file = ".my_test/one_line_no_nl";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" NC, file);
	else
	{
		printf(NC "Test one_line_no_nl\n");
		TEST(get_next_line(fd), "qwertyuiop");
		TEST(get_next_line(fd), NULL);
	}
	/* only nl*/
	file = ".my_test/only_nl";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" NC, file);
	else
	{
		printf(NC "Test only_nl\n");
		TEST(get_next_line(fd), "\n");
		TEST(get_next_line(fd), NULL);
	}
	/* multiple nl */
	file = ".my_test/multiple_nl";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" NC, file);
	else
	{
		printf(NC "Test multiple_nl\n");
		TEST(get_next_line(fd), "\n");
		TEST(get_next_line(fd), "\n");
		TEST(get_next_line(fd), "\n");
		TEST(get_next_line(fd), NULL);
	}
	/* empty */
	file = ".my_test/empty";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" NC, file);
	else
	{
		printf(NC "Test empty\n");
		TEST(get_next_line(fd), NULL);
		TEST(get_next_line(fd), NULL);
	}
	/* limits */
	file = ".my_test/limits";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" NC, file);
	else
	{
		printf(NC "Test limits\n");
		TEST(get_next_line(fd), "0");
		TEST(get_next_line(fd), "1");
		TEST(get_next_line(fd), "2");
		TEST(get_next_line(fd), "3");
		TEST(get_next_line(fd), "4");
		TEST(get_next_line(fd), "5");
		TEST(get_next_line(fd), "6");
		TEST(get_next_line(fd), "7");
		TEST(get_next_line(fd), "8");
		TEST(get_next_line(fd), "9");
		TEST(get_next_line(fd), "10");
		TEST(get_next_line(fd), "11");
		TEST(get_next_line(fd), "12");
		TEST(get_next_line(fd), "13");
		TEST(get_next_line(fd), "14");
		TEST(get_next_line(fd), "15");
		TEST(get_next_line(fd), "16");
		TEST(get_next_line(fd), "17");
		TEST(get_next_line(fd), "18");
		TEST(get_next_line(fd), "19");
		TEST(get_next_line(fd), "20");
		TEST(get_next_line(fd), "21");
		TEST(get_next_line(fd), "22");
		TEST(get_next_line(fd), "23");
		TEST(get_next_line(fd), "24");
		TEST(get_next_line(fd), "25");
		TEST(get_next_line(fd), "26");
		TEST(get_next_line(fd), "27");
		TEST(get_next_line(fd), "28");
		TEST(get_next_line(fd), "29");
		TEST(get_next_line(fd), "30");
		TEST(get_next_line(fd), "31");
		TEST(get_next_line(fd), "32");
		TEST(get_next_line(fd), "33");
		TEST(get_next_line(fd), "34");
		TEST(get_next_line(fd), "35");
		TEST(get_next_line(fd), "36");
		TEST(get_next_line(fd), "37");
		TEST(get_next_line(fd), "38");
		TEST(get_next_line(fd), "39");
		TEST(get_next_line(fd), "40");
		TEST(get_next_line(fd), "41");
		TEST(get_next_line(fd), "42");
		TEST(get_next_line(fd), "43");
		TEST(get_next_line(fd), "44");
		TEST(get_next_line(fd), "45");
		TEST(get_next_line(fd), "46");
	}
	return (0);
}
