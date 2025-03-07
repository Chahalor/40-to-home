# ╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗
# ║                                                                                                                       ║
# ║   _____ ______       ___        ________       ___      _________      ________        ___             ___  __        ║
# ║  |\   _ \  _   \    |\  \      |\   ___  \    |\  \    |\___   ___\   |\   __  \      |\  \          |\  \|\  \       ║
# ║  \ \  \\\__\ \  \   \ \  \     \ \  \\ \  \   \ \  \   \|___ \  \_|   \ \  \|\  \     \ \  \         \ \  \/  /|_     ║
# ║   \ \  \\|__| \  \   \ \  \     \ \  \\ \  \   \ \  \       \ \  \     \ \   __  \     \ \  \         \ \   ___  \    ║
# ║    \ \  \    \ \  \   \ \  \     \ \  \\ \  \   \ \  \       \ \  \     \ \  \ \  \     \ \  \____     \ \  \\ \  \   ║
# ║     \ \__\    \ \__\   \ \__\     \ \__\\ \__\   \ \__\       \ \__\     \ \__\ \__\     \ \_______\    \ \__\\ \__\  ║
# ║      \|__|     \|__|    \|__|      \|__| \|__|    \|__|        \|__|      \|__|\|__|      \|_______|     \|__| \|__|  ║
# ║                                                                                                                       ║
# ║   by nduvoid@student.42mulhouse.fr                                                                                    ║
# ║                                                                                                                       ║
# ║                                                                                                                       ║
# ╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝

# ***************************************************** #
# *                 Configuation                      * #
# ***************************************************** #

MAKEFLAGS += --no-print-directory

# ***************************************************** #
# *                    Variables                      * #
# ***************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

DIR_LIBFT = libft
DIR_INC = includes
DIR_SRC = src
DIR_OBJ = .obj

DIR_SERVER = server
DIR_CLIENT = client
DIR_CRYPTO = cryptography

SRC_SERVER = server.c args.c server_handler.c 
SRC_CLIENT = client.c client_handler.c client_args.c
SRC_CRYPTO = rc4.c

INC_SERVER = $(DIR_INC)/$(DIR_SERVER)
INC_CLIENT = $(DIR_INC)/$(DIR_CLIENT)
INC_CRYPTO = $(DIR_INC)/$(DIR_CRYPTO)

LIBFT = $(DIR_LIBFT)/libft.a

SERV_FILES = $(addprefix $(DIR_SRC)/$(DIR_SERVER)/, $(SRC_SERVER))
CLIE_FILES = $(addprefix $(DIR_SRC)/$(DIR_CLIENT)/, $(SRC_CLIENT))
CRYP_FILES = $(addprefix $(DIR_SRC)/$(DIR_CRYPTO)/, $(SRC_CRYPTO))

OBJ_SERVER = $(patsubst $(DIR_SRC)/$(DIR_SERVER)/%.c, $(DIR_OBJ)/%.o, $(SERV_FILES))
OBJ_CLIENT = $(patsubst $(DIR_SRC)/$(DIR_CLIENT)/%.c, $(DIR_OBJ)/%.o, $(CLIE_FILES))
OBJ_CRYPTO = $(patsubst $(DIR_SRC)/$(DIR_CRYPTO)/%.c, $(DIR_OBJ)/%.o, $(CRYP_FILES))

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
IFLAGS =	-I$(DIR_INC) -I$(DIR_LIBFT) -I$(INC_CRYPTO)
DEBUGFLAGS =

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all compile

all: header norm compile

compile: _server _client

_client: $(LIBFT) $(NAME_CLIENT)

_server: $(LIBFT) $(NAME_SERVER)

bonus:
	$(MAKE) all CFLAGS="$(CFLAGS) -D BONUS=1"

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

$(NAME_SERVER): $(OBJ_SERVER) $(OBJ_CRYPTO)
	@$(CC) $(CFLAGS) $(IFLAGS) -I$(DIR_INC)/$(DIR_SERVER) $(DEBUGFLAGS) -o $@ $^ $(LIBFT)

$(NAME_CLIENT): $(OBJ_CLIENT) $(OBJ_CRYPTO)
	@$(CC) $(CFLAGS) $(IFLAGS) -I$(DIR_INC)/$(DIR_CLIENT) $(DEBUGFLAGS) -o $@ $^ $(LIBFT)

# $(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
# 	@mkdir -p $(DIR_OBJ)
# 	@mkdir -p $(DIR_OBJ)/$(DIR_SERVER)
# 	@mkdir -p $(DIR_OBJ)/$(DIR_CLIENT)
# 	$(call compile_object, $(IFLAGS) $(DEBUGFLAGS), $(OBJ_SERVER) $(OBJ_CLIENT), $(COLOR_YELLOW))

$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_SERVER)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) -I$(INC_SERVER) $(DEBUGFLAGS) -D SERVER, $(DIR_OBJ)/$(notdir $@), $(COLOR_CYAN))

$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_CLIENT)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) -I$(INC_CLIENT) $(DEBUGFLAGS) -D CLIENT, $(DIR_OBJ)/$(notdir $@), $(COLOR_CYAN))

$(DIR_OBJ)/%.o: $(DIR_SRC)/$(DIR_CRYPTO)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS) -I$(INC_CRYPTO) $(DEBUGFLAGS) -D CRYPTO, $(DIR_OBJ)/$(notdir $@), $(COLOR_CYAN))

$(LIBFT):
	-@make -C $(DIR_LIBFT) NO_HEADER=true

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

info:
	$(info SERV_FILES = $(SERV_FILES))
	$(info CLIE_FILES = $(CLIE_FILES))
	$(info OBJ_SERVER = $(OBJ_SERVER))
	$(info OBJ_CLIENT = $(OBJ_CLIENT))

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
	 ║      \|__|     \|__|    \|__|      \|__| \|__|    \|__|        \|__|      \|__|\|__|      \|_______|   \|__|   \__|   ║ \n \
	 ║                                                                                                                       ║ \n \
	 ║    by nduvoid@student.42mulhouse.fr                                                                                   ║ \n"
	@$(call write_goals)
	@printf " \
	 ║                                                                                                                       ║ \n \
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
