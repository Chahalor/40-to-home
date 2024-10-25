# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 08:13:34 by nduvoid           #+#    #+#              #
#    Updated: 2024/10/25 16:58:34 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCSDIR = srcs
INCDIR = includes 
OBJDIR = objs

SRCS =	$(SRCSDIR)/put_func.c \
		$(SRCSDIR)/put_func2.c \
		$(SRCSDIR)/put_func3.c \
		$(SRCSDIR)/ft_printf.c

INCLUDES = libft.a

OBJS = $(SRCS:.c=.o)

SRCS_BONUS =

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
