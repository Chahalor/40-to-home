#  \
# ╔════════════════════════════════════════════════════════════════════════════════════════════╗
# ║                                                                                            ║
# ║       ________        ___  ___          ___          ___               ________            ║
# ║      |\   __  \      |\  \|\  \        |\  \        |\  \             |\   __  \           ║
# ║      \ \  \|\  \     \ \  \ \  \       \ \  \       \ \  \            \ \  \|\  \          ║
# ║       \ \   ____\     \ \   __  \       \ \  \       \ \  \            \ \  \ \  \         ║
# ║        \ \  \___|      \ \  \ \  \       \ \  \       \ \  \____        \ \  \ \  \        ║
# ║         \ \__\          \ \__\ \__\       \ \__\       \ \_______\       \ \_______\       ║
# ║          \|__|           \|__|\|__|        \|__|        \|_______|        \|_______|       ║
# ║                                                                                            ║
# ║    By: nduvoid <nduvoid@student.42mulhouse.fr>                                             ║
# ║    A 42 cursus Project                                                                     ║
# ╚════════════════════════════════════════════════════════════════════════════════════════════╝\n

# ***************************************************** #
# *                 Configuation                      * #
# ***************************************************** #

MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                    Variables                      * #
# ***************************************************** #

NAME		:= philo_bonus
BONUS		:=

CC			:= cc
CFLAGS		+= -Wall -Wextra -Werror -MMD
DEBUGFLAGS	:= 
DIR_SRC		:= src
DIR_OBJ		:= .build
DIR_BONUS	:= 
INCLUDE_ALL	:=-Iglobal -I$(DIR_SRC)/debug -I$(DIR_SRC)/interface -I$(DIR_SRC)/parsing -I$(DIR_SRC)/philosophers -I$(DIR_SRC)/process -I$(DIR_SRC)/semaphore -I$(DIR_SRC)/utils

DIR_LIBFT	:= #
LIBFT		:= #$(DIR_LIBFT)/libft.a

# Here we include all the makefile.mk files
include  src/debug/makefile.mk src/interface/makefile.mk src/parsing/makefile.mk src/philosophers/makefile.mk src/process/makefile.mk src/semaphore/makefile.mk src/utils/makefile.mk

SRC_MAIN	:= main.c
SRC_BONUS	:=

# all object files for the modules
OBJ_MAIN	:= $(addprefix $(DIR_OBJ)/, $(SRC_MAIN:.c=.o))
OBJ_BONUS	:= $(addprefix $(DIR_OBJ)/, $(SRC_BONUS:.c=.o))
OBJ_ALL		:= $(OBJ_DEBUG) $(OBJ_INTERFACE) $(OBJ_PARSING) $(OBJ_PHILOSOPHERS) $(OBJ_PROCESS) $(OBJ_SEMAPHORE) $(OBJ_UTILS)

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header norm $(NAME) install

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

$(NAME):  $(LIBFT) $(OBJ_ALL) $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) $^ $(LIBFT) -o $(NAME) 

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -c $< -o $@

# $(LIBFT):
# 	@make -C $(DIR_LIBFT) NO_HEADER=true

bonus: $(LIBFT) $(OBJ_ALL) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) $^ $(LIBFT)  -o $(BONUS)

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	rm -f $(OBJ_ALL) $(OBJ_MAIN) $(OBJ_BONUS)
#@make clean -C $(DIR_LIBFT)

fclean:
	rm -rf $(DIR_OBJ)
	rm -f $(NAME) $(BONUS)
#@make fclean -C $(DIR_LIBFT)

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

debug.fthread: debug
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -fsanitize=thread)

debug.fs: debug.fsanitize

debug.pg:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -pg)

# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

.PHONY: header norm crazy test install uninstall update hellgrind

header:
ifeq ($(MAKELEVEL),0)
	@echo " \
╔════════════════════════════════════════════════════════════════════════════════════════════╗\n \
║                                                                                            ║\n \
║       ________        ___  ___          ___          ___               ________            ║\n \
║      |\   __  \      |\  \|\  \        |\  \        |\  \             |\   __  \           ║\n \
║      \ \  \|\  \     \ \  \ \  \       \ \  \       \ \  \            \ \  \|\  \          ║\n \
║       \ \   ____\     \ \   __  \       \ \  \       \ \  \            \ \  \ \  \         ║\n \
║        \ \  \___|      \ \  \ \  \       \ \  \       \ \  \____        \ \  \ \  \        ║\n \
║         \ \__\          \ \__\ \__\       \ \__\       \ \_______\       \ \_______\       ║\n \
║          \|__|           \|__|\|__|        \|__|        \|_______|        \|_______|       ║\n \
║                                                                                            ║\n \
║    By: nduvoid <nduvoid@student.42mulhouse.fr>                                             ║\n \
║    A 42 cursus Project                                                                     ║\n \
╚════════════════════════════════════════════════════════════════════════════════════════════╝\n"
endif


norm:
	@errors=$$(norminette --use-gitignore | grep --color=always "Error"); \
	if [ -n "$$errors" ]; then \
		echo "$$errors"; \
		echo "\033[31m ❌ Norminette errors found \033[0m"; \
	else \
		echo "\033[1;32m ✅ Norminette Ok\033[0m"; \
	fi

INSTALL_DIR = $(HOME)/.local/bin

install:
	mkdir -p $(INSTALL_DIR)
	cp $(NAME) $(INSTALL_DIR)/
	chmod +x $(INSTALL_DIR)/$(NAME)
	$(call _completion)
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

hellgrind: debug all
	@echo "\033[1;33m Running hellgrind... \033[0m"
	valgrind --tool=helgrind ./$(NAME) $(ARGS)
	echo "\033[1;32m ✅ Hellgrind finished \033[0m"

.SILENT:
	@echo "\033[1;33m SILENT MODE ACTIVATED \033[0m

