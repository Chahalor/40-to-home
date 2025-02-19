#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	signal_handle(int sig, siginfo_t *info, void *context)
{
	printf("signal_handle\n");
	if (sig == SIGUSR1)
		printf("0");
	else if (sig == SIGUSR2)
		printf("1");
}

int main(void)
{
	struct sigaction	handler;

	handler.sa_sigaction = signal_handle;
	sigemptyset(&handler.sa_mask);
	if (sigaction(SIGUSR1, &handler, NULL) == -1)
		return (0);
	if (sigaction(SIGUSR2, &handler, NULL) == -1)
		return (0);
	printf("PID: %d \n", getpid());
	while (1)
		pause();
}
