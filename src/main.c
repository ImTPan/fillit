/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:51:08 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/09 16:02:11 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** prints a square grid of chars with map_size dimensions.!
*/

void		print_map(char **map, int map_size)
{
	int y;
	int x;

	y = 0;
	while (y < map_size)
	{
		x = 0;
		while (x < map_size)
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
** frees the current map (for use when the map has been found to be too small)
*/

void		free_map(char **map, int map_size)
{
	while (--map_size >= 0)
		free(map[map_size]);
	return ;
}

/*
** Creates a new map of map_size dimensions and fills it with '.' characters.
*/

char		**make_new_map(int map_size)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc(sizeof(char *) * map_size);
	if (map == NULL)
		ft_abort(10);
	while (i < map_size)
	{
		map[i] = (char *)malloc(sizeof(char) * map_size);
		if (map[i] == NULL)
			ft_abort(10);
		ft_memset(map[i], 46, map_size);
		i++;
	}
	return (map);
}

int			main(int argc, char **argv)
{
	t_etris		pieces;
	char		**map;
	int			map_size;

	map = NULL;
	if (argc != 2)
		ft_abort(0);
	else
	{
		initialize_list_item(&pieces);
		read_input_file(argv[1], &pieces);
		map_size = 2;
		make_new_map(map_size);
		while (!solve_grid(&pieces, map, map_size))
		{
			free_map(map, map_size);
			map = make_new_map(++map_size);
		}
		print_map(map, map_size);
		ft_putstr(" __ \n/   \\\n|o o|\n| > |\n|__/|  /\\\n|   |_ ||\n|   |  \\\
					|\n|  J   )_)\n \\____/\n    |\n  =\'\n");
	}
	return (0);
}
