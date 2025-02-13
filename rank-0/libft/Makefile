# ╔════════════════════════════════════════════════════════════════════════════════╗
# ║                                                                                ║
# ║   ___               ___          ________          ________      _________     ║
# ║  |\  \             |\  \        |\   __  \        |\  _____\    |\___   ___\   ║
# ║  \ \  \            \ \  \       \ \  \|\ /_       \ \  \__/     \|___ \  \_|   ║
# ║   \ \  \            \ \  \       \ \   __  \       \ \   __\         \ \  \    ║
# ║    \ \  \____        \ \  \       \ \  \|\  \       \ \  \_|          \ \  \   ║
# ║     \ \_______\       \ \__\       \ \_______\       \ \__\            \ \__\  ║
# ║      \|_______|        \|__|        \|_______|        \|__|             \|__|  ║
# ║                                                                                ║
# ║  by nduvoid                                                                    ║
# ║                                                                                ║
# ╚════════════════════════════════════════════════════════════════════════════════╝

MAKEFLAGS += --no-print-directory	# no Entering / Leaving messages

# ***************************************************** #
# *                 Variable                          * #
# ***************************************************** #

NAME = libft.a

CC :=		cc
CFLAGS :=	-Wall -Wextra -Werror -I./ -Ift_printf -Iget_next_line
DEBUGFLAGS :=
AR :=		ar
ARFLAGS :=	rcs

DIR_LIBFT =		src
DIR_PRINTF =	ft_printf
DIR_GNL =		get_next_line

INCFLAGS :=	-I./ -I$(DIR_PRINTF) -I$(DIR_GNL)

# achive
#...

# ***************************************************** #
# *                    DIR                            * #
# ***************************************************** #

# dir libft

FT_DIR_CHAR_CHANGE = char-change
FT_DIR_IS = is
FT_DIR_LINKED_LIST = linked-list
FT_DIR_MEMORY = memory
FT_DIR_PUT = put
FT_DIR_STR = str
FT_DIR_STR_CHANGE = str-change

FT_DIR_ALL = $(FT_DIR_CHAR_CHANGE) $(FT_DIR_IS) $(FT_DIR_LINKED_LIST) $(FT_DIR_MEMORY) $(FT_DIR_PUT) $(FT_DIR_STR) $(FT_DIR_STR_CHANGE)

# ***************************************************** #
# *                    SRC                            * #
# ***************************************************** #

# libft

SRC_IS = $(addprefix $(DIR_LIBFT)/$(FT_DIR_IS)/, \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
)

SRC_CHAR_CHANGE = $(addprefix $(DIR_LIBFT)/$(FT_DIR_CHAR_CHANGE)/, \
	ft_toupper.c \
	ft_tolower.c \
)

SRC_LINKED_LIST = $(addprefix $(DIR_LIBFT)/$(FT_DIR_LINKED_LIST)/, \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
)

SRC_MEMORY = $(addprefix $(DIR_LIBFT)/$(FT_DIR_MEMORY)/, \
	ft_calloc.c \
	ft_bzero.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
)

SRC_PUT = $(addprefix $(DIR_LIBFT)/$(FT_DIR_PUT)/, \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
)

SRC_STR = $(addprefix $(DIR_LIBFT)/$(FT_DIR_STR)/, \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
)

SRC_STR_CHANGE = $(addprefix $(DIR_LIBFT)/$(FT_DIR_STR_CHANGE)/, \
	ft_atoi.c \
	ft_itoa.c \
	ft_split.c \
)

SRC_LIBFT = $(SRC_IS) $(SRC_CHAR_CHANGE) $(SRC_LINKED_LIST) $(SRC_MEMORY) $(SRC_PUT) $(SRC_STR) $(SRC_STR_CHANGE)

# printf

SRC_PRINTF = $(addprefix $(DIR_PRINTF)/, \
	ft_printf.c \
	put_func.c \
	put_func2.c \
	put_func3.c \
)

# gnl

SRC_GNL = $(addprefix $(DIR_GNL)/, \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
)

# ***************************************************** #
# *                    OBJ                            * #
# ***************************************************** #

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
OBJ_GNL = $(SRC_GNL:.c=.o)

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

