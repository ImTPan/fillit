/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:20:26 by tpan              #+#    #+#             */
/*   Updated: 2016/12/11 14:58:05 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** tet_chk makes sure that there are only 4 hashes in the piece and that each
** hash is touching by counting the number of connections between them.
** The variables row, hash, and connections are all passed in as zero to save
** lines (norm compliance!)
*/

int			tet_chk(char **tet_grid, int connections, int row, int hash)
{
	int		col;

	while (row < 4)
	{
		col = 0;
		while (col++ < 4)
			if (tet_grid[row][col - 1] == '#')
			{
				hash++;
				if (col != 0 && tet_grid[row][col - 2] == '#')
					connections++;
				if (col != 4 && tet_grid[row][col] == '#')
					connections++;
				if (row != 0 && tet_grid[row - 1][col - 1] == '#')
					connections++;
				if (row != 3 && tet_grid[row + 1][col - 1] == '#')
					connections++;
			}
		row++;
	}
	if ((connections == 6 || connections == 8) && hash == 4)
		return (1);
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
	return (grid);
}

/*
** Calculates the height and width of the piece.
*/

void		calc_dimensions(t_etris *piece)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (piece->x[i] > piece->right)
			piece->right = (piece->x[i] + 1);
		if (piece->x[i] < piece->left)
			piece->left = piece->x[i];
		if ((piece->y[i] + 1) > piece->height)
			piece->height = (piece->y[i] + 1);
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
	list->letter = 'A' + piece_count;
	list->small_grid = fill_small_grid(list->str);
	if (!tet_chk(list->small_grid, 0, 0, 0))
		ft_abort(8);
	fill_coords(list, -1, -1);
	calc_dimensions(list);
	return ;
}
