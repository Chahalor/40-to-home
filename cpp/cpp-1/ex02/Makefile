NAME	:= ref

SRC		:= main.cpp
CFLAGS	:= -Wall -Wextra -Werror -Wno-deprecated -std=c++98

all:
	c++ $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -- $(NAME)

fclean: clean

re: fclean all