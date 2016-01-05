/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:12:52 by qfremeau          #+#    #+#             */
/*   Updated: 2016/01/05 23:27:37 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char const *argv[])
{
	char	buf[BUFSIZE];
	int		ret;

	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		return (0);
	}
	ret = read_file(argv[1], buf);
	if (ret == FAIL)
		return (0);
	IFDEBUG(printf(KORG "\nRet is %d\n\n" RESET "%s\n", ret, buf);)
	list_tetriminos(buf, ret);
	
	return (0);
}
