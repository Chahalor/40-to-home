# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 08:13:34 by nduvoid           #+#    #+#              #
#    Updated: 2024/12/11 13:14:13 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCDIR =	src
PRINTFDIR =	ft_printf
GNLDIR =	get_next_line
OBJDIR =	.obj

SRC_LIBFT =	ft_itoa.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strtrim.c \
			ft_strlcat.c \
			ft_strjoin.c \
			ft_strdup.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_memcmp.c \
			ft_bzero.c \
			ft_strchr.c \
			ft_strnstr.c \
			ft_tolower.c \
			ft_atoi.c \
			ft_strlcpy.c \
			ft_substr.c \
			ft_calloc.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_toupper.c

LIBFT_BONUS =	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c

FT_PRINTF_SRC =	ft_printf.c \
				put_func.c \
				put_func2.c \
				put_func3.c

GNL_SRC =	get_next_line_bonus.c \
			get_next_line_utils_bonus.c

LIBFT_OBJ =			$(addprefix $(OBJDIR)/, $(SRC_LIBFT:.c=.o))
LIBFT_BONUS_OBJ =	$(addprefix $(OBJDIR)/, $(LIBFT_BONUS:.c=.o))
FT_PRINTF_OBJ =		$(addprefix $(OBJDIR)/, $(FT_PRINTF_SRC:.c=.o))
GNL_OBJ =			$(addprefix $(OBJDIR)/, $(GNL_SRC:.c=.o))

AR =		ar
FLAGS =		rcs
RM =		rm -f
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(FT_PRINTF_OBJ) $(GNL_OBJ)
	@$(AR) $(FLAGS) $(NAME) $(LIBFT_OBJ) $(FT_PRINTF_OBJ) $(GNL_OBJ)
	@echo "libft.a created"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(PRINTFDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(GNLDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(LIBFT_OBJ) $(LIBFT_BONUS_OBJ) $(FT_PRINTF_OBJ) $(GNL_OBJ)
	@rmdir $(OBJDIR) 2> /dev/null || true
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re bonus
