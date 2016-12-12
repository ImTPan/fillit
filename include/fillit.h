/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:05:34 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/11 19:34:52 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
** **small_grid is a 2d char array representation of the tetrimino
** letter is the letter of the alphatet used to represent the tetrimino
** *str is a copy of the string representing the piece in the input file
** *x an array of 4 x values to corresponed with the array of
** *y y values to represent the four points of the tetrimino relative to the
**		first point encountered from left to right at the top of the piece.
** right is the width to the right of the center piece in units
** left is the width to the left of point x[0],y[0] (0,0)
** height is the total height of the tetrimino in units
** *next is the next item in the list.
*/

typedef struct		s_etris
{
	char			**small_grid;
	char			letter;
	char			*str;
	int				*x;
	int				*y;
	int				right;
	int				left;
	int				height;
	struct s_etris	*next;
}					t_etris;

/*
** Holds a pair of xy coordinates for convenient passing between functions
*/

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

/*
** ft_abort.c
*/

void				ft_abort(int err_code);

/*
** tetrimino.c
*/

int					tet_chk(char **tet_grid, int connections, int row,
						int hash);
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
** tsolve.c
*/

int					solve_grid(t_etris *piece, char **map, int map_dim);
int					test_place(t_etris *piece, char **map, t_coord *coords);
void				place_piece(t_etris *piece, char **map, t_coord *coords,
						char c);

#endif
