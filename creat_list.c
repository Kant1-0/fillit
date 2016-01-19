/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:19:21 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/07 12:49:22 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// ************************************************************************** //
// Initiates the variables for list_tetriminos function
void	init_vars(t_listing *lst)
{
	IFTRACE(printf(KORG "Entering init_vars\n" RESET);)
	lst->x = 1;
	lst->y = 1;
	lst->bloc = 0;
	lst->tetri = 0;
	lst->i = 0;
	lst->c_list = ft_circlst_create();
	lst->minos.nu = 0;
	IFTRACE(printf(KGRN "__Succeed init_vars\n" RESET);)
}

// ************************************************************************** //
// Goes back to line if check_curs at endline was true & reinitializes cursor
void	go_backline(size_t *cur_x, size_t *cur_y)
{
	IFTRACE(printf(KORG "Entering go_backline\n" RESET);)
	*cur_x = 0;
	*cur_y = *cur_y + 1;
	IFTRACE(printf(KGRN "__Succeed go_backline\n" RESET);)
}

// ************************************************************************** //
// Saves bloc coordinates into temp list & check if bloc number is still < 5
BOOL	sav_bloc(t_listing *lst)
{
	IFTRACE(printf(KORG "Entering sav_bloc\n" RESET);)
	lst->bloc = lst->bloc + 1;
	if (lst->bloc == (size_t)1)
		sav_bloc1(&lst);
	else if (lst->bloc == (size_t)2)
		sav_bloc2(&lst);
	else if (lst->bloc == (size_t)3)
		sav_bloc3(&lst);
	else if (lst->bloc == (size_t)4)
		sav_bloc4(&lst);
	else
	{
		IFERROR(ft_putstr(RESET "error");)
		IFDEBUG(printf(KRED ": sav_bloc found too many blocs" RESET);)
		IFERROR(printf("\n");)
		return (FAIL);
	}
	IFTRACE(printf(KGRN "__Succeed sav_bloc\n" RESET);)
	return (SUCCESS);
}

// ************************************************************************** //
// Saves the whole tetriminos into t_list in a new elem
BOOL	sav_minos(t_listing *lst)
{
	IFTRACE(printf(KORG "Entering sav_minos\n" RESET);)
	lst->tetri = lst->tetri + 1;
	//ft_circlst_addnext(lst->c_list, (void *)lst->minos, sizeof(lst->minos));
	// Need to find how to include a struct into a linked list
	if (check_minos(lst->x, lst->y, lst->bloc) == FALSE)
	{
		IFDEBUG(printf(KRED "__Failed sav_minos\n" RESET);)
		return (FAIL);
	}
	IFTRACE(printf(KBLU "Tetris number %zu was successfully saved\n\n", lst->tetri);)
	lst->i = lst->i + 1;
	lst->y = 1;
	lst->x = 1;
	lst->bloc = 0;
	IFTRACE(printf(KGRN "__Succeed sav_minos\n" RESET);)
	return (SUCCESS);
}
