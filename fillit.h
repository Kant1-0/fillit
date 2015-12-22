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

BOOL	read_file(char const *file, char *buf);
BOOL	list_tetriminos(char *buf, int ret);

#endif
