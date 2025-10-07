NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

DIR_SRC		:= .
DIR_BUILD	:= .build/

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(DIR_BUILD), $(OBJS))

all: $(DIR_BUILD) $(NAME)

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(DIR_BUILD)%.o: $(DIR_SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(DIR_BUILD) $(NAME)

re: fclean all