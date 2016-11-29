/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:13:43 by tpan              #+#    #+#             */
/*   Updated: 2016/11/29 15:27:57 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		tet_chk_connect(char **tet_grid, int row, int col)
{
	int		connections;

	connections = 0;
	if (col != 0 && tet_grid[row][col - 1] == '#')
		connections++;
	if (col != 4 && tet_grid[row][col + 1] == '#')
		connections++;
	if (row != 0 && tet_grid[row - 1][col] == '#')
		connections++;
	if (row != 3 && tet_grid[row + 1][col] == '#')
		connections++;
	return (connections);
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

