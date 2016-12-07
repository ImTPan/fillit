/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:05:34 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/07 07:32:24 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct		s_etris
{
	char			**small_grid;	// 2-d representation of the piece
	char			c;		//letter of alphabet used to represent piece in solution
	char			*str;	//raw map of piece from input file, probably won't need
	int				*x;	//x,y coordinates of each of the four filled positions of
	int				*y;	//the input, starting with 0,0 as the top-most  piece
	struct s_etris	*next;	//encountered from left to right, and all other coordinates
	struct s_etris	*prev;	//relative to that position.
}					t_etris;

/*
** ft_abort.c
*/

void				ft_abort(int err_code);

/*
** tetrimino.c
*/

int					tet_chk(char **tet_grid);
char				**fill_small_grid(char *str);
void				add_piece_to_list(t_etris *list, char *piece, int index);

/*
** ft_read.c
*/

t_etris				*read_input_file(char *file, t_etris *tab);
void				ft_memcpycat(char **input_file, char *buff);
void				validate_input(char *file, t_etris *piece_list);

/*
** fill_coords.c
*/

void				fill_coords(int **xpnt, int **ypnt, char **map, int xzer, int yzer);
void				set_origin(int *xzero,int *yzero, int x, int y);
void				set_x_y(int *xpnt, int *ypnt, int x, int y);

/*
** main.c
*/

int					main(int argc, char **argv);

/*
** lists.c
*/

void				initialize_list_item(t_etris *list_item);

#endif
