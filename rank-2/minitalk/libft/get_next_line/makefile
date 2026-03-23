# big header

NAME :=		libftgnl.a

CC :=		cc
CFLAGS :=	-Wall -Wextra -Werror
AR :=		ar
ARFLAGS :=		rcs

SRCDIR :=	./
OBJDIR :=	.obj
INCDIR :=	./

SRC :=		get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OBJ :=		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# ***************************************************** #
# *                    Rules                          * #
# ***************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re