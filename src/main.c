/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:51:08 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/27 20:56:22 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etris		*create_list()
{
	t_etris		list;

	if ((list = (t_etris *)malloc(sizeof(*list))) == NULL)
		return (NULL);
	list->c = '\0'
	list->str = NULL;
	list->next = NULL;
	list->prev = NULL;
}

int			main(int argc, char **argv)
{
	t_etris		*pieces;

	if (argc != 2)
		ft_abort(0);
	else
	{
		ft_bzero(pieces, (sizeof(t_etris) * 27));
		read_input_file(argv[1], pieces);
	}
	return (0);
}
