# Big Header #

# ***************************************************** #
# *                 Configuation                      * #
# ***************************************************** #

MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                    Variables                      * #
# ***************************************************** #

NAME		:= push_swap

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
DEBUGFLAGS	:= 
DIR_SRC		:= src
DIR_OBJ		:= .obj
INCLUDE_ALL	:=-Iinclude -Ilibft -I$(DIR_SRC)/algo -I$(DIR_SRC)/args -I$(DIR_SRC)/debug -I$(DIR_SRC)/stack -I$(DIR_SRC)/utils

DIR_LIBFT	:= libft
LIBFT		:= $(DIR_LIBFT)/libft.a

# Here we include all the makefile.supp files
include  src/algo/makefile.supp src/args/makefile.supp src/debug/makefile.supp src/stack/makefile.supp src/utils/makefile.supp

SRC_MAIN	:= push_swap.c

# all object files for the modules
OBJ_MAIN	:= $(addprefix $(DIR_OBJ)/, $(SRC_MAIN:.c=.o))
OBJ_ALL		:= $(OBJ_ALGO) $(OBJ_ARGS) $(OBJ_DEBUG) $(OBJ_STACK) $(OBJ_UTILS) $(OBJ_MAIN)

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header norm $(NAME)

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

$(NAME): $(LIBFT) $(OBJ_ALL)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) $^ $(LIBFT) -o $(NAME)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -c $< -o $@

$(LIBFT):
	@make -C $(DIR_LIBFT) NO_HEADER=true

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ***************************************************** #
# *                    Debug Rules                    * #
# ***************************************************** #

.PHONY: debug debug.fsanitize debug.fs debug.pg

debug:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -g3 -D DEBUG=1)
	@echo "\033[1;33m DEBUG MODE ACTIVATED \033[0m"


debug.fsanitize: debug
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -fsanitize=address)

debug.fs: debug.fsanitize

debug.pg:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -pg)

# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

header:
	@echo "# Big Header #"

norm:
	@errors=$$(norminette | grep "Error"); \
	if [ -n "$$errors" ]; then \
		echo "$$errors"; \
		echo "\033[31m ❌ Norminette errors found \033[0m"; \
	else \
		echo "\033[1;32m ✅ Norminette Ok\033[0m"; \
	fi
