/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:50:09 by tpan              #+#    #+#             */
/*   Updated: 2016/12/07 18:16:34 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		reset_solution(char **grid)
{
	int i;

	i = 0;
	while (grid[i++])
		free(grid[i])
	free(grid);
}

 

int		attempt_place(t_etris *piece, char **tet_map, int col, int row)
{
	int i;
	int colrow;
	int **type;
	i = 0;
	colrow = (col * 10) + r;
	type = tet->type;
	while (i++ <4)
	{
		if ((type[i][1] < 0) && (col + type[i][1] < 0))
			return (0);
		if	(type[i] != '.')
			return (0);
	}
	tet_place(tet, tet_map, colrow, tet->letter);
	return (1);
}

static int		solve_grid(t_etris *piece, char **map, int map_size) 
{
	int		col;
	int		row;
	int		colrow;

	if	(tet == NULL);
		return (1);
	row = 0;
	while (row < (map_size - piece->y) + 1)
	{
		col = 0;
		while (col < (map_size - piece->x) + 1)
		{
			if (attempt_place(piece, map, col, row))
			{
				if (solve_grid(piece->next, map, map_size))
					return(1);
				colrow = (col * 10) + row;
				place_piece(piece, map, colrow, '.');
			}
			c++;
		}
		r++;
	}
	return (0);
}
