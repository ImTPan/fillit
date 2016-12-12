/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:42:40 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/11 19:40:08 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	initialize_list_item(t_etris *list_item)
{
	list_item->letter = '\0';
	list_item->str = NULL;
	list_item->small_grid = NULL;
	list_item->x = (int *)malloc(sizeof(int) * 4);
	list_item->y = (int *)malloc(sizeof(int) * 4);
	if (list_item->x == NULL || list_item->y == NULL)
		ft_abort(9);
	list_item->left = 0;
	list_item->right = 0;
	list_item->height = 0;
	list_item->next = NULL;
	return ;
}
