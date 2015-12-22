/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 12:52:55 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/11 13:16:31 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

BOOL	read_file(char const *file, char *buf)
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

BOOL	check_curs(char buf, size_t cur_x)
{
	if ((buf != '#'|| buf != '.' || buf != '\n') && 
		((buf == '\n' && cur_x != 5) || 
		(buf == '#' && cur_x == 5) || 
		(buf == '.' && cur_x == 5)))
		return (FALSE);
	if (buf != '#'&& buf != '.' && buf != '\n')
		return (FALSE);
	return (TRUE);
}

BOOL	register_block(size_t *ncase, int temp[][], size_t cur_x, size_t cur_y)
{
	temp[ncase][0] = cur_x;
	temp[ncase][1] = cur_y;
	ncase++;
	if (ncase > 4)
		return (FAIL);
	return (SUCCESS);
}

BOOL	list_tetriminos(char *buf, int ret)
{
	t_list		list;
	
	list.list = ft_circlst_create();
	list.cur_x = 1;
	list.cur_y = 1;
	list.ncase = 0;
	list.ntetri = 0;
	list.i = 0;
	while (i <= (size_t)ret)
	{
		while (list.cur_y < 5)
		{
			if (!check_curs(buf[i], list.cur_x))
				return (FAIL);
			if (buf[i] == '#')
				!register_block(list.ncase, list.temp, list.cur_x, list.cur_y) ? 
			else if (buf[i] == '\n' && cur_x == 5)
			{
				cur_x = 0;
				cur_y++;
			}
			cur_x++;
			i++;
		}
		if (cur_y == 5 && (buf[i] == '\n' || buf[i] == 0))
		{
			ntetri++;
			i++;
			cur_y = 1;
			cur_x = 1;
			ncase = 0;
		}
		else
			return (FAIL);
	}
	return (SUCCESS);
}