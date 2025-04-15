#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define CMD_Y 30 // ligne du terminal où commence la zone "commande"

void	move_cursor(int row, int col)
{
	printf("\033[%d;%dH", row, col); // positionner le curseur à (row, col)
	fflush(stdout);
}

void	clear_cmd_zone(void)
{
	move_cursor(CMD_Y, 1);
	printf("\033[0J"); // clear from cursor to bottom
	fflush(stdout);
}

void	*command_thread(void *arg)
{
	char	buff[64];

	while (1)
	{
		clear_cmd_zone();
		move_cursor(CMD_Y, 1);
		printf("\033[7m[CMD] >> \033[0m"); // style inversé
		fflush(stdout);
		if (!fgets(buff, sizeof(buff), stdin))
			continue;

		// traitement basique
		if (buff[0] == 'q')
			break;
		else if (buff[0] == 's')
		{
			move_cursor(CMD_Y + 1, 1);
			printf("Status: OK\n");
		}
		usleep(100000); // évite le spam
	}
	return NULL;
}

int	main(void)
{
	pthread_t	cmd_thread;

	// Créer le thread de commande
	if (pthread_create(&cmd_thread, NULL, command_thread, NULL) != 0)
	{
		perror("Failed to create command thread");
		return 1;
	}

	// Boucle principale
	while (1)
	{
		move_cursor(300, 400);
		printf("Main loop running...\n");
		fflush(stdout);
		usleep(500000); // Simuler du travail
	}

	pthread_join(cmd_thread, NULL);
	return 0;
}
