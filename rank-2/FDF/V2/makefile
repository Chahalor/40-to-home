# ╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗ 
# ║                                                                                                                             ║ 
# ║   ________  ___      ___           _______           ________      _______           ________  _______       ________       ║ 
# ║  |\  _____\|\  \    |\  \         |\  ___ \         |\   ___ \    |\  ___ \         |\  _____\|\  ___ \     |\   __  \      ║ 
# ║  \ \  \__/ \ \  \   \ \  \        \ \   __/|        \ \  \_|\ \   \ \   __/|        \ \  \__/ \ \   __/|    \ \  \|\  \     ║ 
# ║   \ \   __\ \ \  \   \ \  \        \ \  \_|/__       \ \  \ \\ \   \ \  \_|/__       \ \   __\ \ \  \_|/__   \ \   _  _\    ║ 
# ║    \ \  \_|  \ \  \   \ \  \____    \ \  \_|\ \       \ \  \_\\ \   \ \  \_|\ \       \ \  \_|  \ \  \_|\ \   \ \  \\  \|   ║ 
# ║     \ \__\    \ \__\   \ \_______\   \ \_______\       \ \_______\   \ \_______\       \ \__\    \ \_______\   \ \__\\ _\   ║ 
# ║      \|__|     \|__|    \|_______|    \|_______|        \|_______|    \|_______|        \|__|     \|_______|    \|__|\|__|  ║ 
# ║                                                                                                                             ║ 
# ║    By nduvoid                                                                                                               ║ 
# ║                                                                                                                             ║ 
# ╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝

MAKEFLAGS += --no-print-directory	# no Entering / Leaving messages

# ***************************************************** #
# *                VARIABLES                          * #
# ***************************************************** #

# Name of the executable
NAME :=			fdf

CC :=			cc
CFLAGS =		-Wall -Wextra -Werror -I./$(DIR_INCL)
INCFLAGS = 		-I./$(DIR_INCL)
MLXFLAGS :=		-Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCMLXFLAGS :=	-I/usr/include -Imlx
DEBUGFLAGS =
ARGS =

# Directories
DIR_SRC :=		src
DIR_OBJ :=		.obj
DIR_LIBFT :=	libft
DIR_MLX :=		minilibx-linux
DIR_INCL :=		includes

# All include files
INC_GLOBAL :=	includes
INC_LIBFT :=	$(DIR_LIBFT)
INC_ALGO :=		$(DIR_SRC)/algo
INC_CMD :=		$(DIR_SRC)/cmd
INC_ARGS :=		$(DIR_SRC)/init/args
INC_GRAPH :=	$(DIR_SRC)/graphic
INC_INIT :=		$(DIR_SRC)/init
INC_UTILS :=	$(DIR_SRC)/utils
INC_DEBUG :=	$(DIR_SRC)/debug
ALL_INC :=		$(INC_GLOBAL) $(INC_LIBFT) $(INC_ALGO) $(INC_CMD) $(INC_ARGS) $(INC_GRAPH) $(INC_INIT) $(INC_UTILS) $(INC_DEBUG)
INCLUDES :=		$(foreach dir,$(ALL_INC),-I$(dir))

# All archive files
LIBFT :=	$(DIR_LIBFT)/libft.a
MLX_LIB :=	$(DIR_MLX)/libmlx_Linux.a

# All source files
SRC_ALGO :=		algo/projection.c

SRC_CMD :=		cmd/cmd.c \
				cmd/parsing.c

SRC_DEBUG :=	debug/debug.c

SRC_GRAPH :=	graphic/HookProc.c \
				graphic/model.c \
				graphic/window.c

SRC_INIT :=		init/args/args.c \
				init/args/args_parsing.c \
				init/args/args_utils.c \
				init/init.c \
				init/parsing.c \
				init/fdf.c

SRC_UTILS :=	utils/utils.c

SRC := $(SRC_ALGO) $(SRC_CMD) $(SRC_DEBUG) $(SRC_GRAPH) $(SRC_INIT) $(SRC_UTILS)

# All object files
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

# ***************************************************** #
# *                      Main Rules                   * #
# ***************************************************** #

all: write_header norm $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) compile

# ***************************************************** #
# *                 Compile Rule                      * #
# ***************************************************** #

.PHONY: compile

compile: $(DIR_OBJ) $(OBJ)
	@printf "\n"
	@echo "\033[32m ✅ Compilation done\033[0m"
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) $(MLXFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) -lm -lX11 -lXext -o $(NAME)
	@echo "\033[32m ✅ $(NAME) created\033[0m"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@mkdir -p $(dir $@)
	@$(call compile_object,  $(INCLUDES) $(INCFLAGS) $(INCMLXFLAGS), $(SRC), $(COLOR_YELLOW))

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(LIBFT):
	@make -C $(DIR_LIBFT)

$(MLX_LIB):
	@make -s -C $(DIR_MLX)

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	@rm -rf $(DIR_OBJ)
	-@make -C $(DIR_LIBFT) clean
	-@make -C $(DIR_MLX) clean

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
	@echo $(OBJ)
	@echo $(SRC)

write_header:
	@clear
	@printf "\n\
	╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════╗ \n\
	║                                                                                                              ║ \n\
	║   ________  ___      ___              ________      _______           ________  _______       ________       ║ \n\
	║  |\  _____\|\  \    |\  \            |\   ___ \    |\  ___ \         |\  _____\|\  ___ \     |\   __  \      ║ \n\
	║  \ \  \__/ \ \  \   \ \  \           \ \  \_|\ \   \ \   __/|        \ \  \__/ \ \   __/|    \ \  \|\  \     ║ \n\
	║   \ \   __\ \ \  \   \ \  \           \ \  \ \\\\\\ \   \ \  \_|/__       \ \   __\ \ \  \_|/__   \ \   _  _\    ║ \n\
	║    \ \  \_|  \ \  \   \ \  \____       \ \  \_\\\\\\ \   \ \  \_|\ \       \ \  \_|  \ \  \_|\ \   \ \  \\\\\\\  \|   ║ \n\
	║     \ \__\    \ \__\   \ \_______\      \ \_______\   \ \_______\       \ \__\    \ \_______\   \ \__\\\\\\\ _\   ║ \n\
	║      \|__|     \|__|    \|_______|       \|_______|    \|_______|        \|__|     \|_______|    \|__|\|__|  ║ \n\
	║                                                                                                              ║ \n\
	║    \033[4mAuthor:\033[0m  nduvoid                                                                                          ║ \n"
	@$(write_goals);
	@printf "\
	║                                                                                                              ║ \n\
	╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════╝ \n\
	"

norm:
	@$(call make_norm)

define make_norm
	@norminette $(DIR_SRC)/ $(DIR_LIBFT)/ $(DIR_INCL)/fdf.h > /tmp/norm_output.txt; \
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
