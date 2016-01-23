/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sav_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:57:32 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/23 17:51:22 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#ifdef _TRACE
// ************************************************************************** //
// Static function that tests if minos copy worked
static void test_copy(t_tetri *new_minos)
{
	printf("\n");
	printf("new B1.X = %d\n", new_minos->bloc1.x);
	printf("new B1.Y = %d\n", new_minos->bloc1.y);
	printf("new B2.X = %d\n", new_minos->bloc2.x);
	printf("new B2.Y = %d\n", new_minos->bloc2.y);
	printf("new B3.X = %d\n", new_minos->bloc3.x);
	printf("new B3.Y = %d\n", new_minos->bloc3.y);
	printf("new B4.X = %d\n", new_minos->bloc4.x);
	printf("new B4.Y = %d\n", new_minos->bloc4.y);
	printf("\n");
}

#endif
// ************************************************************************** //
// Deep copies the minos struct into a new one
static void		copy_minos(t_tetri *minos, t_tetri *new_minos)
{
	IFTRACE(printf(KORG "Entering copy_minos\n" RESET);)
	new_minos->nu = minos->nu;
	new_minos->bloc1.x = minos->bloc1.x;
	new_minos->bloc1.y = minos->bloc1.y;
	new_minos->bloc2.x = minos->bloc2.x;
	new_minos->bloc2.y = minos->bloc2.y;
	new_minos->bloc3.x = minos->bloc3.x;
	new_minos->bloc3.y = minos->bloc3.y;
	new_minos->bloc4.x = minos->bloc4.x;
	new_minos->bloc4.y = minos->bloc4.y;
	IFTRACE(printf(KGRN "__Succeed copy_minos\n" RESET);)
}

// ************************************************************************** //
// Saves the whole tetriminos into t_list in a new elem
BOOL			sav_minos(t_listing *lst)
{
	t_tetri		new_minos;

	IFTRACE(printf(KORG "Entering sav_minos #%zu\n" RESET, lst->tetri + 1);)
	lst->tetri = lst->tetri + 1;
	lst->minos.nu = (int)lst->tetri + 64;
	if (check_minos(lst) != TRUE)
	{
		IFERROR(ft_putstr(RESET "error\n");)
		IFDEBUG(printf(KRED "__Failed sav_minos\n" RESET);)
		IFEXITF(return (ERROR);)
	}
	copy_minos(&lst->minos, &new_minos);
	IFTRACE(test_copy(&new_minos);)
	ft_circlst_addnext(lst->c_list, &new_minos, sizeof(new_minos));
	IFTRACE(printf(KBLU "Tetris number %zu was successfully saved\n", lst->tetri);)
	reset_vars(&lst);
	IFTRACE(printf(KVLT "__Succeed sav_minos #%d\n\n" RESET, lst->minos.nu - 64);)
	return (SUCCESS);
}
