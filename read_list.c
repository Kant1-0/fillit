/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:19:21 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/23 17:27:43 by qfremeau         ###   ########.fr       */
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
	IFTRACE(printf(KVLT "__Succeed go_backline\n" RESET);)
}

// ************************************************************************** //
// Changes cursor position and saves its new position
void	move_cursor(size_t *cur_x, size_t *i)
{
	*cur_x = *cur_x + 1;
	*i = *i + 1;
}

// ************************************************************************** //
// Resets variables to read a new tetriminos
void	reset_vars(t_listing **lst)
{
	IFTRACE(printf(KORG "Entering reset_vars\n" RESET);)
	(*lst)->i = (*lst)->i + 1;
	(*lst)->y = 1;
	(*lst)->x = 1;
	(*lst)->bloc = 0;
	IFTRACE(printf(KGRN "__Succeed reset_vars\n" RESET);)
}
