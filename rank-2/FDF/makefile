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

# ***************************************************** #
# *                VARIABLES                          * #
# ***************************************************** #

# Name of the executable
NAME :=			fdf

CC :=			cc
CFLAGS =		-Wall -Wextra -Werror -I./$(DIR_INCL)
INCFLAGS = 		-I./$(DIR_INCL)
MLXFLAGS :=		-Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCMLXFLAGS =	-I/usr/include -Imlx
DEBUGFLAGS =

# Directories
DIR_SRC =	src
DIR_OBJ =	.obj
DIR_LIBFT =	libft
DIR_MLX =	minilibx-linux
DIR_INCL =	includes


# All archive files
LIBFT =		$(DIR_LIBFT)/libft.a
MLX_LIB =	$(DIR_MLX)/libmlx_Linux.a

# All source files
SRC =	fdf.c \
		parsing.c \
		utils.c \
		screen.c \
		interactions.c \
		debug.c

# All object files
OBJ = $(addprefix $(DIR_OBJ)/, $(SRC:.c=.o))

# ***************************************************** #
# *                      Main Rules                   * #
# ***************************************************** #

all: write_header norm $(NAME)
	@echo "\033[32m ✅ Compilation done\033[0m"

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) $(MLXFLAGS) -o $(NAME)
	@echo "\033[32m ✅ $@ created\033[0m"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCMLXFLAGS) -c $< -o $@
	-@$(call progress_bar)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(LIBFT):
	@make -C $(DIR_LIBFT) 

$(MLX_LIB):
	@make -C $(DIR_MLX)

# ***************************************************** #
# *                     Debug                         * #
# ***************************************************** #

debug: DEBUGFLAGS += -g3 -D DEBUG=1
debug: INCFLAGS += -I./$(DIR_INCL)/debug.h
debug: all

debug.fsanitize: DEBUGFLAGS += -fsanitize=address
debug.fsanitize: debug

debug.fs: debug.fsanitize

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

clean:
	@rm -rf $(DIR_OBJ)
	-@make -C $(DIR_LIBFT) clean
	-@make -C $(DIR_MLX) clean

fclean: clean
	@rm -f $(NAME)
	-@make -C $(DIR_LIBFT) fclean

re: fclean all

# ***************************************************** #
# *                Header                             * #
# ***************************************************** #

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
	║    \033[4mauthor:\033[0m nduvoid                                                                                           ║ \n\
	║    \033[4mRules:\033[0m $(if $(MAKECMDGOALS), $(MAKECMDGOALS), all)                                                                                                    ║ \n\
	║                                                                                                              ║ \n\
	╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════╝ \n\
	"

# ***************************************************** #
# *                      Utils                        * #
# ***************************************************** #

norm:
	@$(call make_norm)

define make_norm
	@norminette $(DIR_SRC)/ $(DIR_LIBFT)/ > /tmp/norm_output.txt; \
	if grep -q " Error!" /tmp/norm_output.txt; then \
		echo " ❌ \e[31mNorminette failed\e[0m"; \
		cat /tmp/norm_output.txt; \
	else \
		echo " ✅ \e[32mNorminette passed\e[0m"; \
	fi; \
	rm -- /tmp/norm_output.txt
endef

define progress_bar
	printf "\033[A\033[2K"; \
	printf "🔧 Compiling $<... "
	printf "\033[32m["
	for i in $(shell seq 1 30); do \
		if [ $$i -le $(shell echo "$(words $(SRC)) * 2" | bc) ]; then \
			printf "="; \
		else \
			printf " "; \
		fi; \
	done; \
	printf "] $(words $(SRC)) / $(words $(SRC))\033[0m\n"
endef

.PHONY: all clean fclean re write_header debug debug.fsanitize debug.fs norm
