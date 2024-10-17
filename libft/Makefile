# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 08:13:34 by nduvoid           #+#    #+#              #
#    Updated: 2024/10/17 14:51:38 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = libft.a

# SRCS = $(wildcard *.c)

# OBJS = $(SRCS:.c=.o)

# AR = ar rcs

# $(TARGET):$(OBJ)
# 	$(AR) $(NAME) $(OBJS)
	
# all: $(TARGET)

# clean:
# 	rm -rf $(OBJ_DIR) $(TARGET)

# fclean:	clean
# 		rm -f $(NAME)

# re:	fclean all

# .PHONY: all clean fclean re

NAME = libft.a

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

AR = ar

FLAGS = rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(FLAGS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
