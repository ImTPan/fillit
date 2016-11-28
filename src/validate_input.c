/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 19:13:43 by tpan              #+#    #+#             */
/*   Updated: 2016/11/27 21:40:18 by tpan             ###   ########.fr       */
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

int		tet_file_chk(char *tab, int *num_tets)
{

}

