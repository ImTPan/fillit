# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 21:14:35 by tpan              #+#    #+#              #
#    Updated: 2016/12/04 10:26:50 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft
LIBLINK	= -L./libft -lft

CFLAGS 	= -Wall -Wextra -Werror

SRC		= $(addprefix $(SRCDIR),$(SRCF))

SRCF 	= main.c \
		  ft_abort.c \
		  ft_read.c \
		  fill_coords.c \
		  tetrimino.c

OBJ		= $(addprefix $(OBJDIR),$(SRCF:.c=.o))

OBJDIR	= ./obj/
SRCDIR	= ./src/
LIBDIR	= ./libft/
INCDIR	= ./include/

.PHONY: $(NAME), all, clean, fclean, re

all: $(NAME)

$(NAME): libft
	$(CC) $(CFLAGS) -c -I$(INCDIR) -I$(LIBDIR) $(SRC)
	ar rcs $(NAME) $(OBJ)

obj:
	mkdir -p $(OBJDIR)
	

libft:
	make -C ./libft

libft-clean:
	make -C ./libft clean

libft-fclean:
	make -C ./libft fclean

clean: libft-clean
	rm -rf $(OBJ)

fclean: clean libft-fclean
	rm -rf $(NAME)

re: fclean all 
