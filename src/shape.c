/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:09:49 by qfremeau          #+#    #+#             */
/*   Updated: 2016/06/23 18:23:45 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Gives the max width of the tetriminos checking by columns
*/

int		get_width(char *s)
{
	int i;
	int width;
	int line_void;

	i = 0;
	width = 0;
	line_void = 0;
	while (i < 4)
	{
		if (s[i] == '#' || s[i + 5] == '#' || s[i + 10] == '#' ||\
				s[i + 15] == '#')
		{
			width++;
			if (line_void > 0)
				return (0);
		}
		else if (width > 0)
			line_void++;
		i++;
	}
	return (width);
}

/*
** Gives the max height of the tetriminos checking by lines
*/

int		get_height(char *s)
{
	int i;
	int height;
	int line_void;

	i = 0;
	height = 0;
	line_void = 0;
	while (i < 19)
	{
		if (s[i] == '#' || s[i + 1] == '#' || s[i + 2] == '#' ||\
				s[i + 3] == '#')
		{
			height++;
			if (line_void > 0)
				return (0);
		}
		else if (height > 0)
			line_void++;
		i = i + 5;
	}
	return (height);
}

/*
** Check the void range between the second # and the third # (spec mid-shape)
** Return 0 if range too long and 1 if ok
*/

int		check_void_int(char *s)
{
	int i;
	int h;
	int bug;

	bug = 0;
	i = 0;
	h = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			h++;
		if (h == 2 && s[i] == '#')
		{
			while (s[i + 1 + bug] != '#' && s[i + bug] != '\0')
				bug++;
			if (bug > 5)
				return (0);
		}
		i++;
	}
	return (1);
}

/*
** Check if all four # are next to an other # (right, left, up, bottom)
** Return 0 if false and 1 if true
*/

int		is_alone(char *s)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#' || s[i - 1] == '#' || s[i + 5] == '#' ||\
					s[i - 5] == '#')
				ok++;
			if (ok == 4)
				return (1);
		}
		i++;
	}
	return (0);
}
