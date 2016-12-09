/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:05:34 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/08 17:26:47 by bbauer           ###   ########.fr       */
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
	char			letter;		//letter of alphabet used to represent piece in solution
	char			*str;	//raw map of piece from input file, probably won't need
	int				*x;	//x,y coordinates of each of the four filled positions of
	int				*y;	//the input, starting with 0,0 as the top-most  piece
	int				width;
	int				height;
	struct s_etris	*next;	//encountered from left to right, and all other coordinates
	struct s_etris	*prev;	//relative to that position.
}					t_etris;

typedef struct		s_coord
{
	int				col;
	int				row;
}					t_coord

/*
** ft_abort.c
*/

void				ft_abort(int err_code);

/*
** tetrimino.c
*/

int					tet_chk(char **tet_grid, int connections, int row, int hash);
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

void				fill_coords(t_etris *piece, int xzer, int yzer);

/*
** main.c
*/

int					main(int argc, char **argv);
char				**make_new_map(int map_size);
void				free_map(char **map, int map_size);
void				print_map(char **map, int map_size);

/*
** lists.c
*/

void				initialize_list_item(t_etris *list_item);

/*
** solver.c
*/


#endif
