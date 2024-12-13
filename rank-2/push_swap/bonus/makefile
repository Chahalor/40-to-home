# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 12:14:54 by nduvoid           #+#    #+#              #
#    Updated: 2024/12/10 13:12:27 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester

SRCDIR =	src
OBJDIR =	.obj
HEADIR =	header

SRC =	get_next_line_utils.c \
		get_next_line.c \
		instruct.c \
		instruct2.c \
		instruct3.c \
		stack.c \
		tester.c \
		utils.c \
		utils2.c

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CC =			cc
CFLAGS =		-Wall -Wextra -Werror
DEBUGFLAGS =	-g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

debug: $(OBJ)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

norm:
	@$(call make_norm)

re: fclean all

.PHONY: all clean fclean re debug norm

define make_norm
	@norminette $(SRCDIR)/*.c $(HEADIR)/*.h > /tmp/norm_output.txt; \
	if grep -q "Error!" /tmp/norm_output.txt; then \
		cat /tmp/norm_output.txt; \
	else \
		echo "Norminette passed"; \
	fi; \
	rm -f /tmp/norm_output.txt
endef
