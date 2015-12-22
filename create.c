/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:19:21 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/22 12:36:34 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

BOOL	sav_bloc(size_t *bloc, int *tmp[][], size_t cur_x, size_t cur_y)
{
	tmp[bloc][0] = cur_x;
	tmp[bloc][1] = cur_y;
	bloc++;
	if (bloc > 4)
		return (FAIL);
	return (SUCCESS);
}

void	go_backline(size_t *cur_x, size_t *cur_y)
{
	cur_x = 0;
	cur_y++;
}

void	sav_tetri(size_t *tetri, size_t *i, size_t *cur_x, 
	size_t *cur_y, size_t *bloc)
{
	tetri++;
	i++;
	cur_y = 1;
	cur_x = 1;
	bloc = 0;
}

void	init_vars(size_t *cur_x, size_t *cur_y, size_t *bloc, 
	size_t *tetri, size_t *i, t_circlst **list)
{
	cur_x = 1;
	cur_y = 1;
	bloc = 0;
	tetri = 0;
	i = 0;
	list = ft_circlst_create();
}

BOOL	list_tetriminos(char *buf, int ret)
{
	t_list		lst;
	
	init_vars(lst.x, lst.y, lst.bloc, lst.tetri, lst.i, lst.list);
	while (i <= (size_t)ret)
	{
		while (lst.y < 5)
		{
			if (!check_curs(buf[i], lst.x))
				return (FAIL);
			if (buf[i] == '#')
				!sav_bloc(lst.bloc, list.tmp, lst.x, lst.y) ? return (FAIL);
			else if (buf[i] == '\n' && cur_x == 5)
				go_backline(lst.x, lst.y);
			lst.x++;
			lst.i++;
		}
		if (cur_y == 5 && (buf[i] == '\n' || buf[i] == 0))
			sav_tetri(lst.tetri, lst.i, lst.x, lst.y, lst.bloc)
		else
			return (FAIL);
	}
	return (SUCCESS);
}