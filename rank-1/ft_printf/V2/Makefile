# Compiler et flags
CC			= cc
AR			= ar rcs
CFLAGS		= -Wall -Wextra -Werror -I. -I_internal -MMD
BUILD_DIR	= .build

# Archive statique
NAME		= libftprintf.a

# Fichiers sources principaux
SRCS		= ft_printf.c \
			  interface.c \
			  _internal/printf/writer.c \
			  _internal/utils/_utils.c

# Objets et dépendances
OBJS		= $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

# Crée .build si besoin
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) \
		$(dir $(OBJS))

# Règles
all: $(BUILD_DIR) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compilation avec redirection vers .build
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Inclusion des dépendances générées avec -MMD
-include $(DEPS)
