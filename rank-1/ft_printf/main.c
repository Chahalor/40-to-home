#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
// #include "ft_printf.h"

/**
 * cc main.c libftprintf.a
 */

int	ft_printf(const char *s, ...);

/*
** Helper pour afficher les retours
*/
static void print_ret(const char *label, int ret1, int ret2)
{
	printf("-> %-30s | printf = %3d | ft_printf = %3d", label, ret1, ret2);
	if (ret1 != ret2)
		printf("  ❌");
	else
		printf("  ✅");
	printf("\n\n");
}

/*
** Macro de test standard
*/
#define TEST(fmt, ...) do { \
	int r1; \
	int r2; \
	printf("FORMAT : \"%s\"\n", fmt); \
	printf("printf    : "); \
	r1 = printf(fmt, ##__VA_ARGS__); \
	printf("\nft_printf : "); \
	r2 = ft_printf(fmt, ##__VA_ARGS__); \
	printf("\n"); \
	print_ret(fmt, r1, r2); \
} while (0)

# define YELLOW	"\033[33m"
# define RESET	"\033[0m"



static inline void	test_bonus(void)
{
	printf(YELLOW"========================================\n");
	printf("        BONUS\n");
	printf("========================================\n"RESET);

	printf("========================================\n");
	printf("        WIDTH\n");
	printf("========================================\n");

	TEST("Width 5: '%5d'", 42);
	TEST("Width 5 str: '%5s'", "hi");
	TEST("Width 1: '%1d'", 42);
	TEST("Width 10: '%10u'", 42);

	printf("========================================\n");
	printf("        PRECISION\n");
	printf("========================================\n");

	TEST("Prec .5: '%.5d'", 42);
	TEST("Prec .0 zero: '%.0d'", 0);
	TEST("Prec .3 str: '%.3s'", "abcdef");
	TEST("Prec .0 str: '%.0s'", "hello");

	printf("========================================\n");
	printf("        WIDTH + PRECISION\n");
	printf("========================================\n");

	TEST("'%8.5d'", 42);
	TEST("'%8.3s'", "abcdef");
	TEST("'%5.0d'", 0);
	TEST("'%10.5u'", 42);

	printf("========================================\n");
	printf("        FLAGS\n");
	printf("========================================\n");

	TEST("Plus flag: '%+d'", 42);
	TEST("Plus negative: '%+d'", -42);
	TEST("Space flag: '% d'", 42);
	TEST("Minus flag: '%-5d'", 42);
	TEST("Zero flag: '%05d'", 42);
	TEST("Zero + prec: '%05.3d'", 42);
	TEST("Minus + zero: '%-05d'", 42);

	printf("========================================\n");
	printf("        HEX FLAGS\n");
	printf("========================================\n");

	TEST("Sharp hex: '%#x'", 42);
	TEST("Sharp HEX: '%#X'", 42);
	TEST("Sharp zero: '%#x'", 0);
	TEST("Sharp width: '%#8x'", 42);
	TEST("Sharp zero pad: '%#08x'", 42);
}

int	main(const int argc, const char *argv[])
{
	int	bonus = 0;

	if (argc > 1)
	{
		// printf("argv[%d]='%s'\n", 1, argv[1]);
		if (strcmp(argv[1], "--bonus") || strcmp(argv[1], "-b"))
			bonus = 1;
	}

	printf("========================================\n");
	printf("        BASIC TYPES\n");
	printf("========================================\n");

	TEST("Char: %c", 'A');
	TEST("Char null: %c", 0);
	TEST("String: %s", "Hello");
	TEST("Empty string: %s", "");
	TEST("NULL string: %s", NULL);
	TEST("Decimal: %d", 42);
	TEST("Int: %i", -42);
	TEST("Unsigned: %u", 42);
	TEST("Hex lower: %x", 42);
	TEST("Hex upper: %X", 42);
	TEST("Percent: %%");

	printf("========================================\n");
	printf("        EDGE VALUES\n");
	printf("========================================\n");

	TEST("INT_MAX: %d", INT_MAX);
	TEST("INT_MIN: %d", INT_MIN);
	TEST("UINT_MAX: %u", UINT_MAX);
	TEST("LONG_MAX hex: %x", LONG_MAX);
	TEST("Zero: %d", 0);

	printf("========================================\n");
	printf("        POINTERS\n");
	printf("========================================\n");

	int x = 42;
	TEST("Pointer: %p", &x);
	TEST("NULL pointer: %p", NULL);

	if (bonus)
		test_bonus();

	printf("========================================\n");
	printf("        MIXED\n");
	printf("========================================\n");

	TEST("Mix: %d %s %x %p %%", 42, "hello", 42, &x);
	
	if (bonus)
	{
		TEST("All flags: '%-#08.5x'", 42);
		TEST("Crazy: '%+ -05.3d'", 42);
	}

	printf("========================================\n");
	printf("        INVALID / LIMIT CASES\n");
	printf("========================================\n");

	TEST("Unknown specifier: %q", 42);
	TEST("Only percent: %");
	TEST("Percent then char: %%c");
	TEST("Empty format: ");

	printf("========================================\n");
	printf("        END OF TESTS\n");
	printf("========================================\n");

	return (0);
}
