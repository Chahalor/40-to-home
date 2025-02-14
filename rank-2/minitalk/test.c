#include <signal.h>
// #include <asm-generic/signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "0", 1);
	else if (sig == SIGUSR2)
		write(1, "1", 1);
}

int	main(void)
{
	printf("PID: %d\n", getpid());
	struct sigaction	act;
	act.sa_handler = handler;
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
}

