#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void free_auto(void *ptr)
{
	void **p = (void **)ptr;
	if (*p)
		free(*p);
}

void f()
{
	__attribute__((cleanup(free_auto))) char *str = malloc(100);
	memcpy(str, "Hello, world!", 13);
	printf("%s\n", str);
}


int main() {

	f();

	return 0;
}
