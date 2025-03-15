# ╔═══════════════════════════════════════════════════════════════════════════════════════════════════╗
# ║                                                                                                   ║
# ║   ________  ___  ___  ________  ___  ___          ________  ___       __   ________  ________     ║
# ║  |\   __  \|\  \|\  \|\   ____\|\  \|\  \        |\   ____\|\  \     |\  \|\   __  \|\   __  \    ║
# ║  \ \  \|\  \ \  \\\  \ \  \___|\ \  \\\  \       \ \  \___|\ \  \    \ \  \ \  \|\  \ \  \|\  \   ║
# ║   \ \   ____\ \  \\\  \ \_____  \ \   __  \       \ \_____  \ \  \  __\ \  \ \   __  \ \   ____\  ║
# ║    \ \  \___|\ \  \\\  \|____|\  \ \  \ \  \       \|____|\  \ \  \|\__\_\  \ \  \ \  \ \  \___|  ║
# ║     \ \__\    \ \_______\____\_\  \ \__\ \__\        ____\_\  \ \____________\ \__\ \__\ \__\     ║
# ║      \|__|     \|_______|\_________\|__|\|__|       |\_________\|____________|\|__|\|__|\|__|     ║
# ║                         \|_________|                \|_________|                                  ║
# ║                                                                                                   ║
# ║   by <nduvoid@student.42mulhouse.fr>                                                              ║
# ║                                                                                                   ║
# ╚═══════════════════════════════════════════════════════════════════════════════════════════════════╝



# ***************************************************** #
# *                 Configuation                      * #
# ***************************************************** #

MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                    Variables                      * #
# ***************************************************** #

NAME = push_swap

DIR_LIBFT = libft
DIR_INC = include
DIR_SRC = src/
DIR_OBJ = .obj
DIR_BONUS = bonus

DIR_ARGS = args
DIR_ALGO = algo
DIR_DEBUG = debug
DIR_STACK = stack
DIR_UTILS = utils
DIR_INSTRUCT = instruct

SRC_ARGS = args.c 
SRC_ALGO = #algo.c
SRC_DEBUG = #debug.c
SRC_STACK = #stack.c
SRC_UTILS = #utils.c
SRC_INSTRUCT = #instruct.c
SRC_MAIN = #push_swap.c

LIBFT = $(DIR_LIBFT)/libft.a

FILES_ARGS =		$(addprefix $(DIR_SRC/)$(DIR_ARGS)/, $(SRC_ARGS))
FILES_ALGO =		$(addprefix $(DIR_SRC/)$(DIR_ALGO)/, $(SRC_ALGO))
FILES_DEBUG =		$(addprefix $(DIR_SRC/)$(DIR_DEBUG)/, $(SRC_DEBUG))
FILES_STACK =		$(addprefix $(DIR_SRC/)$(DIR_STACK)/, $(SRC_STACK))
FILES_UTILS =		$(addprefix $(DIR_SRC/)$(DIR_UTILS)/, $(SRC_UTILS))
FILES_INSTRUCT =	$(addprefix $(DIR_SRC/)$(DIR_INSTRUCT)/, $(SRC_INSTRUCT))
FILES_MAIN =		$(addprefix $(DIR_SRC), $(SRC_MAIN))


OBJ_ARGS =		$(patsubst $(DIR_SRC)$(DIR_ARGS)/%.c, $(DIR_OBJ)/%.o, $(FILES_ARGS))
OBJ_ALGO =		$(patsubst $(DIR_SRC)$(DIR_ALGO)/%.c, $(DIR_OBJ)/%.o, $(FILES_ALGO))
OBJ_DEBUG =		$(patsubst $(DIR_SRC)$(DIR_DEBUG)/%.c, $(DIR_OBJ)/%.o, $(FILES_DEBUG))
OBJ_STACK =		$(patsubst $(DIR_SRC)$(DIR_STACK)/%.c, $(DIR_OBJ)/%.o, $(FILES_STACK))
OBJ_UTILS =		$(patsubst $(DIR_SRC)$(DIR_UTILS)/%.c, $(DIR_OBJ)/%.o, $(FILES_UTILS))
OBJ_INSTRUCT =	$(patsubst $(DIR_SRC)$(DIR_INSTRUCT)/%.c, $(DIR_OBJ)/%.o, $(FILES_INSTRUCT))
OBJ_MAIN =		$(patsubst $(DIR_SRC)%.c, $(DIR_OBJ)/%.o, $(FILES_MAIN))

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
IFLAGS =	-I$(DIR_INC) -I$(DIR_LIBFT)
DEBUGFLAGS =

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all compile bonus

