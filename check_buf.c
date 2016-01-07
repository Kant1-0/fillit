/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:44:40 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/07 11:11:51 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// ************************************************************************** //
// Checks if cursor is reading right characters
BOOL	check_curs(char buf, size_t cur_x)
{
	IFTRACE(printf(KORG "Entering check_curs\n" RESET);)
	if ((buf != '#'|| buf != '.' || buf != '\n') && 
		((buf == '\n' && cur_x != 5) || 
		(buf == '#' && cur_x == 5) || 
		(buf == '.' && cur_x == 5)))
	{
		IFERROR(ft_putstr(RESET "error");)
		IFDEBUG(printf(KRED ": check_curs found a wrong character" RESET);)
		IFTRACE(printf("  %d|%c|", buf, buf);)
		IFERROR(printf("\n");)
		return (FALSE);
	}
	if (buf != '#' && buf != '.' && buf != '\n')
	{
		IFERROR(ft_putstr(RESET "error");)
		IFDEBUG(printf(KRED ": check_curs end of line was wrong" RESET);)
		IFTRACE(printf("  %d|%c|", buf, buf);)
		IFERROR(printf("\n");)
		return (FALSE);
	}
	IFTRACE(printf(KGRN "__Succeed check_curs\n" RESET);)
	return (TRUE);
}

// ************************************************************************** //
// Checks if tetriminos made is valid
BOOL	check_minos(size_t cur_x, size_t cur_y, size_t bloc)
{
	IFTRACE(printf(KORG "Entering check_minos\n" RESET);)
	cur_x = cur_x + 1;
	cur_y = cur_y + 1;
	cur_x = cur_x - 1;
	cur_y = cur_y - 1;
	if (bloc != 4)
	{
		IFERROR(ft_putstr(RESET "error");)
		IFDEBUG(printf(KRED ": check_minos found not enough blocs = %zu" RESET, bloc);)
		IFERROR(printf("\n");)
		return (FALSE);
	}
	IFTRACE(printf(KGRN "__Succeed check_minos\n" RESET);)
	return (TRUE);
}