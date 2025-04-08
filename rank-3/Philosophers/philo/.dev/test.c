#include <stdio.h>

static const char *colors[] = {
    "\033[38;2;255;125;0m",    // Rouge
    "\033[38;2;0;255;0m",    // Vert
    "\033[38;2;0;0;255m",    // Bleu
    "\033[38;2;255;255;0m",  // Jaune
    "\033[38;2;255;0;255m",  // Magenta
    "\033[38;2;0;255;255m",  // Cyan
    "\033[38;2;255;255;255m" // Blanc
};

int main(void)
{
	int i;

	for (i = 0; i < 7; i++)
	{
		printf("%sHello, World!%s\n", colors[i], "\033[0m");
	}

	return 0;
}