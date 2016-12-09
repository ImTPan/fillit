# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 21:14:35 by tpan              #+#    #+#              #
#    Updated: 2016/12/09 15:38:29 by tpan             ###   ########.fr        #
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
		  tetrimino.c \
		  lists.c \
		  tsolve.c \

OBJ		= $(addprefix $(OBJDIR),$(SRCF:.c=.o))

OBJDIR	= ./obj/
SRCDIR	= ./src/
LIBDIR	= ./libft/
INCDIR	= ./include/

.PHONY: $(NAME), all, clean, fclean, re, libft, libft-clean, libft-fclean

all: $(NAME)

$(NAME): libft
	$(CC) $(CFLAGS) -c -I$(INCDIR) -I$(LIBDIR) $(SRC)
	mkdir -p $(OBJDIR)
	mv $(SRCF:.c=.o) $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) $(OBJ) $(LIBFT) -o $@

libft:
	make -C ./libft re

libft-clean:
	make -C ./libft clean

libft-fclean:
	make -C ./libft fclean

clean: libft-clean
	rm -rf $(OBJDIR)

fclean: clean libft-fclean
	rm -rf $(NAME)

re: fclean all 
