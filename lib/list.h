/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:30:40 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/21 17:38:34 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <string.h>
# include <stdlib.h>
//# include <unistd.h>
# include "libft.h"

typedef	struct	s_circlst
{
	void				*content;
	size_t				content_size;
	struct s_circlst	*next;
	struct s_circlst	*prev;
}				t_circlst;

void			ft_circlst_addnext(t_circlst *elem, void const *content, 
	size_t content_size);
void			ft_circlst_addprev(t_circlst *elem, void const *content, 
	size_t content_size);
void			ft_circlst_addhead(t_circlst *racine, void const *content, 
	size_t content_size);
void			ft_circlst_addtail(t_circlst *racine, void const *content, 
	size_t content_size);
void			ft_circlst_delone(t_circlst *elem);
void			ft_circlst_delhead(t_circlst *racine);
void			ft_circlst_deltail(t_circlst *racine);
t_circlst		*ft_circlst_create(void);

#endif
