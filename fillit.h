/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:08:49 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/09 14:33:59 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "lib/libft.h"
#include "lib/list.h"
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

#define BOOL int
#define SUCCESS 1
#define FAIL -1
#define TRUE 1
#define FALSE 0
#define BUFSIZE 4095

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KORG  "\x1B[33m"
#define RESET "\033[0m"

typedef struct	s_position
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_tetriminos
{
	t_pos	block1;
	t_pos	block2;
	t_pos	block3;
	t_pos	block4;
} 				t_tetri;

typedef struct	s_listing
{
	t_circlst	*list;
	int			temp[4][1];
	size_t		cur_x;
	size_t		cur_y;
	size_t		ncase;
	size_t		ntetri;
	size_t		i;
}				t_list;

BOOL	read_file(char const *file, char *buf);
BOOL	list_tetriminos(char *buf, int ret);

#endif
