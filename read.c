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

BOOL	list_tetriminos(char *buf, int ret)
{
	t_circlst	*list;
	int			temp[4][1];
	size_t		cur_x;
	size_t		cur_y;
	size_t		ncase;
	size_t		ntetri;
	size_t		i;
	
	list = ft_circlst_create();
	cur_x = 1;
	cur_y = 1;
	ncase = 0;
	ntetri = 0;
	i = 0;
	while (i <= (size_t)ret)
	{
		printf(KRED "\nBack at cur_y < 5   x:%lu & y:%lu - i was %lu|%c|\n"KORG"Ret is %d\n\n" RESET, cur_x, cur_y, i, buf[i], ret);
		while (cur_y < 5)
		{
			if (!check_curs(buf[i], cur_x))
			{
				printf(KRED "Failed at x:%lu & y:%lu - i was %lu|%c|\n" RESET, cur_x, cur_y, i, buf[i]);
				return (FAIL);
			}
			if (buf[i] == '#')
			{
				temp[ncase][0] = 
				ncase++;
				printf(KGRN "'#' ws registerd at x:%lu & y:%lu - i was %lu|%c|  &  ncase was %lu\n" RESET, cur_x, cur_y, i, buf[i], ncase);
				if (ncase > 4)
				{
					printf(KRED "Too many blocks in tetriminos, ncase : %lu\n"RESET, ncase);
					return (FAIL);
				}
			}
			else if (buf[i] == '\n' && cur_x == 5)
			{
				printf(KORG "Line at x:%lu & y:%lu was checked - i was %lu|\\n|\n\n" RESET, cur_x, cur_y, i);
				cur_x = 0;
				cur_y++;
			}
			else
				printf("Curs at x:%lu & y:%lu was checked - i was %lu|%c|\n", cur_x, cur_y, i, buf[i]);
			cur_x++;
			i++;
		}
		if (cur_y == 5 && (buf[i] == '\n' || buf[i] == 0))
		{
			ntetri++;
			printf(KGRN "\nTetri number: %lu succesfully checked\n" RESET, ntetri);
			i++;
			cur_y = 1;
			cur_x = 1;
			ncase = 0;
			printf(KORG "Curs is now x:%lu & y:%lu   with i = %lu\n\n" RESET, cur_x, cur_y, i);
		}
		else
		{
			printf(KRED "Failed at '\\n' pos was x:%lu & y:%lu - i was %lu|%c|\n" RESET, cur_x, cur_y, i, buf[i]);
			return (FAIL);
		}
	}
	printf(KRED "End of WhileLoop at x:%lu & y:%lu - i was %lu|%c|\n"KORG"Ret is %d\n\n"RESET, cur_x, cur_y, i, buf[i], ret);
	return (SUCCESS);
}