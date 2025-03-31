/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:09:41 by nduvoid           #+#    #+#             */
/*   Updated: 2025/03/31 12:26:31 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#define TEST_SIZE 100000000 // 100 Mo pour test extrême

void test_memchr(const char *desc, unsigned char *buffer, size_t size, int value) {
	printf("Test: %s ... ", desc);
	fflush(stdout);

	void *res_std = ft_memchr(buffer, value, size);
	void *res_fast = ft_memchr(buffer, value, size);

	if (res_std == res_fast) {
		printf("✅ OK\n");
	} else {
		printf("❌ FAIL (std: %p, fast: %p)\n", res_std, res_fast);
	}
}

int main() {
	srand((unsigned int)time(NULL));

	// 1. Test avec la valeur au début
	unsigned char *buf1 = malloc(TEST_SIZE);
	memset(buf1, 'A', TEST_SIZE);
	buf1[0] = 'X'; // Valeur cible au début
	test_memchr("Valeur au début", buf1, TEST_SIZE, 'X');

	// 2. Test avec la valeur au milieu
	unsigned char *buf2 = malloc(TEST_SIZE);
	memset(buf2, 'A', TEST_SIZE);
	buf2[TEST_SIZE / 2] = 'Y'; // Valeur cible au milieu
	test_memchr("Valeur au milieu", buf2, TEST_SIZE, 'Y');

	// 3. Test avec la valeur à la fin
	unsigned char *buf3 = malloc(TEST_SIZE);
	memset(buf3, 'A', TEST_SIZE);
	buf3[TEST_SIZE - 1] = 'Z'; // Valeur cible à la fin
	test_memchr("Valeur à la fin", buf3, TEST_SIZE, 'Z');

	// 4. Test sans la valeur (NULL attendu)
	unsigned char *buf4 = malloc(TEST_SIZE);
	memset(buf4, 'A', TEST_SIZE);
	test_memchr("Valeur absente", buf4, TEST_SIZE, 'B');

	// 5. Test avec des accès mémoire non alignés
	unsigned char *buf5 = malloc(TEST_SIZE + 1);
	unsigned char *unaligned = buf5 + 1; // Décalage d'un octet pour casser l'alignement
	memset(unaligned, 'A', TEST_SIZE);
	unaligned[TEST_SIZE / 2] = 'W'; // Valeur cible au milieu
	test_memchr("Accès mémoire non aligné", unaligned, TEST_SIZE, 'W');

	// Nettoyage
	free(buf1);
	free(buf2);
	free(buf3);
	free(buf4);
	free(buf5);

	return 0;
}
