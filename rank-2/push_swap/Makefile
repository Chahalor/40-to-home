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

# Here we include all the makefile.mk files
include  src/algo/makefile.mk src/args/makefile.mk src/debug/makefile.mk src/stack/makefile.mk src/utils/makefile.mk

SRC_MAIN	:= push_swap.c

# all object files for the modules
OBJ_MAIN	:= $(addprefix $(DIR_OBJ)/, $(SRC_MAIN:.c=.o))
OBJ_ALL		:= $(OBJ_ALGO) $(OBJ_ARGS) $(OBJ_DEBUG) $(OBJ_STACK) $(OBJ_UTILS) $(OBJ_MAIN)

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header norm $(NAME) install

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

.PHONY: header norm install uninstall update

header:
	@echo "# Big Header #"

norm:
	@errors=$$(norminette --use-gitignore | grep "Error"); \
	if [ -n "$$errors" ]; then \
		echo "$$errors"; \
		echo "\033[31m ❌ Norminette errors found \033[0m"; \
	else \
		echo "\033[1;32m ✅ Norminette Ok\033[0m"; \
	fi

test: all
	bash ./benchmark.sh 10
	bash ./benchmark.sh 100
	bash ./benchmark.sh 500
	@echo "\033[1;32m ✅ Test completed \033[0m"

INSTALL_DIR = $(HOME)/.local/bin

install:
	mkdir -p $(INSTALL_DIR)
	cp $(NAME) $(INSTALL_DIR)/
	chmod +x $(INSTALL_DIR)/$(NAME)
	echo "\033[1;32m ✅ $(NAME) installed to $(INSTALL_DIR) \033[0m"; \

uninstall:
	rm -rf $(INSTALL_DIR)/$(NAME)
	echo "\033[1;32m ✅ $(NAME) uninstalled from $(INSTALL_DIR) \033[0m";

update:
	if [ -f ./auto.sh ]; then \
		echo "\033[1;33m Updating Makefile... \033[0m"; \
	else \
		echo "\033[1;31m auto.sh not found, please add the script to automate the update \033[0m"; \
		exit 1; \
	fi
	./auto.sh
	echo "\033[1;32m ✅ Makefile updated \033[0m";

.SILENT:
	@echo "\033[1;33m SILENT MODE ACTIVATED \033[0m

