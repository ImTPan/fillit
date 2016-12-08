/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:10:57 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/08 12:30:20 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set_origin(int *xzero, int *yzero, int x, int y)
{
	*xzero = x;
	*yzero = y;
}

static void		set_x_y(int *xpnt, int *ypnt, int x, int y)
{
	*xpnt = x;
	*ypnt = y;
}

/*
** This function will calculate the x,y coordinate values of each point of the
** tetrimino for easy math when fitting the piece to the map. The results are
** saved in xpnt and ypnt int arrays. xzero and yzero are local variables but
** are passed in as -1 to save four lines and make this function norm compliant.
*/

void			fill_coords(t_etris *piece, int xzer, int yzer)
{
	int		x;
	int		y;
	int		i;

	i = 1;
	set_x_y(&(piece->x[0]), &(piece->y[0]), 0, 0);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x++ < 4)
			if (piece->small_grid[y][x - 1] == '#')
			{
				if (yzer == -1 && xzer == -1)
					set_origin(&xzer, &yzer, x - 1, y);
				else
				{
					set_x_y(&(piece->x[i]), &(piece->y[i]),
								x - xzer - 1, y - yzer);
					i++;
				}
			}
		y++;
	}
}
