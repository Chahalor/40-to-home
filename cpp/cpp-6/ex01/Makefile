NAME		:= serializer
CXX			:= c++
CXXFLAGS	:= -std=c++98  -Wall -Wextra -Werror -Wno-deprecated -MMD -g3 -Iall -Iheaders

DIR_SRC		:= .
DIR_BUILD	:= .build/
DIR_ALL		:= all/

ALL			:= $(DIR_ALL)/all.a
SRCS		:= Serializer.cpp
_SRC		:= $(addprefix src/, $(SRCS)) main.cpp

OBJS		:= $(_SRC:.cpp=.o)
OBJS		:= $(addprefix $(DIR_BUILD), $(OBJS))

all: $(DIR_BUILD) $(NAME)

$(DIR_BUILD):
	mkdir -p $(DIR_BUILD)

$(NAME): $(OBJS) $(ALL)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(ALL):
	$(MAKE) -C $(DIR_ALL) CXXFLAGS="$(CXXFLAGS)"

$(DIR_BUILD)%.o: $(DIR_SRC)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(DIR_ALL) clean

fclean:
	rm -rf $(DIR_BUILD) $(NAME)
	$(MAKE) -C $(DIR_ALL) fclean

re: fclean all

debug:
	$(eval CXXFLAGS=$(CXXFLAGS) -DDEBUG)

.PHONY: all clean fclean re