#include "fillit.h"

/*
** Its the solver control center complete with super recursive karate chop action!
*/

int			solve_grid(t_etris *piece, char **map, int map_size)
{
	int			col;
	int			row;
	t_coord		coords;

	row = 0;
	while (row < map_size - piece->height + 1)
	{
		col = 0;
		while (col < map_size - piece->width + 1)
		{
			coords->x = row;
			coords->y = col;
			if (test_place(piece, map, coords))
			{
				if (solve_grid(piece->next, map, map_size))
					return (1);
				place_piece(piece, map, coords, '.');
			}
			col++;
		}
		row++;
	}
	return (0);
}

/*
** Reworked version of the attempt_place function for simplicity and speed and
** to work with our datastructures. It tests each four points that need to be
** empty to know if we can place a piece here. It does so by adding the start
** coordinate to each of the four relative coordinates of the piece which we
** have calculated and stored in piece->x and piece->y arrays.
*/

int			test_place(t_etris *piece, char ***map, t_coord coords)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (*map[coords->y + piece->y[i]][coords->x + piece->x[i]] != '.')
			return (0);
		i++;
	}
	place_piece(piece, map, coords);
	return (1);
}

/*
** After the coordinates are confirmed as a posible placement location by
** test_place function, this function writes the piece's letter to the
** solution map.
*/

void		place_piece(t_etris *piece, t_etris **small_grid, t_coord coords, char c)
{
	int		i;
	while (i < 4)
		*map[coords->y + piece->y[i]][coords->x + piece->x[i]] = piece->letter;
	return ;
}
