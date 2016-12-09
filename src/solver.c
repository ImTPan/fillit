/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:50:09 by tpan              #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		reset_solution(char **grid)
{
	int i;

	i = 0;
	while (grid[i++])
		free(grid[i]);
	free(grid);
}

/*
** make america free again, used to free the grid in case of backtrack. Unsure
** if this implementation can be used to recurse n levels or just all or none
*/

int		attempt_place(t_etris *piece, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < piece->width)
	{
		j = 0;
		while (j < piece->height)
		{
			if (piece->x[j][i] == '#' && map->array[y + j][x + i] != '.')
				return(0);
			j++;
		}
		i++;
	}
	place_piece(piece, tet_map, colrow, t_etris->letter);
	return (1);
}

/*
** while within range of height and width, checks validity of placing at that 
** spot if the position is occupied by a hash then we can our tetrimino there
** however if there is anything other than a period than we cannot/should not.
*/

static int		solve_grid(t_etris *piece, char **map, int map_size) 
{
	int			col;
	int			row;
	t_coord		coords;

	row = 0;
	while (row < (map_size - piece->height) + 1)
	{
		col = 0;
		while (col < (map_size - piece->width) + 1)
		{
			if (attempt_place(piece, map, col, row))
			{
				if (solve_grid(piece->next, map, map_size))
					return(1);
				coords->row = row;
				coords->col = col;
				place_piece(piece, map, coords, '.');
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	place_piece(t_etris *piece, t_etris **small_grid, t_etris coords, char mark)
{
	int i;
	int j;

	i = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			if (piece->x[j][i] == '#')
				map->array[t_etris->y + j][t_etris->x + i] = mark;
			j++;
		}
		i++;
	}
}
