/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:52:55 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/05 23:35:19 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//#define _DEBUG

int		read_file(char const *file, char *buf)
{
	IFDEBUG(printf(KORG "Entering read_file\n" RESET);)
	int		fd;
	int		ret;
	int		ptr_ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(KRED "Error: cannot open file\n" RESET, 2);
		return (FAIL);
	}
	while ((ret = read(fd, buf, BUFSIZE)) != 0)
	{
		ptr_ret = ret;
		buf[ret] = '\0';
	}
	close(fd);
	printf(KGRN "__Succeed read_file\n" RESET);
	return (ptr_ret);
}

BOOL	list_tetriminos(char *buf, int ret)
{
	IFDEBUG(printf(KORG "Entering list_tetriminos\n" RESET);)
	t_listing		lst;
	IFDEBUG(printf(KGRN "__Succeed t_listing\n" RESET);)

	init_vars(&lst.x, &lst.y, &lst.bloc, &lst.tetri, &lst.i, &lst.list);
	IFDEBUG(printf(KORG "Begin while(lst.i <= ret)\n" RESET);)
	while (lst.i <= (size_t)ret)
	{
		while (lst.y < 5)
		{
			if (!check_curs(buf[lst.i], lst.x))
			{
				IFDEBUG(printf(KRED "__Failed list_tetriminos\n" RESET);)
				return (FAIL);
			}
			if (buf[lst.i] == '#')
			{
				if (!sav_bloc(&lst.bloc, lst.x, lst.y))
				{
					IFDEBUG(printf(KRED "__Failed list_tetriminos\n" RESET);)
					return (FAIL);
				}
				else
				{
					IFDEBUG(printf(KBLU "'#' ws registerd at x:%lu & y:%lu - i was %lu|%c|  &  bloc was %lu\n" RESET, lst.x, lst.y, lst.i, buf[lst.i], lst.bloc);)
				}
			}
			else if (buf[lst.i] == '\n' && lst.x == 5)
				go_backline(&lst.x, &lst.y);
			lst.x++;
			lst.i++;
		}
		if (lst.y == 5 && (buf[lst.i] == '\n' || buf[lst.i] == 0))
			sav_tetri(&lst.tetri, &lst.i, &lst.x, &lst.y, &lst.bloc);
		else
		{
			IFDEBUG(printf(KRED "__Failed list_tetriminos\n" RESET);)
			return (FAIL);
		}
	}
	printf(KGRN "__Succeed list_tetriminos\n" RESET);
	return (SUCCESS);
}
