# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 21:14:35 by tpan              #+#    #+#              #
#    Updated: 2016/12/11 20:29:17 by tpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

CC		= gcc

LIBFT	= ./libft/libft.a

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

.PHONY: $(NAME),all, clean, fclean, re, libft

all: libft $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c -I$(INCDIR) -I$(LIBDIR) -I $(LIBFT) $(SRC)
	mkdir -p $(OBJDIR)
	mv $(SRCF:.c=.o) $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) $(OBJ) $(LIBFT) -o $@

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

clean: 
	rm -rf $(OBJDIR)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all 
