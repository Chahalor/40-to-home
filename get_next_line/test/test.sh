#!/bin/bash

# Liste des valeurs pour BUFFER_SIZE
BUFFER_SIZES=(0 1 4 8 16 32 46 47 64 128 256 10000 1000000)

for size in "${BUFFER_SIZES[@]}"
do
	echo "Testing with BUFFER_SIZE=$size"
	cc -Wall -Wextra -Werror -D BUFFER_SIZE=$size ./get_next_line.c ./get_next_line_utils.c ./test/main.c -o test_gnl
	# valgrind ./test_gnl | cat -e
	./test_gnl | cat -e
	echo "|
------------------------------------"
done

rm ./test_gnl
