#!/bin/bash

# Liste des valeurs pour BUFFER_SIZE
BUFFER_SIZES=(0 1 2 4 8 16 32 47 48 64 128 256 10000 1000000)

for size in "${BUFFER_SIZES[@]}"
do
	echo "Testing with BUFFER_SIZE=$size"
	cc -Wall -Wextra -Werror -g3 -D BUFFER_SIZE=$size ./get_next_line.c ./get_next_line_utils.c ./test/main.c -o test_gnl # -fsanitize=address
	# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_gnl
	./test_gnl
	echo "|
------------------------------------"
done

# rm ./test_gnl
