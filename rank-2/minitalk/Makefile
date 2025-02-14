# ╔════════════════════════════════════════════════════════════════════════════════════╗
# ║                                                                                    ║
# ║                                                                                    ║
# ║  _____ ______   ___  ________   ___  _________  ________  ___       ___  __        ║
# ║ |\   _ \  _   \|\  \|\   ___  \|\  \|\___   ___\\   __  \|\  \     |\  \|\  \      ║
# ║ \ \  \\\__\ \  \ \  \ \  \\ \  \ \  \|___ \  \_\ \  \|\  \ \  \    \ \  \/  /|_    ║
# ║  \ \  \\|__| \  \ \  \ \  \\ \  \ \  \   \ \  \ \ \   __  \ \  \    \ \   ___  \   ║
# ║   \ \  \    \ \  \ \  \ \  \\ \  \ \  \   \ \  \ \ \  \ \  \ \  \____\ \  \\ \  \  ║
# ║    \ \__\    \ \__\ \__\ \__\\ \__\ \__\   \ \__\ \ \__\ \__\ \_______\ \__\\ \__\ ║
# ║     \|__|     \|__|\|__|\|__| \|__|\|__|    \|__|  \|__|\|__|\|_______|\|__| \|__| ║
# ║                                                                                    ║
# ║  by nduvoid                                                                        ║
# ║                                                                                    ║
# ╚════════════════════════════════════════════════════════════════════════════════════╝

MAKEFLAGS += --no-print-directory	# no Entering / Leaving messages

# ***************************************************** #
# *                VARIABLES                          * #
# ***************************************************** #

# Name of the executable
NAME :=			minitalk
NAME_CLIENT :=	client.out
NAME_SERVER :=	server.out

CC :=			cc
CFLAGS =		-Wall -Wextra -Werror
DEBUGFLAGS =
ARGS =

# Directories
DIR_SRC :=
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
C_MOD_ALL :=		$(C_MOD_HEAR) $(C_MOD_TALK) $(C_MOD_TRAN) $(C_MOD_UTILS)

 # Server
S_MOD_HEAR :=		Listener
S_MOD_TALK :=		Talker
S_MOD_TRAN :=		Translator
S_MOD_UTILS :=		Utils
S_MOD_ALL :=		$(S_MOD_HEAR) $(S_MOD_TALK) $(S_MOD_TRAN) $(S_MOD_UTILS)

ALL_MOD :=		$(C_MOD_ALL) $(S_MOD_ALL)

# Includes
INC_GLOBAL :=	Global
INC_CLIENT :=	$(foreach dir, $(C_MOD_ALL) ,-I$(DIR_CLIENT)/$(dir)/$(DIR_INTERFACE))
INC_SERVER :=	$(foreach dir, $(S_MOD_ALL) ,-I$(DIR_SERVER)/$(dir)/$(DIR_INTERFACE))
INCLUDES :=		-I$(INC_GLOBAL) -I$(DIR_LIBFT) #$(INC_CLIENT) $(INC_SERVER)

# -----| Sources |----- #
 # Client
C_SRC_HEAR :=		#$(DIR_CLIENT)/$(C_MOD_HEAR)/hear.c
C_SRC_TALK :=		$(DIR_CLIENT)/$(C_MOD_TALK)/talker.c
C_SRC_TRAN :=		$(DIR_CLIENT)/$(C_MOD_TRAN)/translator.c
C_SRC_UTILS :=		$(DIR_CLIENT)/$(C_MOD_UTILS)/utils.c
CLIENT_SRC_ALL :=		$(C_SRC_HEAR) $(C_SRC_TALK) $(C_SRC_TRAN) $(C_SRC_UTILS) $(DIR_CLIENT)/client.c


 # Server
S_SRC_HEAR :=		$(DIR_SERVER)/$(S_MOD_HEAR)/signal.c
S_SRC_TALK :=		$(DIR_SERVER)/$(S_MOD_TALK)/talker.c
S_SRC_TRAN :=		$(DIR_SERVER)/$(S_MOD_TRAN)/translator.c
S_SRC_UTILS :=		$(DIR_SERVER)/$(S_MOD_UTILS)/utils.c
SERVER_SRC_ALL :=		$(S_SRC_HEAR) $(S_SRC_TALK) $(S_SRC_TRAN) $(DIR_SERVER)/server.c

OBJ_CLIENT :=	$(addprefix $(DIR_OBJ)/, $(CLIENT_SRC_ALL:.c=.o))
OBJ_SERVER :=	$(addprefix $(DIR_OBJ)/, $(SERVER_SRC_ALL:.c=.o))
ALL_OBJ :=		$(OBJ_CLIENT) $(OBJ_SERVER)

# ***************************************************** #
# *                      Main Rules                   * #
# ***************************************************** #

.PHONY: all name

all: write_header norm $(NAME)

$(NAME): $(LIBFT) compile

# ***************************************************** #
# *                 Compile Rule                      * #
# ***************************************************** #

.PHONY: compile client server

compile: client reset_count server

client: reset_count $(LIBFT) $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $() $(OBJ_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "\n\033[32m ✅ Client created\033[0m"

server: reset_count $(LIBFT) $(OBJ_SERVER)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) $(OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "\033[32m ✅ Server created\033[0m"

COMPILE_FLAG =	$(if $(filter client/%,$<),$(INC_CLIENT),$(INC_SERVER))
COMPILE_SRC =	$(if $(filter client/%,$<),$(CLIENT_SRC_ALL),$(SERVER_SRC_ALL))
$(DIR_OBJ)/%.o: %.c
	@mkdir -p $(dir $@)
	$(call compile_object, $(INCLUDES) $(COMPILE_FLAG), $(COMPILE_SRC), $(COLOR_YELLOW))

# $(DIR_OBJ)/%.o: %.c
# 	@mkdir -p $(dir $@)
# 	$(call compile_object, $(INCLUDES), $(ALL_OBJ), $(COLOR_GREEN))

$(LIBFT):
	-@make -C $(DIR_LIBFT)

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

.PHONY: write_header echo norm reset_count make_norm compile_object write_goals

echo:
	@echo "Client: $(OBJ_CLIENT)\n $(CLIENT_SRC_ALL)"
	@echo "Server: $(OBJ_SERVER)\n $(SERVER_SRC_ALL)"
	@echo "flag: $(COMPILE_FLAG)"
	@echo "src: $(COMPILE_SRC)"

write_header:
	@clear
	@printf "\n/* Big Header */\n"

norm:
	@if norminette | grep "Error" > /dev/null; then \
		norminette | grep "Error" > /dev/null; \
		echo "\033[31m ❌ Norminette errors found \033[0m"; \
	else \
		echo "\033[1;32m ✅ Norminette Ok\033[0m"; \
	fi

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
		@printf " "
	@true
endef

# 	@printf "$(CC) $(CFLAGS) $(DEBUGFLAGS) $(1) -c $< -o $@\n"
