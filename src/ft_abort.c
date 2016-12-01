/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:47:44 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/30 18:36:16 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_abort(int err_code)
{
	ft_putstr("error!\n");
	if (err_code == 0)
		ft_putstr("usage: ./fillit.a path/to/map\n");
	if (err_code == 1)
		ft_putstr("might as well kill yourself now...\n");
	if (err_code == 2)
		ft_putstr("invalid input file\n");
	if (err_code == 3)
		ft_putstr("malloc error at initialization!\n");
	if (err_code == 4)
		ft_putstr("error opening or reading specified file!\n");
	if (err_code == 5)
		ft_putstr("invalid char in input file!");
	if (err_code == 6)
		ft_putstr("invalid input file!");
	exit(0);
}
