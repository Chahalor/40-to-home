# Big Header

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

SRC_SERVER = server.c
SRC_CLIENT = client.c

LIBFT = $(DIR_LIBFT)/libft.a

OBJ_SERVER = $(addprefix $(DIR_OBJ)/, $(SRC_SERVER:.c=.o))
OBJ_CLIENT = $(addprefix $(DIR_OBJ)/, $(SRC_CLIENT:.c=.o))

CC =		cc
CFLAGS =	-Wall -Wextra -Werror
IFLAGS =	-I$(DIR_INC) -I$(DIR_LIBFT)
DEBUGFLAGS =

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all compile

all: header norm compile

compile: server client

client: $(LIBFT) $(NAME_CLIENT)

server: $(LIBFT) $(NAME_SERVER)

# ***************************************************** #
# *                  Compiling                        * #
# ***************************************************** #

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(IFLAGS) $(DEBUG) -o $@ $^ $(LIBFT)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(IFLAGS) $(DEBUG) -o $@ $^ $(LIBFT)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@mkdir -p $(DIR_OBJ)
	$(call compile_object, $(IFLAGS), $(OBJ_SERVER) $(OBJ_CLIENT), $(COLOR_YELLOW))

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
	@echo "Client: $(OBJ_CLIENT)\n $(SRC_CLIENT)"
	@echo "Server: $(OBJ_SERVER)\n $(SRC_SERVER)"

header:
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
	@printf "$(CC) $(CFLAGS) $(DEBUGFLAGS) $(1) -c $< -o $@\n"
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
