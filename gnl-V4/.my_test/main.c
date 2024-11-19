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
#define RESET "\033[0m"

void	tester(char *s1, char *s2, int line)
{
	if (!s1 && !s2)
		printf(GREEN "OK " RESET);
	else if (!s1 || !s2)
		printf(RED "KO " RESET);
	else if (strcmp(s1, s2))
		printf(RED "KO " RESET);
	else
		printf(GREEN "OK " RESET);
}

#define TEST(s1, s2) {tester(s1, s2, __LINE__); free(s1);}

void	run_test(void)
{
	/* 1char */
	char	*file = ".my_test/1char";
	int		fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" RESET, file);
	else
	{
		TEST(get_next_line(fd), "0");
		TEST(get_next_line(fd), NULL);
	}
	/* one_line */
	file = ".my_test/one_line_no_nl";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" RESET, file);
	else
	{
		printf(RESET "\nTest one_line_no_nl\n\t");
		TEST(get_next_line(fd), "qwertyuiop");
		TEST(get_next_line(fd), NULL);
	}
	/* only nl*/
	file = ".my_test/only_nl";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" RESET, file);
	else
	{
		printf(RESET "\nTest only_nl\n\t");
		TEST(get_next_line(fd), "\n");
		TEST(get_next_line(fd), NULL);
	}
	/* multiple nl */
	file = ".my_test/multiple_nl";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" RESET, file);
	else
	{
		printf(RESET "\nTest multiple_nl\n\t");
		TEST(get_next_line(fd), "\n");
		TEST(get_next_line(fd), "\n");
		printf("%s ", get_next_line(fd));
		// TEST(get_next_line(fd), "\n");
		TEST(get_next_line(fd), NULL);
	}
	/* empty */
	file = ".my_test/empty";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" RESET, file);
	else
	{
		printf(RESET "\nTest empty\n\t");
		TEST(get_next_line(fd), NULL);
		TEST(get_next_line(fd), NULL);
	}
	/* multiple lines */
	file = ".my_test/multiple_lines";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf(RED "Error opening file %s\n" RESET, file);
	else
	{
		printf(RESET "\nTest multiple_lines\n\t");
		TEST(get_next_line(fd), "qwertyuiop\n");
		TEST(get_next_line(fd), "asdfghjkl;\n");
		TEST(get_next_line(fd), "zxcvbnm,./");
		TEST(get_next_line(fd), NULL);
	}
}

/**
 * @brief Test the get_next_line function
 * @author nduvoid
 * @todo Add more tests, especially for BUFFER_SIZE > 1
 * @todo using argc/v pour commencer a un test en particulier
 */
int main(int argc, const char *argv[])
{
	#undef BUFFER_SIZE
	#define BUFFER_SIZE 1
	printf("\n=== BUFFER_SIZE = %d ===\n", BUFFER_SIZE);
	run_test();
	#undef BUFFER_SIZE

	#define BUFFER_SIZE 42
	printf("\n=== BUFFER_SIZE = %d ===\n", BUFFER_SIZE);
	run_test();
	#undef BUFFER_SIZE

	#define BUFFER_SIZE 1000000
	printf("\n=== BUFFER_SIZE = %d ===\n", BUFFER_SIZE);
	run_test();
	return (0);
}
