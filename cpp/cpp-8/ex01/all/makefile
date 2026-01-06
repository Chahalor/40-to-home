NAME		= all.a

CXX			?= c++
CXXFLAGS	?= -Wall -Wextra -Werror -Wno-deprecated -std=c++98 -MMD -I.
AR			?= ar rcs

DIR_BUILD	:= .build/
DIR_SRC		:= .
DIR_INC		:= .

SRCS		:= string.cpp atoi.cpp itoa.cpp random.cpp

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
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(DIR_BUILD) $(NAME)

re: fclean all