/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:51:08 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/03 17:47:18 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	t_etris		pieces;

//	pieces = NULL;
	if (argc != 2)
		ft_abort(0);
	else
	{
		read_input_file(argv[1], &pieces);
	}
	return (0);
}
