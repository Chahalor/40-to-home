NAME		= all.a

CC			?= c++
CFLAGS		?= -Wall -Wextra -Werror -Wno-deprecated -std=c++98 -MMD -I.
AR			?= ar rcs

DIR_BUILD	:= .build/
DIR_SRC		:= .
DIR_INC		:= .

SRCS		:= string.cpp atoi.cpp

_OBJS		:= $(SRCS:.cpp=.o)
OBJS		:= $(addprefix $(DIR_BUILD), $(_OBJS))
DEPS		:= $(OBJS:.o=.d)

-include $(DEPS)

all: $(DIR_BUILD) $(NAME)

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(NAME): $(OBJS)
	$(AR) rcs $@ $^

$(DIR_BUILD)%.o: $(DIR_SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(DIR_BUILD) $(NAME)

re: fclean all