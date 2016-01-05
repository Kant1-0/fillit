/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:19:21 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/05 18:12:30 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

BOOL	check_curs(char buf, size_t cur_x)
{
	printf(KORG "Entering check_curs\n" RESET);
	if ((buf != '#'|| buf != '.' || buf != '\n') && 
		((buf == '\n' && cur_x != 5) || 
		(buf == '#' && cur_x == 5) || 
		(buf == '.' && cur_x == 5)))
	{
		printf(KRED "__Failed check_curs\n" RESET);
		return (FALSE);
	}
	if (buf != '#' && buf != '.' && buf != '\n')
	{
		printf(KRED "__Failed check_curs end of line\n" RESET);
		printf(KRED "End of line was: %d|%c|\n" RESET, buf, buf);
		return (FALSE);
	}
	printf(KGRN "__Succeed check_curs\n" RESET);
	return (TRUE);
}

BOOL	sav_bloc(size_t *bloc, size_t cur_x, size_t cur_y)
{
	int test;

	printf(KORG "Entering sav_bloc\n" RESET);
	test = cur_x + cur_y;
	*bloc = *bloc + 1;
	if (*bloc > (size_t)4)
	{
		printf(KRED "__Failed sav_bloc\n" RESET);
		return (FAIL);
	}
	printf(KGRN "__Succeed sav_bloc\n" RESET);
	return (SUCCESS);
}

void	go_backline(size_t *cur_x, size_t *cur_y)
{
	printf(KORG "Entering go_backline\n" RESET);
	*cur_x = 0;
	*cur_y = *cur_y + 1;
	printf(KGRN "__Succeed go_backline\n" RESET);
}

void	sav_tetri(size_t *tetri, size_t *i, size_t *cur_x, size_t *cur_y, 
	size_t *bloc)
{
	printf(KORG "Entering sav_tetri\n" RESET);
	*tetri = *tetri + 1;
	*i = *i + 1;
	*cur_y = 1;
	*cur_x = 1;
	*bloc = 0;
	printf(KGRN "__Succeed sav_tetri\n" RESET);
}

void	init_vars(size_t *cur_x, size_t *cur_y, size_t *bloc, size_t *tetri, 
	size_t *i, t_circlst **list)
{
	printf(KORG "Entering init_vars\n" RESET);
	*cur_x = 1;
	*cur_y = 1;
	*bloc = 0;
	*tetri = 0;
	*i = 0;
	*list = ft_circlst_create();
	printf(KGRN "__Succeed init_vars\n" RESET);
}