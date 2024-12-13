# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 11:58:41 by nduvoid           #+#    #+#              #
#    Updated: 2024/12/13 15:44:20 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	FDF

DIRSRC	  =	src/
DIRMLIBX  =	minilibx-linux/
DIRLIBFT  =	libft/
HEADERDIR =	includes/
DIROBJ	  =	.obj/

SRC =	fdf.c		\
		parsing.c	\
SRCDEBUG =	debug.c

OBJ =		$(addprefix $(DIROBJ), $(SRC:.c=.o))
OBJDEBUG =	$(addprefix $(DIROBJ), $(SRCDEBUG:.c=.o))

CC = 			cc
CFLAGS =		-Wall -Wextra -Werror
CFLAGS +=		-I $(HEADERDIR)
CFLAGS +=		-I $(DIRLIBFT)$(HEADERDIR)
CFLAGS +=		-I $(DIRMLIBX)
DEBUGFLAGS =	-g3 -D DEBUG=1
FSFLAGS =		-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(DIRLIBFT)
	@make -C $(DIRMLIBX)
	@$(CC) $(OBJ) $(DIRMLIBX)/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)

$(DIROBJ)%.o: $(DIRSRC)%.c
	@mkdir -p $(DIROBJ)
	@$(CC) $(CFLAGS) -I$(DIRMLIBX) -I$(HEADERDIR) -O3 -c $< -o $@

debug: $(OBJ)
	@make -C $(DIRLIBFT)
	@make -C $(DIRMLIBX)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) -I$(DIRMLIBX) -I$(HEADERDIR) -o $(NAME) $(OBJ) -L $(DIRLIBFT) -lft -L $(DIRMLIBX)

debug.fs: 
	$(DEBUGFLAGS) := $(DEBUGFLAGS) $(FSFLAGS)
	debug

clean:
	@rm -rf $(DIROBJ)
	@make -C $(DIRLIBFT) clean
	@make -C $(DIRMLIBX) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(DIRLIBFT) fclean

re: fclean all

.PHONY: all clean fclean re