all: header norm compile

compile: $(LIBFT) $(NAME)

bonus:
	-@$(MAKE) -C $(DIR_BONUS) $(MAKEFLAGS)

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

$(NAME): $(OBJ_SRC)
	@$(CC) $(CFLAGS) $(IFLAGS) $(IFLAGS) $(DEBUGFLAGS) -o $@ $^ $(LIBFT)

$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_ARGS)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) $(DEBUGFLAGS), $(DIR_OBJ)/$(notdir $@), $(COLOR_YELLOW))

$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_ALGO)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) $(DEBUGFLAGS), $(DIR_OBJ)/$(notdir $@), $(COLOR_YELLOW))
	
$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_DEBUG)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) $(DEBUGFLAGS), $(DIR_OBJ)/$(notdir $@), $(COLOR_YELLOW))

$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_STACK)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) $(DEBUGFLAGS), $(DIR_OBJ)/$(notdir $@), $(COLOR_YELLOW))

$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_UTILS)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) $(DEBUGFLAGS), $(DIR_OBJ)/$(notdir $@), $(COLOR_YELLOW))

$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_INSTRUCT)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) $(DEBUGFLAGS), $(DIR_OBJ)/$(notdir $@), $(COLOR_YELLOW))

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) $(DEBUGFLAGS), $(DIR_OBJ)/$(notdir $@), $(COLOR_YELLOW))

$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_MAIN)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) $(DEBUGFLAGS), $(DIR_OBJ)/$(notdir $@), $(COLOR_YELLOW))

$(LIBFT):
	-@make -C $(DIR_LIBFT) NO_HEADER=true

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	@rm -rf $(DIR_OBJ)
	-@make -C $(DIR_LIBFT) clean
	-@make -C $(DIR_BONUS) clean

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	-@make -C $(DIR_LIBFT) fclean
	-@make -C $(DIR_BONUS) fclean

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

.PHONY: header info norm reset_count compile_object write_goals

info:
	$(info $(NAME))
	$(info $(SRC))
	$(info $(OBJ_SRC))

header:
	@clear
	@printf "\n \
	 ╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗ \n \
	 ║                                                                                                                       ║ \n \
	 ║   _____ ______       ___        ________       ___      _________      ________        ___           ___  __          ║ \n \
	 ║  |\   _ \  _   \    |\  \      |\   ___ \     |\  \    |\___   ___\   |\   __  \      |\  \         |\  \|\  \        ║ \n \
	 ║  \ \  \\\__\  \   \   \ \  \     \ \  \\ \  \    \ \  \   \|___ \  \_|   \ \  \|\  \     \ \  \        \ \  \/  /|_      ║ \n \
	 ║   \ \  \\|__| \   \   \ \  \     \ \  \\ \  \    \ \  \       \ \  \     \ \   __  \     \ \  \        \ \   ___  \     ║ \n \
	 ║    \ \  \    \ \  \   \ \  \     \ \  \\ \  \    \ \  \       \ \  \     \ \  \ \  \     \ \  \____    \ \  \\  \  \    ║ \n \
	 ║     \ \__\    \ \__\   \ \__\     \ \__\\ \__\    \ \__\       \ \__\     \ \__\ \__\     \ \_______\   \ \__\\  \__\   ║ \n \
	 ║      \|__|     \|__|    \|__|      \|__| \|__|    \|__|        \|__|      \|__|\|__|      \|_______|    \|__|   \__|  ║ \n \
	 ║                                                                                                                       ║ \n \
	 ║    by <nduvoid@student.42mulhouse.fr>                                                                                 ║ \n"
	@$(call write_goals)
	@printf " \
	 ║                                                                                                                       ║ \n \
	 ╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n"

norm:
	@errors=$$(norminette | grep "Error"); \
	if [ -n "$$errors" ]; then \
		echo "$$errors"; \
		echo "\033[31m ❌ Norminette errors found \033[0m"; \
	else \
		echo "\033[1;32m ✅ Norminette Ok\033[0m"; \
	fi

define write_goals
	line_size=106; \
	line="$(if $(MAKECMDGOALS), $(MAKECMDGOALS), all)"; \
	line_size=$$(( $$line_size - $${#line} )); \
	printf "  ║    \e[4mRule(s):\e[0m %s%*s\e[0m║\n" "$$line" $$line_size " "
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
		@printf " "
	@true
endef

# 	@printf "$(CC) $(CFLAGS) $(DEBUGFLAGS) $(1) -c $< -o $@\n"