.PHONY: all

all: header norm $(NAME)

$(NAME): compile
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL)
	@echo "\033[32m ✅ $(NAME) created\033[0m"

# ***************************************************** #
# *                 Compile Rule                      * #
# ***************************************************** #

.PHONY: compile

compile: echo $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL)
	@echo "\033[32m ✅ Compilation done\033[0m"

$(DIR_OBJ)/%.o: $(DIR_LIBFT)/%.c | $(DIR_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_PRINTF)/%.c | $(DIR_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(DIR_OBJ)/%.o: $(DIR_GNL)/%.c | $(DIR_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCFLAGS) $(DEBUGFLAGS) -c $< -o $@

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

# ***************************************************** #
# *                    Clean Rules                    * #
# ***************************************************** #

.PHONY: clean fclean re

clean:
	@rm -f $(OBJ_LIBFT) $(OBJ_PRINTF) $(OBJ_GNL)
	@rm -rf $(DIR_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

# ***************************************************** #
# *                    Debug Rules                    * #
# ***************************************************** #

.PHONY: debug

debug: 
	@$(eval DEBUGFLAGS = -g)
# @echo "\033[32m ✅ Debug mode activated\033[0m"
#@make all

# ***************************************************** #
# *                    Utils                          * #
# ***************************************************** #

.PHONY: norm header

echo:
	@echo "SRC_LIBFT: $(SRC_LIBFT)\n"
	@echo "OBJ_LIBFT: $(OBJ_LIBFT)\n"
	@echo "INCLUDES: $(INCFLAGS)\n"

norm:
	@if norminette $(DIR_LIBFT) $(DIR_PRINTF) $(DIR_GNL) | grep "Error" > /dev/null; then \
		norminette $(DIR_LIBFT) $(DIR_PRINTF) $(DIR_GNL) | grep "Error" > /dev/null; \
		echo "\033[1;32m Norminette errors found \033[0m"; \
	else \
		echo "norminette Ok ✅"; \
	fi

header:
	@echo "\n"
	@echo "╔════════════════════════════════════════════════════════════════════════════════╗"
	@echo "║   ___               ___          ________          ________      _________     ║"
	@echo "║  |\  \             |\  \        |\   __  \        |\  _____\    |\___   ___\   ║"
	@echo "║  \ \  \            \ \  \       \ \  \|\ /_       \ \  \__/     \|___ \  \_|   ║"
	@echo "║   \ \  \            \ \  \       \ \   __  \       \ \   __\         \ \  \    ║"
	@echo "║    \ \  \            \ \  \       \ \  \|\  \       \ \  \_|          \ \  \   ║"
	@echo "║     \ \  \____        \ \  \       \ \  \|\  \       \ \  \_|          \ \  \  ║"
	@echo "║      \ \_______\       \ \__\       \ \_______\       \ \__\            \ \__\ ║"
	@echo "║       \|_______|        \|__|        \|_______|        \|__|             \|__| ║"
	@echo "║                                                                                ║"
	@echo "║  by nduvoid                                                                    ║"
	@echo "║                                                                                ║"
	@echo "╚════════════════════════════════════════════════════════════════════════════════╝"
	@echo "\n"

# ***************************************************** #
# *                    Functions                      * #
# ***************************************************** #

.PHONY: reset_count

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
	printf "	$(CC) $(CFLAGS) $(INCFLAGS) $(DEBUGFLAGS) $(1) -c $< -o $@\n"
	$(CC) $(CFLAGS) $(INCFLAGS) $(DEBUGFLAGS) $(1) -c $< -o $@
	@printf "\r$(3)\bCompiling %s%*s[%-$(BAR_LENGTH)s] %d/%d$(COLOR_RESET)" \
		"$<" \
		$$(($(PADDING) - $$(echo -n "$(NAME)" | wc -c))) "" \
		$(shell printf '=%.0s' $$(seq 1 $$(echo "$$(( $(BAR_LENGTH) * $(COUNT) / $(words $(2)) ))"))) \
		$(COUNT) \
		$(words $(2))
		printf " "
	@true
endef

