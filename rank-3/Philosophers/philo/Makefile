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

NAME		:= philo
BONUS		:=

CC			:= cc
CFLAGS		+= -Wall -Wextra -Werror -Werror=implicit-function-declaration -MMD
DEBUGFLAGS	:= 
DIR_SRC		:= src
DIR_OBJ		:= .build
DIR_BONUS	:= 
INCLUDE_ALL	:=-Iglobal -I$(DIR_SRC)/debug -I$(DIR_SRC)/interface -I$(DIR_SRC)/parsing -I$(DIR_SRC)/philosophers -I$(DIR_SRC)/states -I$(DIR_SRC)/threads -I$(DIR_SRC)/utils

_DEPS		:= $(_OBJ_ALL:.o=.d)

# Here we include all the makefile.mk files
include  src/debug/makefile.mk src/interface/makefile.mk src/parsing/makefile.mk src/philosophers/makefile.mk src/states/makefile.mk src/threads/makefile.mk src/utils/makefile.mk
-include $(_DEPS)

SRC_MAIN	:= main.c
SRC_BONUS	:=

# all object files for the modules
_OBJ_MAIN	:= $(addprefix $(DIR_OBJ)/, $(SRC_MAIN:.c=.o))
_OBJ_BONUS	:= $(addprefix $(DIR_OBJ)/, $(SRC_BONUS:.c=.o))
_OBJ_ALL		:= $(OBJ_DEBUG) $(OBJ_INTERFACE) $(OBJ_PARSING) $(OBJ_PHILOSOPHERS) $(OBJ_STATES) $(OBJ_THREADS) $(OBJ_UTILS)

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header norm $(NAME) install

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

$(NAME): $(_OBJ_ALL) $(_OBJ_MAIN)
	@echo "\n ⚙️ $(_YELLOW) Compiling$(_RESET) $(NAME)..."
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) $^ -o $(NAME) 

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) -c $< -o $@

bonus: $(_OBJ_ALL) $(_OBJ_BONUS)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDE_ALL) $^ -o $(BONUS)

fast: $(NAME)

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	rm -f $(_OBJ_ALL) $(_OBJ_MAIN) $(_OBJ_BONUS)

fclean:
	rm -rf $(DIR_OBJ)
	rm -f $(NAME) $(BONUS)

re: fclean all

# ***************************************************** #
# *                    Debug Rules                    * #
# ***************************************************** #

.PHONY: debug debug.fsanitize debug.fs debug.pg hellgrind

debug:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -g3 -D DEBUG=1)
	@echo "\033[1;33m DEBUG MODE ACTIVATED $(_RESET)"

debug.fsanitize: debug
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -fsanitize=address)

debug.fs: debug.fsanitize

debug.fthread: debug
	@echo "$(_YELLOW) use: $(_RESET)'setarch $$(uname -m) -R $$SHELL' before running philo\n"
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -fsanitize=thread)

debug.pg:
	$(eval DEBUGFLAGS=$(DEBUGFLAGS) -pg)

hellgrind: debug all
	@echo "\033[1;33m Running hellgrind... \033[0m"
	valgrind --tool=helgrind ./$(NAME) $(ARGS)
	echo "\033[1;32m ✅ Hellgrind finished \033[0m"

# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

.PHONY: header norm install uninstall update symbols

