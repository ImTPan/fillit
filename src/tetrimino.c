/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:20:26 by tpan              #+#    #+#             */
/*   Updated: 2016/12/01 17:44:01 by tpan             ###   ########.fr       */
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

