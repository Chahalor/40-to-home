# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 09:08:21 by nduvoid           #+#    #+#              #
#    Updated: 2024/12/02 14:16:10 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCDIR =	src
LIBFTDIR =	libft
OBJDIR =	.obj

SRC =	push_swap.c \
		command.c \
		command2.c \
		command3.c \
		stack.c \
		debuger.c #rm

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
DEBUGFLAGS = -g3 -fsanitize=address

LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re debug
