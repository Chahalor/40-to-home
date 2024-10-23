# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 08:13:34 by nduvoid           #+#    #+#              #
#    Updated: 2024/10/23 15:14:52 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRCS = 

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_printf.c

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

