/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:10:57 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/06 17:42:18 by bbauer           ###   ########.fr       */
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
** saved in xpnt and ypnt int arrays.
*/

void		fill_coords(int **xpnt, int **ypnt, char **map)
{
	int		x;
	int		y;
	int		xzero;
	int		yzero;
	int		i;

	ft_putstr("verify map:\n");
	print_map(map);
	i = 1;
	xzero = -1;
	yzero = -1;
	*xpnt = (int *)malloc(sizeof(int) * 4);
	*ypnt = (int *)malloc(sizeof(int) * 4);
	set_x_y(*xpnt, *ypnt, 0, 0);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (++x < 4)
			if (map[y][x - 1] == '#')
			{
				if (yzero == -1 && xzero == -1)
					set_origin(&xzero, &yzero, (x - 1), y);
				else
					set_x_y(xpnt[i], ypnt[i], (x - 1), y);
				i++;
			}
		y++;
	}
}
