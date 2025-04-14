#include <stdio.h>
#include <string.h>
#include <unistd.h>
// #include "test.h"

int main(void)
{
	int sleep_time = 1000;
	printf("should Usleep %d milliseconde\n", sleep_time);
	ft_usleep(sleep_time * 1000);
}