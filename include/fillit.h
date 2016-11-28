/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:05:34 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/27 21:21:02 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct		s_etris
{
	char			c;		//letter of alphabet used to represent piece in solution
	char			*str;	//raw map of piece from input file, probably won't need
	int				x[4];	//x,y coordinates of each of the four filled positions of
	int				y[4];	//the input, starting with 0,0 as the top-most  piece
	struct t_etris	*next;	//encountered from left to right, and all other coordinates
	struct t_etris	*prev;	//relative to that position.
}					t_etris;

/*
** ft_abort.c
*/

void				ft_abort(int err_code);

/*
** ft_read.c
*/

t_etris				*read_input_file(char *file, t_etris *tab);
void				ft_memcpycat(char **input_file, char *buff);
/*
** main.c
*/

int					main(int argc, char **argv);


#endif
