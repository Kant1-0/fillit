/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:52:55 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/07 11:12:15 by qfremeau         ###   ########.fr       */
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
		IFERROR(ft_putstr(RESET "error");)
		IFDEBUG(printf(KRED "cannot open file" RESET);)
		IFERROR(printf("\n");)
		return (FAIL);
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
			if (check_curs(buf[lst.i], lst.x) == FALSE)
			{
				IFDEBUG(printf(KRED "__Failed list_tetriminos\n" RESET);)
				return (FAIL);
			}
			if (buf[lst.i] == '#')
			{
				if (sav_bloc(&lst) == FAIL)
				{
					IFDEBUG(printf(KRED "__Failed list_tetriminos\n" RESET);)
					return (FAIL);
				}
				else
				{
					IFTRACE(printf(KBLU "'#' ws registerd at x:%lu & y:%lu - i was %lu|%c|  &  bloc was %lu\n" RESET, lst.x, lst.y, lst.i, buf[lst.i], lst.bloc);)
				}
			}
			else if (buf[lst.i] == '\n' && lst.x == 5)
				go_backline(&lst.x, &lst.y);
			lst.x++;
			lst.i++;
		}
		if (lst.y == 5 && (buf[lst.i] == '\n' || buf[lst.i] == 0))
		{
			if (sav_minos(&lst) == FAIL)
			{
				IFDEBUG(printf(KRED "__Failed list_tetriminos\n" RESET);)
				return (FAIL);
			}
		}
		else
		{
			IFERROR(ft_putstr(RESET "error");)
			IFDEBUG(printf(KRED ": list_tetriminos failed with a wrong character at tetriminos #%zu end" RESET, lst.tetri);)
			IFTRACE(printf("  %d|%c|", buf[lst.i], buf[lst.i]);)
			IFERROR(printf("\n");)
			return (FAIL);
		}
	}
	IFDEBUG(printf(KGRN "__Succeed list_tetriminos\n" RESET);)
	return (SUCCESS);
}
