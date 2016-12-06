/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:54:04 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/06 13:55:16 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF_SIZE 20

/*
** This will check that the file contains no invalid characters and copy each
** piece to the list. The add_piece_to_list function will perform further
** validation of each piece indivitually..
*/

void		validate_input(char *file, t_etris *piece_list)
{
	int		i;
	int		piece_count;

	i = 0;
	piece_count = 0;
	while (file[i] == '\n' || file[i] == '.' || file[i] == '#')
	{
		
		if (i > 0 && (i % 21) == 0)
		{
			add_piece_to_list(&piece_list, &file[i - 21], i);
			piece_count++;
		}
		i++;
	}
	if ((i % 21) != 20 || file[i] != '\0')
		ft_abort(5);
	return ;
}

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
	char	buff[BUFF_SIZE + 1];
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
			input_file = strndup(buff, BUFF_SIZE + 1);
		else
			ft_memcpycat(&input_file, buff);
	}
	close(fd);
	ft_putstr(input_file); // FOR TESTING PURPOSES ONLY TO CONFIRM INPUT WAS READ
	validate_input(input_file, piece_list);
	return (piece_list);
}
