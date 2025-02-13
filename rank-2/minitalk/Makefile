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
# ╚═══════════════════════════════════════════════════════════════════════════════╝

AKEFLAGS += --no-print-directory	# no Entering / Leaving messages

# ***************************************************** #
# *                VARIABLES                          * #
# ***************************************************** #

# Name of the executable
NAME_CLIENT :=	client
NAME_SERVER :=	server

CC :=			cc
CFLAGS =		-Wall -Wextra -Werror
DEBUGFLAGS =
ARGS =

# Directories
DIR_SRC :=			.
DIR_OBJ :=			.obj
DIR_LIBFT :=		libft
DIR_CLIENT :=		client
DIR_SERVER :=		server
DIR_INTERFACE :=	interface
DIR_INTERNE :=		interne

# Libraries
LIBFT :=		$(DIR_LIBFT)/libft.a

# -----| Modules |----- #
 # Client
C_MOD_HEAR :=		Hear
C_MOD_TALK :=		Talker
C_MOD_TRAN :=		Translator
C_MOD_UTILS :=		Utils
C_MOD_ALL :=		$(C_MOD_HEART) $(C_MOD_TALK) $(C_MOD_TRAN) $(C_MOD_UTILS)

 # Server
S_MOD_HEAR :=		Listener
S_MOD_TALK :=		Talker
S_MOD_TRAN :=		Translator
S_MOD_UTILS :=		Utils
S_MOD_ALL :=		$(S_MOD_HEART) $(S_MOD_TALK) $(S_MOD_TRAN) $(S_MOD_UTILS)

ALL_MOD :=		$(C_MOD_ALL) $(S_MOD_ALL)

# Includes
INC_GLOBAL :=	Global
INC_CLIENT :=	$(foreach dir, $(C_MOD_ALL) ,-I$(DIR_SRC)/$(dir)/$(DIR_INTERFACE))
INC_SERVER :=	$(foreach dir, $(S_MOD_ALL) ,-I$(DIR_SRC)/$(dir)/$(DIR_INTERFACE))
INCLUDES :=		-I$(INC_GLOBAL) -I$(DIR_LIBFT) $(INC_CLIENT) $(INC_SERVER)

# -----| Sources |----- #
 # Client
C_SRC_HEAR :=		$(DIR_SRC)/$(DIR_CLIENT)/$(C_MOD_HEAR)/hear.c
C_SRC_TALK :=		$(DIR_SRC)/$(DIR_CLIENT)/$(C_MOD_TALK)/talker.c
C_SRC_TRAN :=		$(DIR_SRC)/$(DIR_CLIENT)/$(C_MOD_TRAN)/translator.c
C_SRC_UTILS :=		$(DIR_SRC)/$(DIR_CLIENT)/$(C_MOD_UTILS)/utils.c
C_SRC_ALL :=		$(C_SRC_HEAR) $(C_SRC_TALK) $(C_SRC_TRAN) $(C_SRC_UTILS) $(DIR_SRC)/$(DIR_CLIENT)client.c

OBJ_CLIENT :=	$(addprefix $(DIR_OBJ)/, $(C_SRC_ALL:.c=.o))

 # Server
S_SRC_HEAR :=		$(DIR_SRC)/$(DIR_SERVER)/$(S_MOD_HEAR)/signal.c
S_SRC_TALK :=		$(DIR_SRC)/$(DIR_SERVER)/$(S_MOD_TALK)/talker.c
S_SRC_TRAN :=		$(DIR_SRC)/$(DIR_SERVER)/$(S_MOD_TRAN)/translator.c
# S_SRC_UTILS :=		$(DIR_SRC)/$(DIR_SERVER)/$(S_MOD_UTILS)/utils.c
S_SRC_ALL :=		$(S_SRC_HEAR) $(S_SRC_TALK) $(S_SRC_TRAN) $(DIR_SRC)/$(DIR_SERVER)server.c

OBJ_SERVER :=	$(addprefix $(DIR_OBJ)/, $(S_SRC_ALL:.c=.o))

ALL_OBJ :=			$(OBJ_CLIENT) $(OBJ_SERVER)

# ***************************************************** #
# *                      Main Rules                   * #
# ***************************************************** #

.PHONY: all name

all: write_header norm name $(NAME)

name: $(LIBFT) compile
	@echo "NAME slag"

$(NAME): $(LIBFT) compile
	@echo "NAME"

# ***************************************************** #
# *                 Compile Rule                      * #
# ***************************************************** #

.PHONY: compile client server

compile: client server
	@echo "\033[32m ✅ Compilation done\033[0m"

client: $(LIBFT) $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $() $(OBJ_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "\033[32m ✅ Client created\033[0m"

server: $(LIBFT) $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) $(OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "\033[32m ✅ Server created\033[0m"

$(DIR_OBJ)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(call compile_object, $(INCLUDES), $(ALL_OBJ), $(NAME))

$(LIBFT):
	@make -C -s $(DIR_LIBFT)

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	@rm -rf $(DIR_OBJ)
	-@make -C $(DIR_LIBFT) clean

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
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
	@echo "Client: $(OBJ_CLIENT)\n $(C_SRC_ALL)"
	@echo "Server: $(OBJ_SERVER)\n $(S_SRC_ALL)"

write_header:
	@clear
	@printf "\n/* Big Header */\n"

norm:
	@$(call make_norm)

define make_norm
	@norminette > /tmp/norm_output.txt; \
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
