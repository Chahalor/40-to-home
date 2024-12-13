# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 09:08:21 by nduvoid           #+#    #+#              #
#    Updated: 2024/12/13 11:28:38 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directories
SRCDIR =	src
LIBFTDIR =	libft
OBJDIR =	.obj
DBGDIR =	debug # not exiting yet
INCDIR =	include

# All source files
SRC =		main.c 		\
			push_swap.c	\
			instruct.c	\
			instruct2.c	\
			instruct3.c	\
			stack.c		\
			radix.c		\
			utils.c
DEBUGSRC =	debuger.c

# All archive files
LIBFT =	$(LIBFTDIR)/libft.a

# All object files
OBJ =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEBUGOBJ =	$(addprefix $(OBJDIR)/, $(DEBUGSRC:.c=.o))

# Compilation Flags
CC =				cc
CFLAGS =			-Wall -Wextra -Werror -I./$(INCDIR) -I./libft/include

# Debug Flags
DEBUGFLAGS =		-g3 -D DEBUG=1
FSANITIZEFLAGS =	-fsanitize=address


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(LIBFT) $(OBJ) $(DEBUGOBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(DEBUGOBJ) -o $(NAME) $(LIBFT)

debug.fsanitize: CFLAGS += $(FSANITIZEFLAGS)
debug.fsanitize: debug

debug.fs: debug.fsanitize

norm:
	@$(call make_norm)
# @make -C $(LIBFTDIR) norm TODO

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re debug debug.fsanitize

# All functions
define make_norm
	@norminette $(SRCDIR)/*.c $(INCDIR)/*.h > /tmp/norm_output.txt; \
	if grep -q "Error!" /tmp/norm_output.txt; then \
		echo "\e[31mNorminette failed\e[0m"; \
		cat /tmp/norm_output.txt; \
	else \
		echo "\e[32mNorminette passed\e[0m"; \
	fi; \
	rm -f /tmp/norm_output.txt
endef
