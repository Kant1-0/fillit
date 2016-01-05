/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:08:49 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/05 17:54:15 by qfremeau         ###   ########.fr       */
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
	t_pos	bloc1;
	t_pos	bloc2;
	t_pos	bloc3;
	t_pos	bloc4;
} 				t_tetri;

typedef struct	s_listing
{
	t_circlst	*list;
	size_t		x;
	size_t		y;
	size_t		bloc;
	size_t		tetri;
	size_t		i;
}				t_listing;

int		read_file(char const *file, char *buf);
BOOL	list_tetriminos(char *buf, int ret);
BOOL	check_curs(char buf, size_t cur_x);
BOOL	sav_bloc(size_t *bloc, size_t cur_x, size_t cur_y);
void	go_backline(size_t *cur_x, size_t *cur_y);
void	sav_tetri(size_t *tetri, size_t *i, size_t *cur_x, size_t *cur_y, 
	size_t *bloc);
void	init_vars(size_t *cur_x, size_t *cur_y, size_t *bloc, size_t *tetri, 
	size_t *i, t_circlst **list);


#endif
