/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:52:55 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/22 13:43:15 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_file(char const *file, char *buf)
{
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
	return (ptr_ret);
}

BOOL	list_tetriminos(char *buf, int ret)
{
	t_listing		lst;
	
	init_vars(&lst.x, &lst.y, &lst.bloc, &lst.tetri, &lst.i, &lst.list);
	while (lst.i <= (size_t)ret)
	{
		while (lst.y < 5)
		{
			if (!check_curs(buf[lst.i], lst.x))
				return (FAIL);
			if (buf[lst.i] == '#')
			{
				if (!sav_bloc(&lst.bloc, &lst.tmp, lst.x, lst.y))
					return (FAIL);
			}
			else if (buf[lst.i] == '\n' && lst.x == 5)
				go_backline(&lst.x, &lst.y);
			lst.x++;
			lst.i++;
		}
		if (lst.y == 5 && (buf[lst.i] == '\n' || buf[lst.i] == 0))
			sav_tetri(&lst.tetri, &lst.i, &lst.x, &lst.y, &lst.bloc);
		else
			return (FAIL);
	}
	return (SUCCESS);
}