_YELLOW	:= \033[1;33m
_GREEN	:= \033[1;32m
_RED	:= \033[1;31m
_RESET	:= \033[0m

header:
ifeq ($(MAKELEVEL), 0)
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

help:
	@echo "\033[1;33mUsage: make [target]$(_RESET)\n" 	"$(_YELLOW)├──$(_GREEN)all$(_RESET)			- Build the project\n" 	"$(_YELLOW)├──$(_GREEN)bonus$(_RESET)		- Build the bonus part of the project\n" 	"$(_YELLOW)├──$(_GREEN)fast$(_RESET)			- Build the project quickly\n" 	"$(_YELLOW)├──$(_GREEN)clean$(_RESET)		- Remove object files\n" 	"$(_YELLOW)├──$(_GREEN)fclean$(_RESET)		- Remove object files and executable\n" 	"$(_YELLOW)├──$(_GREEN)re$(_RESET)			- Clean and rebuild the project\n" 	"$(_YELLOW)├──$(_GREEN)debug$(_RESET)		- Enable debug mode\n" 	"$(_YELLOW)├──$(_GREEN)debug.fsanitize$(_RESET)	- Enable debug mode with address sanitizer\n" 	"$(_YELLOW)├──$(_GREEN)debug.fs$(_RESET)		- Enable debug mode with full sanitizer\n" 	"$(_YELLOW)├──$(_GREEN)debug.pg$(_RESET)		- Enable debug mode with profiling\n" 	"$(_YELLOW)├──$(_GREEN)norm$(_RESET)			- Check code style with Norminette\n" 	"$(_YELLOW)├──$(_GREEN)install$(_RESET)		- Install the executable to ~/.local/bin\n" 	"$(_YELLOW)├──$(_GREEN)uninstall$(_RESET)		- Uninstall the executable from ~/.local/bin\n" 	"$(_YELLOW)├──$(_GREEN)update$(_RESET)		- Update the Makefile using auto.sh script\n" 	"$(_YELLOW)└──$(_GREEN)symbols$(_RESET)		- Check for forbidden symbols in the binary\n"

# -----| Norminette check  |----- #

NORM_FILES := global/ src/
norm:
	@printf "$(_YELLOW) 🔎 Checking norminette...$(_RESET)"
	@NORM_OUTPUT="$$(norminette $(NORM_FILES) | grep 'Error')" ; \
	if [ -z "$$NORM_OUTPUT" ]; then \
		printf "$(_GREEN) ✅ Norminette passed with no errors.$(_RESET)\n"; \
	else \
		printf "\r" ; 		printf "$$NORM_OUTPUT" | awk '\
		/\.c: Error!/ || /\.h: Error!/ { file=$$0; next } \
		/Error:/ { \
			l=match($$0, /line: *[0-9]+/); \
			c=match($$0, /col: *[0-9]+/); \
			line=substr($$0, l+6, 10); \
			col=substr($$0, c+5, 10); \
			gsub(/\(line: *[0-9]+, *col: *[0-9]+\): */, "", $$0); \
			sub(/Error: /, "", $$0); \
			split(file, parts, ":"); \
			printf "$(_RED)Error$(_RESET): %s:%-2s:%-2s: %s\n", parts[1], line+0, col+0, $$0; \
		}' ; \
		echo "$(_RED) ❌ Norminette errors found$(_RESET)" ; \
	fi

# -----| Install / Uninstall |----- #

INSTALL_DIR = $(HOME)/.local/bin
install:
	mkdir -p $(INSTALL_DIR)
	cp $(NAME) $(INSTALL_DIR)/
	chmod +x $(INSTALL_DIR)/$(NAME)
	$(call _completion)
	echo "$(_GREEN) ✅ $(NAME) installed to $(INSTALL_DIR) $(_RESET)"; \

uninstall:
	rm -rf $(INSTALL_DIR)/$(NAME)
	echo "$(_GREEN) ✅ $(NAME) uninstalled from $(INSTALL_DIR) $(_RESET)";

update:
	if [ -f ./auto.sh ]; then \
		echo "\033[1;33m Updating Makefile... $(_RESET)"; \
	else \
		echo "$(_RED) auto.sh not found, please add the script to automate the update $(_RESET)"; \
		exit 1; \
	fi
	./auto.sh
	echo "$(_GREEN) ✅ Makefile updated $(_RESET)";


# -----| Symbols check |----- #
SUPPRESED_SYMBOLS	:=	memset
ALLOWED_SYMBOLS		:=	memset, printf, malloc, free, write, \
						usleep, gettimeofday, pthread_create, \
						pthread_detach, pthread_join, pthread_mutex_init, \
						pthread_mutex_destroy, pthread_mutex_lock, \
						pthread_mutex_unlock 
symbols:
	@nm -uj $(NAME) | sort -u | sed 's/@.*//' | grep -v '^__' | \
	awk ' \
	BEGIN { \
		split("$(ALLOWED_SYMBOLS)", allowed); \
		split("$(SUPPRESSED_SYMBOLS)", suppressed); \
		for (i in allowed) allow[allowed[i]] = 1; \
		for (i in suppressed) supp[suppressed[i]] = 1; \
		suppressed_count = 0; \
		forbidden_count = 0; \
		output = ""; \
	} \
	{ \
		sym = $$0; \
		if (sym in allow) \
			output = output sprintf("$(_YELLOW)│   $(_GREEN)%s (allowed)$(_RESET)\n", sym); \
		else if (sym in supp) \
			suppressed_count++; \
		else \
		{ \
			output = output sprintf("$(_YELLOW)├$(_RED)── %s (forbidden)$(_RESET)\n", sym); \
			forbidden_count++; \
		} \
	} \
	END { \
		if (suppressed_count > 0 || forbidden_count > 0) \
		{ \
			printf "$(_YELLOW)SYMBOLS:$(_RESET)\n"; \
			printf "%s", output; \
		} \
		else \
			printf "$(_YELLOW)├──$(_GREEN)✅ Only allowed symbols found!$(_RESET)\n"; \
		printf "$(_YELLOW)├── functions suppressed (%d)\n",  suppressed_count; \
		printf "$(_YELLOW)└── functions forbidden (%d)\n", forbidden_count; \
	}'

# Variables de suivi
COMPILED := 0
TOTAL := 100
BAR_WIDTH := 50

define compile
	COMPILED=$$((COMPILED + 1)); \
	TOTAL=$(TOTAL); \
	RATIO=$$(echo "$$COMPILED * $(BAR_WIDTH) / $$TOTAL" | bc); \
	printf "\rCompiling %-40s \n[" "$1"; \
	for i in $$(seq 1 $$RATIO); do printf "="; done; \
	for i in $$(seq $$((BAR_WIDTH))); do printf " "; done; \
	printf "]\n"
endef

.SILENT:
	@echo "\033[1;33m SILENT MODE ACTIVATED $(_RESET)"
