/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:37:24 by ymarcill          #+#    #+#             */
/*   Updated: 2020/03/11 18:45:55 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projectinclude.h"

void	save_fd(void)
{
	g_jobcontrol.f = 1;
	g_jobcontrol.stdi = dup(0);
	g_jobcontrol.stdo = dup(1);
	g_jobcontrol.stde = dup(2);
}

void	reset_fd(void)
{
	g_jobcontrol.f = 0;
	dup2(g_jobcontrol.stdi, 0);
	close(g_jobcontrol.stdi);
	dup2(g_jobcontrol.stdo, 1);
	close(g_jobcontrol.stdo);
	dup2(g_jobcontrol.stde, 2);
	close(g_jobcontrol.stde);
}

void	close_fd(void)
{
	close(g_jobcontrol.stdi);
	close(g_jobcontrol.stde);
	close(g_jobcontrol.stdo);
}

void	do_in_child(int oldlink[2], int newlink[2], char ***av)
{
	(void)oldlink;
	(void)newlink;
	(void)av;
	g_jobcontrol.g_fg ? reset_attr() : 0;
	set_id_sign(g_jobcontrol.g_fg);
	fill_pipe(oldlink, newlink, av, g_jobcontrol.i);
}
