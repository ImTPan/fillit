/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:20:26 by tpan              #+#    #+#             */
/*   Updated: 2016/12/07 22:31:50 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			tet_chk(char **tet_grid)
{
	int		connections;
	int		row;
	int		col;
	int		hash;

	connections = 0;
	hash		= 0;
	row			= 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tet_grid[row][col] == '#')
			{
				hash++;
				if (col != 0 && tet_grid[row][col - 1] == '#')
					connections++;
				if (col != 3 && tet_grid[row][col + 1] == '#')
					connections++;
				if (row != 0 && tet_grid[row - 1][col] == '#')
					connections++;
				if (row != 3 && tet_grid[row + 1][col] == '#')
					connections++;
			}
			col++;
		}
		row++;
	}
	if ((connections == 6 || connections == 8) && hash == 4)
	{
		ft_putstr("Piece passes tet_chk\n");
		return (1);
	}
	else
		return (0);
}

/*
** This function converts the string to a 2d map.
*/

char		**fill_small_grid(char *str)
{
	int		x;
	int		y;
	int		i;
	char	**grid;

	if (NULL == (grid = (char **)malloc(sizeof(char *) * 4)))
		ft_abort(1);
	i = 0;
	y = 0;
	while (y < 4 && i < 20)
	{
		if (NULL == (grid[y] = (char *)malloc(sizeof(char) * 4)))
			ft_abort(1);
		x = 0;
		while (x < 4)
		{
			grid[y][x] = str[i];
			x++;
			i++;
		}
		y++;
		i++;
	}
	return grid;
}

/*
** just making sure the coordinates are being calculated correctly. This will
** be an unnecessary function in the final version.
*/

void		print_coords(int *x, int *y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_putstr("\nCOORDS\nX: ");
		ft_putnbr(x[i]);
		ft_putstr("\nY: ");
		ft_putnbr(y[i]);
		i++;
	}
}

/*
** Traverses to the end of the list of pieces and then fills in data for a new
** piece.
*/

void		add_piece_to_list(t_etris *list, char *piece, int piece_count)
{
	while (list->next)
		list = list->next;
	if (piece_count > 0)
	{
		if (NULL == (list->next = (t_etris *)malloc(sizeof(t_etris))))
			ft_abort(7);
		list = list->next;
		initialize_list_item(list);
	}
	list->str = ft_strndup(piece, 20);
	ft_putstr("copying piece:\n");
	ft_putstr(list->str);
	list->c = 'A' + piece_count;
	ft_putchar(list->c);
	ft_putstr("\n^ current letter!\n");
	list->small_grid = fill_small_grid(list->str);
	if (!tet_chk(list->small_grid))
		ft_abort(8);
	fill_coords(&list->x, &list->y, list->small_grid, -1, -1);
	print_coords(list->x, list->y);
	return ;
}
