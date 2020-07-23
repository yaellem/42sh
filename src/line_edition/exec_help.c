/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:01:08 by frameton          #+#    #+#             */
/*   Updated: 2020/03/10 02:52:38 by frameton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

void			es7(char *s, int m)
{
	ft_ptchar('\n');
	ft_marge(m);
	ft_putstr(s);
}

static int		help_ws(int *m)
{
	struct winsize	sz;
	int				mh;

	ioctl(0, TIOCGWINSZ, &sz);
	if (sz.ws_col < 90 || sz.ws_row < 30)
	{
		ft_putstr(FRED"setcpt error : "WHITE);
		ft_putendl("window size too small.");
		return (0);
	}
	tputs(tgetstr("vi", NULL), 1, ft_ptchar);
	tputs(tgetstr("cl", NULL), 1, ft_ptchar);
	*m = sz.ws_col - 84;
	mh = sz.ws_row - 29;
	*m = *m / 2;
	mh = mh / 2;
	while (mh--)
		tputs(tgetstr("do", NULL), 1, ft_ptchar);
	return (1);
}

static void		write_anim(int i)
{
	tputs(tgetstr("im", NULL), 1, ft_ptchar);
	clr_shell(g_jobcontrol.s.clr);
	ft_putstr("_");
	fp("ei", "rc");
	while (i--)
		tputs(tgetstr("le", NULL), 1, ft_ptchar);
	clr_shell(g_jobcontrol.s.clr);
	ft_putstr("_");
	tputs(tgetstr("rc", NULL), 1, ft_ptchar);
}

static void		anim_cpt(int m, int lr, int c, int i)
{
	int		s;

	ft_marge(m + 42);
	clr_shell(g_jobcontrol.s.clr);
	s = lr;
	while (c)
	{
		tputs(tgetstr("sc", NULL), 1, ft_ptchar);
		write_anim(i);
		while (lr--)
			tputs(tgetstr("do", NULL), 1, ft_ptchar);
		lr = s;
		s = m + 42;
		while (s--)
			tputs(tgetstr("nd", NULL), 1, ft_ptchar);
		s = lr;
		tputs(tgetstr("sc", NULL), 1, ft_ptchar);
		write_anim(i);
		while (lr--)
			tputs(tgetstr("up", NULL), 1, ft_ptchar);
		lr = s;
		++i;
		--c;
		usleep(10000);
	}
}

int				exec_sethelp(void)
{
	int				m;
	char			buf[1];

	fp("cl", "vi");
	m = 0;
	tgetent(NULL, getenv("TERM"));
	if (!(help_ws(&m)))
		return (1);
	anim_cpt(m, 28, 42, 1);
	exec_help2(m);
	es7("Search history: ", m + 30);
	clr_shell(g_jobcontrol.s.clr);
	ft_putstr("ctrl + r"WHITE);
	ft_putstr("\n\n");
	ft_marge(m + 10);
	clr_shell(g_jobcontrol.s.clr);
	ft_putstr("Warning: "WHITE);
	ft_putstr("The copy/paste from an external source does not work");
	read(0, &buf, 1);
	fp("ve", "cl");
	return (0);
}
