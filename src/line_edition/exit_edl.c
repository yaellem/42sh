/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_edl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 23:48:48 by frameton          #+#    #+#             */
/*   Updated: 2020/03/25 00:56:05 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

static void	file_history2(t_htr **tmp, t_htr **del, t_struct *s)
{
	while ((*tmp = *del))
	{
		(*del) = (*del)->next;
		free((*tmp)->name);
		free(*tmp);
	}
	sec_free(&s->cmd, 0);
	sec_free(&s->cpcl, 0);
}

static void	file_history3(t_struct *s, int fd)
{
	char	c;
	char	*c2;

	c2 = NULL;
	c = s->cpt + 48;
	write(fd, &c, 1);
	write(fd, "\n", 1);
	if (s->clr > 9)
	{
		c2 = ft_itoa(s->clr);
		write(fd, c2, ft_strlen(c2));
		write(fd, "\n", 1);
		free(c2);
	}
	else
	{
		c = s->clr + 48;
		write(fd, &c, 1);
		write(fd, "\n", 1);
	}
	c = s->ci + 48;
	write(fd, &c, 1);
	write(fd, "\n", 1);
}

static int	file_history(t_htr *h, t_htr **del, t_struct *s, int fd)
{
	t_htr	*tmp;
	char	*p;

	p = NULL;
	if (h)
	{
		if ((p = ft_strjoin(s->start_pwd, "/.history")) == NULL)
			return (sec_free(&p, 0));
		if ((fd = open(p, O_WRONLY | O_CREAT, 0644)) == -1)
			return (sec_free(&p, 0));
		file_history3(s, fd);
		while (h)
		{
			write(fd, h->name, ft_strlen(h->name));
			write(fd, "\n", 1);
			h = h->next;
		}
		close(fd);
	}
	file_history2(&tmp, del, s);
	return (sec_free(&p, 1));
}

static void	ft_exit3(t_struct *s)
{
	t_lst2	*del;

	del = NULL;
	while ((del = (*s).env))
	{
		(*s).env = (*s).env->next;
		free(del->env);
		free(del->varn);
		free(del->var);
		free(del);
	}
	free((*s).env_path);
	free_dchar(&(*s).builtin_ref);
}

void		exit_edl(t_struct *s, char **cmd)
{
	t_lst	*del;

	if (cmd[1] && (!is_strdigit(cmd[1]) || cmd[1][0] == '-' || cmd[2]))
	{
		error_exit("exit: 1 only arg : unsigned digit");
		return ;
	}
	while ((del = (*s).lbg))
	{
		(*s).lbg = (*s).lbg->next;
		free(del);
	}
	file_history(s->h, &s->h, s, 0);
	ft_exit3(&*s);
	reset_attr();
	if (g_jobcontrol.sim == 0)
		delete_job(g_jobcontrol.first_mail);
	astdel(&g_shell->ast);
	if (cmd[1])
		exit(ft_atoi(cmd[1]));
	else
		exit(g_jobcontrol.ret);
}
