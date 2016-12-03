/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:20:26 by tpan              #+#    #+#             */
/*   Updated: 2016/12/02 19:03:30 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		tet_chk(char **tet_grid)
{
	int		connections;
	int		row;
	int		col;
	int 	hash;

	connections = 0;
	while (row < 5)
	{	
		while (col < 4)
		{
			if (tet_grid[row][col] == '#')
				hash++;
			if (col != 0 && tet_grid[row][col - 1] == '#')
				connections++;
			if (col != 4 && tet_grid[row][col + 1] == '#')
				connections++;
			if (row != 0 && tet_grid[row - 1][col] == '#')
				connections++;
			if (row != 3 && tet_grid[row + 1][col] == '#')
				connections++;
			col++;
		}
		row++;
	}
	if ((connections == 6 || connections == 8) && hash == 4)
		return (1);
	else
		return (0);
}

/*
** This function converts the string to a 2d map.
*/
void		fill_small_grid(char **grid, char *str)
{
	int		x;
	int		y;


	while (y < 4)
	{
		while (x < 4)
		{
			
		}
	}
}

/*
** This function will calculate the x,y coordinate values of each point of the
** tetramino for easy math when fitting the piece to the map.
*/
void		fill_coords(int *x, int *y, char **map)
{
	
}

/*
** Traverses to the end of the list of pieces and then fills in data for a new
** piece.
*/

void		add_piece_to_list(t_etris *list, char *piece)
{
	int		i;

	i = 0;
	while (list && list->next)
	{
		list = list->next;
		i++;
	}
	if (!list)
		if (NULL == (list = (t_etris)malloc(sizeof(t_etris *)))
			ft_abort(7);
	else if (NULL == (list->next = (t_etris)malloc(sizeof(t_etris *)))
		ft_abort(7);
	list = list->next;
	list->str = strndup(piece, 21);
	list->c = 'A' + i;
	fill_small_grid(list->small_grid, list->str);
	fill_coords(list->x, list->y, list->small_grid);
	if (!tet_chk(list->small_grid))
		ft_abort(8);
	return ;
}

t_etris *new tetr(char **tet_grid, int x, int y, char letter)
{
	t_etris *tetris;

	tetris = ft_memalloc(sizeof(t_etris));
	tetris->x[] = x;
	tetris->y[] = y;
	tetris->str = tet_grid;
	tetris->c = letter;
	tetris->next = NULL;
	tetris->prev = NULL;
	return (tetris);
}

