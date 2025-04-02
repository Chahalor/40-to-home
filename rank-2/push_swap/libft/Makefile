# Big Header #

# ***************************************************** #
# *                 Configuation                      * #
# ***************************************************** #

MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                    Variables                      * #
# ***************************************************** #

NAME		:= libft.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -MMD
DEBUGFLAGS	:= 
DIR_SRC		:= src
DIR_OBJ		:= .obj
DIR_BONUS	:= 
INCLUDE_ALL	:=-I./ -I -I$(DIR_SRC)/char-change -I$(DIR_SRC)/ft_printf -I$(DIR_SRC)/get_next_line -I$(DIR_SRC)/is -I$(DIR_SRC)/linked-list -I$(DIR_SRC)/memory -I$(DIR_SRC)/put -I$(DIR_SRC)/str -I$(DIR_SRC)/str-change

# Here we include all the makefile.mk files
include  src/char-change/makefile.mk src/ft_printf/makefile.mk src/get_next_line/makefile.mk src/is/makefile.mk src/linked-list/makefile.mk src/memory/makefile.mk src/put/makefile.mk src/str/makefile.mk src/str-change/makefile.mk

SRC_MAIN	:=

# all object files for the modules
OBJ_MAIN	:= $(addprefix $(DIR_OBJ)/, $(SRC_MAIN:.c=.o))
OBJ_ALL		:= $(OBJ_CHAR-CHANGE) $(OBJ_FT_PRINTF) $(OBJ_GET_NEXT_LINE) $(OBJ_IS) $(OBJ_LINKED-LIST) $(OBJ_MEMORY) $(OBJ_PUT) $(OBJ_STR) $(OBJ_STR-CHANGE) $(OBJ_MAIN)

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header norm $(NAME)

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

$(NAME): $(OBJ_ALL)
	@ar rcs $(NAME) $(OBJ_ALL)
	@ranlib $(NAME)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -c $< -o $@

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	rm -rf $(DIR_OBJ)
# @make clean -C $(DIR_LIBFT)
# @make clean -C $(DIR_BONUS)

fclean: clean
	rm -f $(NAME)
# @make fclean -C $(DIR_LIBFT)
# @make fclean -C $(DIR_BONUS)

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

.PHONY: header norm crazy test update # install uninstall

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

# INSTALL_DIR = $(HOME)/.local/bin

# install:
# 	mkdir -p $(INSTALL_DIR)
# 	cp $(NAME) $(INSTALL_DIR)/
# 	chmod +x $(INSTALL_DIR)/$(NAME)
# 	echo "\033[1;32m ✅ $(NAME) installed to $(INSTALL_DIR) \033[0m"; \

# uninstall:
# 	rm -rf $(INSTALL_DIR)/$(NAME)
# 	echo "\033[1;32m ✅ $(NAME) uninstalled from $(INSTALL_DIR) \033[0m";

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

