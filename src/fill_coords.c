/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:10:57 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/07 15:48:52 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		set_origin(int *xzero, int *yzero, int x, int y)
{
	*xzero = x;
	*yzero = y;
}

void		set_x_y(int *xpnt, int *ypnt, int x, int y)
{
	*xpnt = x;
	*ypnt = y;
}

/*
** For testing purposes only!
*/

void		print_map(char **map)
{
	int y;
	int x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	return ;
}

/*
** This function will calculate the x,y coordinate values of each point of the
** tetrimino for easy math when fitting the piece to the map. The results are
** saved in xpnt and ypnt int arrays. xzero and yzero are local variables but
** are passed in as -1 to save four lines and make this function norm compliant.
*/

void		fill_coords(int **xpnt, int **ypnt, char **map, int xzer, int yzer)
{
	int		x;
	int		y;

	*xpnt = (int *)malloc(sizeof(int) * 4);
	*ypnt = (int *)malloc(sizeof(int) * 4);
	if (*xpnt == NULL || *ypnt == NULL)
		ft_abort(9);
	set_x_y((*xpnt)++, (*ypnt)++, 0, 0);
	y = 0;
	while (y < 4)
	{
		x = 1;
		while (x++ < 4)
			if (map[y][x - 1] == '#')
			{
				if (yzer == -1 && xzer == -1)
					set_origin(&xzer, &yzer, (x - 1), y);
				else
					set_x_y((*xpnt)++, (*ypnt)++, ((x - 1) - xzer), (y - yzer));
			}
		y++;
	}
}
