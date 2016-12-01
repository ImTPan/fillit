/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:54:04 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/27 21:24:22 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF_SIZE 20

/*
** Copies bytes read so far to new larger memory area and concatenates the
** buffer before freeing the original memory location.
*/

void		ft_memcpycat(char **input_file, char *buff)
{
	char	*input_old;

	input_old = *input_file;
	*input_file = ft_strjoin(*input_file, buff);
	ft_memdel((void **)&input_old);
	return ;
}

/*
** Read entire input file into memory
*/

t_etris		*read_input_file(char *file, t_etris *piece_list)
{
	int		fd;
	int		ret;
	char	buff[21];
	char	*input_file;

	input_file = NULL;
	ret = 1;
	if (-1 == (fd = open(file, O_RDONLY)))
		ft_abort(4);
	while (ret != 0)
	{
		if (-1 == (ret = read(fd, buff, BUFF_SIZE)))
			ft_abort(4);
		buff[ret] = '\0';
		if (!input_file)
			input_file = strndup(buff, 21);
		else
			ft_memcpycat(&input_file, buff);
	}
	close(fd);
	ft_putstr(input_file);
	validate_input(input_file, piece_list);
	return (tab);
}
