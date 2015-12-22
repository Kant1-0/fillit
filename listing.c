/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:19:21 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/22 13:43:02 by qfremeau         ###   ########.fr       */
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

BOOL	sav_bloc(size_t *bloc, int **tmp, size_t cur_x, size_t cur_y)
{
	**tmp = cur_x + cur_y;
	*bloc = *bloc + 1;
	if (*bloc > (size_t)4)
		return (FAIL);
	return (SUCCESS);
}

void	go_backline(size_t *cur_x, size_t *cur_y)
{
	*cur_x = 0;
	*cur_y = *cur_y + 1;
}

void	sav_tetri(size_t *tetri, size_t *i, size_t *cur_x, size_t *cur_y, 
	size_t *bloc)
{
	*tetri = *tetri + 1;
	*i = *i + 1;
	*cur_y = 1;
	*cur_x = 1;
	*bloc = 0;
}

void	init_vars(size_t *cur_x, size_t *cur_y, size_t *bloc, size_t *tetri, 
	size_t *i, t_circlst **list)
{
	*cur_x = 1;
	*cur_y = 1;
	*bloc = 0;
	*tetri = 0;
	*i = 0;
	*list = ft_circlst_create();
}