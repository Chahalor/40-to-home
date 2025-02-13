
# ╔═══════════════════════════════════════════════════════════════════════════════╗
# ║                                                                               ║
# ║   ________        ___          ________        _______           ___    ___   ║
# ║  |\   __  \      |\  \        |\   __  \      |\  ___ \         |\  \  /  /|  ║
# ║  \ \  \|\  \     \ \  \       \ \  \|\  \     \ \   __/|        \ \  \/  / /  ║
# ║   \ \   ____\     \ \  \       \ \   ____\     \ \  \_|/__       \ \    / /   ║
# ║    \ \  \___|      \ \  \       \ \  \___|      \ \  \_|\ \       /     \/    ║
# ║     \ \__\          \ \__\       \ \__\          \ \_______\     /  /\   \    ║
# ║      \|__|           \|__|        \|__|           \|_______|    /__/ /\ __\   ║
# ║                                                                 |__|/ \|__|   ║
# ║                                                                               ║
# ║  by nduvoid                                                                   ║
# ║                                                                               ║
# ╚═══════════════════════════════════════════════════════════════════════════════╝

# MAKEFLAGS += --no-print-directory	# no Entering / Leaving messages

# ***************************************************** #
# *                VARIABLES                          * #
# ***************************************************** #

# Name of the executable
NAME :=			pipex

CC :=			cc
CFLAGS =		-Wall -Wextra -Werror
DEBUGFLAGS =
ARGS =

# Directories
DIR_SRC :=			src
DIR_OBJ :=			.obj
DIR_LIBFT :=		libft
DIR_INTERFACE :=	interface
DIR_INTERNE :=		interne

# Libraries
LIBFT :=		$(DIR_LIBFT)/libft.a

# modules
MOD_FORK :=		fork
MOD_INIT :=		init
MOD_PARS :=		parsing
MOD_PROC :=		process
MOD_PIPE :=		pipe
MOD_UTILS :=	utils
MOD_DEBUG :=	debug

MOD_ALL :=		$(MOD_FORK) $(MOD_INIT) $(MOD_PARS) $(MOD_PROC) $(MOD_PIPE) $(MOD_UTILS) $(MOD_DEBUG)

# Includes
INC_GLOBAL :=	Global
INCLUDES :=		-I$(DIR_LIBFT) -I$(INC_GLOBAL) $(foreach dir, $(MOD_ALL) ,-I$(DIR_SRC)/$(dir)/$(DIR_INTERFACE))

# SRC

SRC_FORK :=		$(MOD_FORK)/

SRC_INIT :=		$(MOD_INIT)/init.c

SRC_PARS :=		$(MOD_PARS)/parsing_args.c

SRC_PROC :=		$(MOD_PROC)/

SRC_PIPE :=		$(MOD_PIPE)/

SRC_UTILS :=	$(MOD_UTILS)/utils.c

SRC_DEBUG :=	$(MOD_DEBUG)/print_struct.c

SRC_MAIN :=		pipex.c


SRC := $(SRC_MAIN) $(SRC_INIT) $(SRC_PARS) $(SRC_UTILS) $(SRC_DEBUG)

# All object files
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

# ***************************************************** #
# *                      Main Rules                   * #
# ***************************************************** #

all: write_header norm $(NAME)

$(NAME): $(LIBFT) compile

# ***************************************************** #
# *                 Compile Rule                      * #
# ***************************************************** #

.PHONY: compile

compile: libft $(DIR_OBJ) $(OBJ)
	@printf "\n"
	@echo "\033[32m ✅ Compilation done\033[0m"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[32m ✅ $(NAME) created\033[0m"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@mkdir -p $(dir $@)
	@$(call compile_object, $(INCLUDES), $(SRC), $(COLOR_YELLOW))

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(LIBFT):
	make -s -C $(DIR_LIBFT)
	@echo "\033[32m ✅ Libft created\033[0m"

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	@rm -rf $(DIR_OBJ)
	-@make -C $(DIR_LIBFT) clean

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

.PHONY: run write_header norm reset_count make_norm compile_object write_goals

run:
	./$(NAME) $(ARGS)

echo:
	@echo "OBJ: $(OBJ)"
	@echo "SRC: $(SRC)"

write_header:
	@clear
	@printf "\n/* Big Header */\n"

norm:
	@$(call make_norm)

define make_norm
	@norminette $(DIR_SRC)/ $(DIR_LIBFT)/ $(INC_GLOBAL)/ > /tmp/norm_output.txt; \
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
	@printf "$(CC) $(CFLAGS) $(DEBUGFLAGS) $(1) -c $< -o $@\n"
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
