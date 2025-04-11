#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"

int main(void)
{
	t_str	str = {"hello world\n", 12, 0};
	write(1, str.str, str.len);

}