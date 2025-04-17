#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	printf("Ceci est une ligne fixe\n");
	printf("\033[999B"); // essaie d'aller très bas
	printf("Tu es (peut-être) loin en bas 🫣\n");

	sleep(3); // attend 3 secondes

	printf("\033[999A"); // remonte au max (haut de l'écran)
	printf("Et maintenant tout en haut 👆\n");
	return (0);
}
