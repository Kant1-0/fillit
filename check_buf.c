/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:44:40 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/23 17:37:05 by qfremeau         ###   ########.fr       */
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
		IFERROR(ft_putstr(RESET "error\n");)
		IFDEBUG(printf(KRED "Check_curs found a wrong character" RESET);)
		IFTRACE(printf("  %d|%c|\n", buf, buf);)
		IFEXITF(return (FALSE);)
	}
	if (buf != '#' && buf != '.' && buf != '\n')
	{
		IFERROR(ft_putstr(RESET "error\n");)
		IFDEBUG(printf(KRED "Check_curs end of line was wrong" RESET);)
		IFTRACE(printf("  %d|%c|\n", buf, buf);)
		IFEXITF(return (FALSE);)
	}
	IFTRACE(printf(KGRN "__Succeed check_curs\n" RESET);)
	return (TRUE);
}

// ************************************************************************** //
// Checks if tetriminos made is valid
BOOL	check_minos(t_listing *lst)
{
	IFTRACE(printf(KORG "Entering check_minos\n" RESET);)
	if (lst->bloc != 4)
	{
		IFDEBUG(printf(KRED "Check_minos found incorrect number of blocs = %zu\n" RESET, lst->bloc);)
		IFEXITF(return (FALSE);)
	}
	#ifdef _TRACE
		printf("\n");
		printf("B1.X = %d\n", B1X);
		printf("B1.Y = %d\n", B1Y);
		printf("B2.X = %d\n", B2X);
		printf("B2.Y = %d\n", B2Y);
		printf("B3.X = %d\n", B3X);
		printf("B3.Y = %d\n", B3Y);
		printf("B4.X = %d\n", B4X);
		printf("B4.Y = %d\n", B4Y);
		printf("\n");
	#endif
	if (!(((B1XP == B2X) && (B1Y == B2Y)) || ((B1X == B2X) && (B1YP == B2Y))
		|| ((B1X == B3X) && (B1YP == B3Y)) || ((B1X == B4X) && (B1YP == B4Y))))
	{
		IFDEBUG(printf(KRED "Invalid tetriminos shape, stopped at block 1 checking\n" RESET);)
		IFEXITF(return (FALSE);)
	}
	if (!(((B2XP == B3X) && (B2Y == B3Y)) || ((B2X == B3X) && (B2YP == B3Y))
		|| ((B2X == B4X) && (B2YP == B4Y)) || ((B2XM == B1X) && (B2Y == B1Y))))
	{
		IFDEBUG(printf(KRED "Invalid tetriminos shape, stopped at block 2 checking\n" RESET);)
		IFEXITF(return (FALSE);)
	}
	if (!(((B3XP == B4X) && (B3Y == B4Y)) || ((B3X == B4X) && (B3YP == B4Y))
		|| ((B3XM == B2X) && (B3Y == B2Y))))
	{
		IFDEBUG(printf(KRED "Invalid tetriminos shape, stopped at block 3 checking\n" RESET);)
		IFEXITF(return (FALSE);)
	}
	if (!(((B4XM == B3X) && (B4Y == B3Y)) || ((B4X == B3X) && (B4YM == B3Y))
		|| ((B4X == B1X) && (B4YM == B1Y)) || ((B4X == B2X) && (B4YM == B2Y))))
	{
		IFDEBUG(printf(KRED "Invalid tetriminos shape, stopped at block 4 checking\n" RESET);)
		IFEXITF(return (FALSE);)
	}
	IFTRACE(printf(KGRN "__Succeed check_minos\n" RESET);)
	return (TRUE);
}
