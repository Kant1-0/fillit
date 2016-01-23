/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:52:55 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/23 17:17:09 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// ************************************************************************** //
// Reads and saves file into a buffer string 
int		read_file(char const *file, char *buf)
{
	IFTRACE(printf(KORG "Entering read_file\n" RESET);)
	int		fd;
	int		ret;
	int		ptr_ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		IFERROR(ft_putstr(RESET "error\n");)
		IFDEBUG(printf(KRED "Cannot open file\n" RESET);)
		return (ERROR);
	}
	while ((ret = read(fd, buf, BUFSIZE)) != 0)
	{
		ptr_ret = ret;
		buf[ret] = '\0';
	}
	close(fd);
	IFDEBUG(printf(KGRN "__Succeed read_file\n" RESET);)
	return (ptr_ret);
}

// ************************************************************************** //
// Analyzes buffer to save and check coordinates into a circular list
BOOL	list_tetriminos(char *buf, int ret)
{
	IFTRACE(printf(KORG "Entering list_tetriminos\n" RESET);)
	t_listing		lst;
	IFTRACE(printf(KGRN "__Succeed t_listing\n" RESET);)

	init_vars(&lst);
	IFTRACE(printf(KORG "Begin while(lst.i <= ret)\n" RESET);)
	while (lst.i <= (size_t)ret)
	{
		while (lst.y < 5)
		{
			if (check_curs(buf[lst.i], lst.x) != TRUE)
			{
				IFDEBUG(printf(KRED "__Failed list_tetriminos\n" RESET);)
				IFEXITF(return (FAIL);)
			}
			if (buf[lst.i] == '#')
			{
				sav_bloc(&lst);
				IFTRACE(printf(KBLU "'#' ws registerd at x:%lu & y:%lu - i was %lu|%c|  &  bloc was %lu\n" RESET, lst.x, lst.y, lst.i, buf[lst.i], lst.bloc);)
			}
			else if (buf[lst.i] == '\n' && lst.x == 5)
				go_backline(&lst.x, &lst.y);
			move_cursor(&lst.x, &lst.i);
		}
		if (lst.y == 5 && (buf[lst.i] == '\n' || buf[lst.i] == 0))
		{
			if (sav_minos(&lst) != SUCCESS)
			{
				IFDEBUG(printf(KRED "__Failed list_tetriminos\n" RESET);)
				IFEXITF(return (FAIL);)
			}
		}
		else
		{
			IFERROR(ft_putstr(RESET "error\n");)
			IFDEBUG(printf(KRED "List_tetriminos failed with a wrong character at tetriminos #%zu end" RESET, lst.tetri);)
			IFTRACE(printf("  %d|%c|\n", buf[lst.i], buf[lst.i]);)
			IFEXITF(return (ERROR);)
		}
	}
	IFDEBUG(printf(KGRN "__Succeed list_tetriminos\n" RESET);)
	return (SUCCESS);
}
