/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:42:40 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/06 13:19:37 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	initialize_list_item(t_etris *list_item)
{
	list_item->c = '\0';
	list_item->str = NULL;
	list_item->small_grid = NULL;
	ft_bzero(list_item->x, (sizeof(int) * 4));
	ft_bzero(list_item->y, (sizeof(int) * 4));
	list_item->prev = NULL;
	list_item->next = NULL;
	return ;
}
