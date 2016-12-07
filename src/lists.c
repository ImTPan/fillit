/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:42:40 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/06 17:02:59 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	initialize_list_item(t_etris *list_item)
{
	list_item->c = '\0';
	list_item->str = NULL;
	list_item->small_grid = NULL;
	list_item->x = NULL;
	list_item->y = NULL;
	list_item->prev = NULL;
	list_item->next = NULL;
	return ;
}
