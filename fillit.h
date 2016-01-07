/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:08:49 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/07 11:18:07 by qfremeau         ###   ########.fr       */
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
// Macro for Printf Colors
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KORG  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define RESET "\033[0m"

// ************************************************************************** //
// Debug Conditionnal Macro
// Uncomment #define _MACRO to choose how to debug
#define _DEBUG

#ifdef _DEBUG
#define IFDEBUG(x) x
#else
#define IFDEBUG(x)
#endif

#define _TRACE

#ifdef _TRACE
#define IFTRACE(x) x
#else
#define IFTRACE(x)
#endif

#define _ERROR

#ifdef _ERROR
#define IFERROR(x) x
#else
#define IFERROR(x)
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
	size_t	nu;
	t_pos	bloc1;
	t_pos	bloc2;
	t_pos	bloc3;
	t_pos	bloc4;
} 				t_tetri;

// Typedef for list_tetrimonis Function
typedef struct	s_listing
{
	t_circlst	*c_list;
	t_tetri		minos;
	size_t		x;
	size_t		y;
	size_t		bloc;
	size_t		tetri;
	size_t		i;
}				t_listing;

// ************************************************************************** //
// Preproccesors read_file.c
int		read_file(char const *file, char *buf);
BOOL	list_tetriminos(char *buf, int ret);

// Preproccesors creat_list.c
void	init_vars(t_listing *lst);
void	go_backline(size_t *cur_x, size_t *cur_y);
BOOL	sav_bloc(t_listing *lst);
BOOL	sav_minos(t_listing *lst);

// Preproccesors check_buf.c
BOOL	check_minos(size_t cur_x, size_t cur_y, size_t bloc);
BOOL	check_curs(char buf, size_t cur_x);

// Preproccesors sav_bloc.c
void	sav_bloc1(t_listing **lst);
void	sav_bloc2(t_listing **lst);
void	sav_bloc3(t_listing **lst);
void	sav_bloc4(t_listing **lst);

#endif
