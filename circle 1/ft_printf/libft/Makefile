# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 08:13:34 by nduvoid           #+#    #+#              #
#    Updated: 2024/10/23 15:15:03 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_itoa.c \
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

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

AR = ar
FLAGS = rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS)
	$(AR) $(FLAGS) $(NAME) $(OBJS) $(BONUS_OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(FLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

