/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:47:44 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/11 14:44:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_abort(int err_code)
{
	ft_putstr("error!\n");
	if (err_code == 0)
		ft_putstr("usage: ./fillit.a path/to/map\n");
	if (err_code >= 1)
		ft_putstr("error\n");
	exit(0);
}
