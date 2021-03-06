/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:50:59 by ymarcill          #+#    #+#             */
/*   Updated: 2019/11/29 00:53:57 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <input.h>

void	go_prev(int *mainindex, int **pos, char *tmp)
{
	int i;
	int *coord;

	i = 0;
	free(pos[0]);
	if (!(pos[0] = malloc(sizeof(int) * ft_strlenu(tmp))))
		return ;
	while (tmp[i])
	{
		coord = get_coord(get_cursor_position());
		ft_putchar_fd(tmp[i], 0);
		if (coord[1] == g_w.ws_col)
		{
			if (coord[0] == g_w.ws_row && tmp[i] != '\n')
				ft_putstr_fd("\e[S", 0);
			ft_putstr_fd("\e[E", 0);
		}
		pos[0][i] = coord[1];
		if (tmp[i] == '\n')
			ft_putchar_fd('\r', 0);
		*mainindex += 1;
		i++;
		free(coord);
	}
}

void	history_prev(int **prompt, t_hustru *big_struc,
	int **pos, int *mainindex)
{
	int		r;
	char	*tmp;

	tmp = ft_strdup(g_mainline);
	r = get_row(0, ft_strlenu(g_mainline), prompt[0][1]);
	if (big_struc->lkd_hist && big_struc->lkd_hist->prev)
	{
		clean_for_quotes(mainindex, *prompt, pos[0]);
		big_struc->lkd_hist = big_struc->lkd_hist->prev;
		free(tmp);
		tmp = ft_strdup(big_struc->lkd_hist->history);
		go_prev(mainindex, pos, tmp);
	}
	r = get_row(0, ft_strlenu(tmp), prompt[0][1]);
	r = r + get_nb_line_quote(tmp);
	if (g_w.ws_row - prompt[0][0] < r)
		prompt[0][0] -= r - (g_w.ws_row - prompt[0][0]);
	g_mainline ? free(g_mainline) : 0;
	g_mainline = ft_strdup(tmp);
	free(tmp);
}

void	history_next(int **prompt, t_hustru *big_struc,
	int **pos, int *mainindex)
{
	int		r;
	char	*tmp;

	tmp = ft_strdup(g_mainline);
	r = get_row(0, ft_strlenu(g_mainline), prompt[0][1]);
	if (big_struc->lkd_hist && big_struc->lkd_hist->next)
	{
		clean_for_quotes(mainindex, *prompt, pos[0]);
		big_struc->lkd_hist = big_struc->lkd_hist->next;
		free(tmp);
		tmp = ft_strdup(big_struc->lkd_hist->history);
		go_prev(mainindex, pos, tmp);
		r = get_row(0, ft_strlenu(tmp), prompt[0][1]);
		r = r + get_nb_line_quote(tmp);
		if (g_w.ws_row - prompt[0][0] < r)
			prompt[0][0] -= r - (g_w.ws_row - prompt[0][0]);
	}
	else if (big_struc->lkd_hist && big_struc->lkd_hist->history[0])
	{
		free(tmp);
		tmp = ft_strdup("");
	}
	free(g_mainline);
	g_mainline = ft_strdup(tmp);
	free(tmp);
}

void	move_hist(t_coord *c, t_hustru *big_struc)
{
	if (c->buf[0] == 27 && c->buf[1] == 91 && c->buf[2] == 65)
		history_prev(&c->prompt, big_struc, &c->pos, &c->mainindex);
	else if (c->buf[0] == 27 && c->buf[1] == 91 && c->buf[2] == 66)
		history_next(&c->prompt, big_struc, &c->pos, &c->mainindex);
	if (c->buf[0] == '\n')
	{
		while (big_struc->lkd_hist && big_struc->lkd_hist->next != NULL)
			big_struc->lkd_hist = big_struc->lkd_hist->next;
	}
}
