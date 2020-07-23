/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:31:31 by geargenc          #+#    #+#             */
/*   Updated: 2020/04/22 15:19:57 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

int				ft_exp_error(t_txtlist *list, t_txtlist *error)
{
	t_txtlist	*tmp;

	while (list != error)
	{
		tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
	}
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	return (-1);
}

int				ft_exp(t_txtlist *list)
{
	t_txtlist	*tmp;

	tmp = list;
	while (tmp)
	{
		if (g_exptab[tmp->token](tmp))
			return (ft_exp_error(list, tmp));
		tmp = tmp->next;
	}
	return (0);
}
