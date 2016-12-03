/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 23:54:04 by bbauer            #+#    #+#             */
/*   Updated: 2016/12/02 20:51:45 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF_SIZE 20

/*
**	Checks for any invalid characters in input file
*/
int			valid_chars(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

/*
** This will check that the file as a whole and each tetramino is valid.
*/

void		validate_input(char *file, t_etris *piece_list)
{
	int		i;
	int		j;
	int		piece_count;

	if (!valid_chars(file))
		ft_abort(5);
	i = 0;
	j = 0;
	piece_count = 0;
	while (file[i] != '\0')
	{
		j = 0;
		while (j < 21 && j != '\0')
			j++;
		if (j == 21)
		{
			add_piece_to_list(piece_list, &file[i]);
			i += 21;
		}
		piece_count++;
		if (j != 21 || piece_count > 26)
			ft_abort(6);
	}
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
	ft_putstr(input_file); // FOR TESTING PURPOSES ONLY TO CONFIRM INPUT WAS READ
	validate_input(input_file, piece_list);
	return (piece_list);
}
