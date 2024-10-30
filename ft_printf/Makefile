# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 09:06:20 by nduvoid           #+#    #+#              #
#    Updated: 2024/10/30 14:29:39 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = srcs
INCDIR = libft
OBJDIR = ./.obj

SRCS =		ft_printf.c \
			put_func.c \
			put_func2.c \
			put_func3.c \
			utils.c
SRC = 		$(addprefix $(SRCDIR)/, $(SRCS))
SRCOBJ = 	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

AR = ar
FLAGS = rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJDIR) $(SRCOBJ)
	$(AR) $(FLAGS) $(NAME) $(SRCOBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
