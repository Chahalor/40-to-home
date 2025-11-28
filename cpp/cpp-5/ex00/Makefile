NAME		:= bureaucrat
CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -Wno-deprecated -std=c++98 -MMD -g3 -Iall -Iheaders

DIR_SRC		:= .
DIR_BUILD	:= .build/
DIR_ALL		:= all/

ALL			:= $(DIR_ALL)/all.a
SRCS		:= Bureaucrat.cpp
_SRC		:= $(addprefix src/, $(SRCS)) main.cpp

OBJS		:= $(_SRC:.cpp=.o)
OBJS		:= $(addprefix $(DIR_BUILD), $(OBJS))

all: $(DIR_BUILD) $(NAME)

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(NAME): $(OBJS) $(ALL)
	$(CC) $(CFLAGS) -o $@ $^

$(ALL):
	$(MAKE) -C $(DIR_ALL) CFLAGS="$(CFLAGS)"

$(DIR_BUILD)%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(DIR_ALL) clean

fclean:
	rm -rf $(DIR_BUILD) $(NAME)
	$(MAKE) -C $(DIR_ALL) fclean

re: fclean all

debug:
	$(eval CFLAGS=$(CFLAGS) -DDEBUG)

.PHONY: all clean fclean re