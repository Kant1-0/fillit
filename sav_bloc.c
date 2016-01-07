/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sav_bloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:07:10 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/07 12:23:34 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// ************************************************************************** //
// Saves coordinates into different blocs 1 to 4 according to sav_bloc function
void	sav_bloc1(t_listing **lst)
{
	IFTRACE(printf(KORG "Entering sav_bloc1\n" RESET);)
	(*lst)->minos.bloc1.x = (*lst)->x;
	(*lst)->minos.bloc1.y = (*lst)->y;
	IFTRACE(printf(KGRN "__Succeed sav_bloc1\n" RESET);)
}

// Bloc 2
void	sav_bloc2(t_listing **lst)
{
	IFTRACE(printf(KORG "Entering sav_bloc2\n" RESET);)
	(*lst)->minos.bloc2.x = (*lst)->x;
	(*lst)->minos.bloc2.y = (*lst)->y;
	IFTRACE(printf(KGRN "__Succeed sav_bloc2\n" RESET);)
}

// Bloc 3
void	sav_bloc3(t_listing **lst)
{
	IFTRACE(printf(KORG "Entering sav_bloc3\n" RESET);)
	(*lst)->minos.bloc3.x = (*lst)->x;
	(*lst)->minos.bloc3.y = (*lst)->y;
	IFTRACE(printf(KGRN "__Succeed sav_bloc3\n" RESET);)
}

// Bloc 4
void	sav_bloc4(t_listing **lst)
{
	IFTRACE(printf(KORG "Entering sav_bloc4\n" RESET);)
	(*lst)->minos.bloc4.x = (*lst)->x;
	(*lst)->minos.bloc4.y = (*lst)->y;
	IFTRACE(printf(KGRN "__Succeed sav_bloc4\n" RESET);)
}
