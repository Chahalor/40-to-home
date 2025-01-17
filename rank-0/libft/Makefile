# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 08:13:34 by nduvoid           #+#    #+#              #
#    Updated: 2025/01/16 14:38:09 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***************************************************** #
# *                 Variable                          * #
# ***************************************************** #

NAME = libft.a

DIR_SRC =		src
DIR_PRINTF =	ft_printf
DIR_GNL =		get_next_line
DIR_OBJ =		.obj

SRC_LIBFT =	char-change/ft_toupper.c \
			char-change/ft_tolower.c \
			is/ft_isalnum.c \
			is/ft_isalpha.c \
			is/ft_isascii.c \
			is/ft_isdigit.c \
			is/ft_isprint.c \
			linked-list/ft_lstadd_back.c \
			linked-list/ft_lstadd_front.c \
			linked-list/ft_lstclear.c \
			linked-list/ft_lstdelone.c \
			linked-list/ft_lstiter.c \
			linked-list/ft_lstlast.c \
			linked-list/ft_lstmap.c \
			linked-list/ft_lstnew.c \
			linked-list/ft_lstsize.c \
			memory/ft_calloc.c \
			memory/ft_bzero.c \
			memory/ft_memchr.c \
			memory/ft_memcmp.c \
			memory/ft_memcpy.c \
			memory/ft_memmove.c \
			memory/ft_memset.c \
			put/ft_putchar_fd.c \
			put/ft_putendl_fd.c \
			put/ft_putstr_fd.c \
			put/ft_putnbr_fd.c \
			str/ft_strchr.c \
			str/ft_strdup.c \
			str/ft_striteri.c \
			str/ft_strjoin.c \
			str/ft_strlcat.c \
			str/ft_strlcpy.c \
			str/ft_strlen.c \
			str/ft_strmapi.c \
			str/ft_strncmp.c \
			str/ft_strnstr.c \
			str/ft_strrchr.c \
			str/ft_strtrim.c \
			str/ft_substr.c \
			str-change/ft_atoi.c \
			str-change/ft_itoa.c \
			str-change/ft_split.c

SRC_PRINTF =	ft_printf.c \
				put_func.c \
				put_func2.c \
				put_func3.c

SRC_GNL =	get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OBJ_LIBFT =			$(addprefix $(DIR_OBJ)/, $(notdir $(SRC_LIBFT:.c=.o)))
OBJ_PRINTF =		$(addprefix $(DIR_OBJ)/, $(SRC_PRINTF:.c=.o))
OBJ_GNL =			$(addprefix $(DIR_OBJ)/, $(SRC_GNL:.c=.o))

AR =		ar
FLAGS =		rcs
RM =		rm -f
CC =		cc
CFLAGS =	-Wall -Wextra -Werror
DEBUGFLAGS =

# ***************************************************** #
# *                      Main Rules                   * #
# ***************************************************** #

all: header norm $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) compile

# ***************************************************** #
# *                 Compile Rule                      * #
# ***************************************************** #

.PHONY: compile

compile: $(DIR_OBJ) $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL)
	@printf "\n"
	@echo "\033[32m ✅ Compilation done\033[0m"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(MLXFLAGS) -lm $(OBJ) $(LIBFT) $(MLX_LIB) -o $(NAME)
	@echo "\033[32m ✅ $(NAME) created\033[0m"

$(DIR_OBJ)/%.o: $(DIR_LIBFT)/%.c | $(DIR_OBJ)
	@$(call compile_object, $(INCFLAGS), "", $(SRC_LIBFT), $(COLOR_YELLOW))

$(DIR_OBJ)/%.o: $(DIR_PRINTF)/%.c | $(DIR_OBJ)
	@$(call compile_object, $(INCFLAGS), "", $(SRC_PRINTF), $(COLOR_YELLOW))

$(DIR_OBJ)/%.o: $(DIR_GNL)/%.c | $(DIR_OBJ)
	@$(call compile_object, $(INCFLAGS), "", $(SRC_GNL), $(COLOR_YELLOW))

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(LIBFT):
	@make -C $(DIR_LIBFT)

$(MLX_LIB):
	@make -s -C $(DIR_MLX)

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	@rm -rf $(DIR_OBJ)
	-@make -C $(DIR_LIBFT) clean
	-@make -C $(DIR_MLX) clean

fclean: clean
	@rm -f $(NAME)
	-@make -C $(DIR_LIBFT) fclean

re: fclean all

# ***************************************************** #
# *                    Debug Rules                    * #
# ***************************************************** #

.PHONY: debug debug.fsanitize debug.fs

debug:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -g3 -D DEBUG=1)


debug.fsanitize: debug
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -fsanitize=address)

debug.fs: debug.fsanitize

# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

.PHONY: header norm reset_count make_norm compile_object write_goals

header:
	@clear
	@printf "Header Libft\n"

norm:
	@if [ command -v norminette &> /dev/null ]; then \
		$(call make_norm); \
	else \
		echo "Norminette not found\n"; \
	fi

define make_norm
	@norminette $(DIR_SRC)/ $(DIR_LIBFT)/ > /tmp/norm_output.txt; \
	if grep -q " Error!" /tmp/norm_output.txt; then \
		cat /tmp/norm_output.txt | grep "Error"; \
		echo " ❌ \e[31mNorminette failed\e[0m"; \
	else \
		echo " ✅ \e[32mNorminette passed\e[0m"; \
	fi; \
	rm -- /tmp/norm_output.txt
endef

define write_goals
	line_size=97; \
	line="$(if $(MAKECMDGOALS), $(MAKECMDGOALS), all)"; \
	line_size=$$(( $$line_size - $${#line} )); \
	printf "║    \e[4mRule(s):\e[0m %s%*s\e[0m║\n" "$$line" $$line_size " "
endef

# Helper function to print a progress bar
# Credits: ugwentzi@student.42mulhouse.fr
#=- Progress Bar -=#
BAR_LENGTH =	42
PADDING =		10
COLOR_YELLOW =	\033[1;33m
COLOR_GREEN =	\033[1;32m
COLOR_CYAN =	\033[1;36m
COLOR_RED =		\033[31m
COLOR_RESET =	\033[0m

reset_count:
	$(eval COUNT := 0)

define compile_object
	$(eval COUNT := $(shell echo $$(( $(COUNT) + 1 ))))
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(1) -c $< -o $@
	@printf "\r$(3)\bCompiling %s%*s[%-$(BAR_LENGTH)s] %d/%d$(COLOR_RESET)" \
		"$<" \
		$$(($(PADDING) - $$(echo -n "$(NAME)" | wc -c))) "" \
		$(shell printf '=%.0s' $$(seq 1 $$(echo "$$(( $(BAR_LENGTH) * $(COUNT) / $(words $(2)) ))"))) \
		$(COUNT) \
		$(words $(2))
		printf " "
	@true
endef

