# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 21:14:35 by tpan              #+#    #+#              #
#    Updated: 2016/11/23 09:38:13 by tpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft
LIBLINK	= -L./libft -lft

CFLAGS 	= -Wall -Wextra -Werror

SRC 	= main.c \

OBJ 	= $(SRC:.c=.o)
	
.PHONY: $(NAME), all, clean, fclean, re

all: libft $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) -c $(SRC) $
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

libft:
	make -C ./libft
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all 
