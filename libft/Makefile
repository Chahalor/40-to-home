# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nduvoid <nduvoid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 08:13:34 by nduvoid           #+#    #+#              #
#    Updated: 2024/10/22 15:43:15 by nduvoid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_additionalP1.c \
		ft_allocFunc.c \
		ft_isfunc.c \
		ft_itoa.c \
		ft_memfunc.c \
		ft_memfunc2.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strfunc.c \
		ft_strFunc2.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strtrim.c \
		ft_txt.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

AR = ar
FLAGS = rcs
RM = rm -f

BONUS_OBJS =

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_BONUS)
	$(AR) $(FLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)

bonus : BONUS_OBJS = $(OBJS_BONUS)
bonus : $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re bonus
