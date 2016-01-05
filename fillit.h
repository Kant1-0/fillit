/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:08:49 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/05 23:35:36 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// Includes
#include "lib/libft.h"
#include "lib/list.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// ************************************************************************** //
// Macro for True or False
#define BOOL int
#define SUCCESS 1
#define FAIL -1
#define TRUE 1
#define FALSE 0
// Macro for read function
#define BUFSIZE 4095
// Macro for Printf Color
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KORG  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define RESET "\033[0m"

// ************************************************************************** //
// Debug Conditionnal Macro
#define _DEBUG

#ifdef _DEBUG
#define IFDEBUG(x) x
#else
#define IFDEBUG(x)
#endif

// ************************************************************************** //
// Typedef for Tetris Case Coordinates
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

// Typedef for list_tetrimonis Function
typedef struct	s_listing
{
	t_circlst	*list;
	size_t		x;
	size_t		y;
	size_t		bloc;
	size_t		tetri;
	size_t		i;
}				t_listing;

// ************************************************************************** //
// Preproccesors
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
