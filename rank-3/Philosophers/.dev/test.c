/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:03:31 by nduvoid           #+#    #+#             */
/*   Updated: 2025/05/06 09:23:58 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <string.h>


typedef struct s_philo {
	long	last_meal;
	int		time_to_die;
	sem_t	*sem_stdout;
}	t_philo;

long	current_time_ms(void) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	*monitor(void *arg) {
	t_philo *philo = (t_philo *)arg;

	while (1) {
		usleep(1000); // 1ms
		if (current_time_ms() - philo->last_meal > philo->time_to_die) {
			sem_wait(philo->sem_stdout);
			printf("Philo %d est mort de faim\n", getpid());
			sem_post(philo->sem_stdout);
			exit(1);
		}
	}
	return (NULL);
}

void	philo_process(int time_to_die, sem_t *sem_stdout) {
	t_philo	philo;
	pthread_t	thread;

	philo.last_meal = current_time_ms();
	philo.time_to_die = time_to_die;
	philo.sem_stdout = sem_stdout;

	pthread_create(&thread, NULL, monitor, &philo);
	pthread_detach(thread);

	// Boucle de vie du philosophe
	while (1) {
		// Manger : met à jour le timestamp
		philo.last_meal = current_time_ms();
		sem_wait(sem_stdout);
		printf("Philo %d mange\n", getpid());
		sem_post(sem_stdout);
		usleep(2000 * 1000); // 2 sec
	}
}

int main(void) {
	sem_t *sem_stdout = sem_open("/sem_stdout", O_CREAT, 0644, 1);
	const int philo_count = 10; // Nombre de philosophes
	register int i = -1;

	while (++i < philo_count)
	{
		int pid = fork();
	
		if (pid == 0)
			philo_process(3000, sem_stdout); // enfant = philosophe
	}
	

	// Parent attend la mort
	int	status;
	waitpid(-1, &status, 0);
	if (WIFEXITED(status)) {
		printf("a Philosopher a terminé avec code %d\n", WEXITSTATUS(status));
	}
	sem_close(sem_stdout);
	sem_unlink("/sem_stdout");
}
