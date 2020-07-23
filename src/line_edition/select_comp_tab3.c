/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_comp_tab3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:23:32 by frameton          #+#    #+#             */
/*   Updated: 2020/02/16 02:16:50 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

void	up_touch2(t_comp **cmp, t_comp *bcmp, int c)
{
	while ((*cmp)->col != c)
	{
		*cmp = (*cmp)->prev;
		if (!*cmp && ((*cmp) = bcmp))
			while ((*cmp)->next)
				*cmp = (*cmp)->next;
	}
	(*cmp)->sel = 1;
}

void	up_touch(t_comp *cmp, t_comp *bcmp, int *j, int i)
{
	int		c;

	while (!cmp->sel)
		cmp = cmp->next;
	cmp->sel = 0;
	c = cmp->col;
	if (cmp->prev)
		cmp = cmp->prev;
	else
		while (cmp->next)
			cmp = cmp->next;
	up_touch2(&cmp, bcmp, c);
	c = 0;
	while (c < *j)
	{
		tputs(tgetstr("up", NULL), 1, ft_ptchar);
		tputs(tgetstr("dl", NULL), 1, ft_ptchar);
		++c;
	}
	del_move(4);
	*j = 0;
	print_comp_tab(bcmp, 0, i, &*j);
}
