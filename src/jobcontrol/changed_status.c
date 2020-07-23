/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changed_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 00:14:55 by ymarcill          #+#    #+#             */
/*   Updated: 2020/04/22 15:12:45 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projectinclude.h"

void	if_stp(t_job *job, int i)
{
	if (i)
	{
		ft_putchar_fd('[', 2);
		ft_putnbr_fd(job->j_nb, 2);
		ft_putstr_fd("]+	", 2);
	}
	ft_putstr_fd("[", 2);
	ft_putnbr_fd(job->pgid, 2);
	ft_putstr_fd("] ", 2);
	if (i && job->first_process->status <= 0)
		ft_putstr_fd(" Done", 2);
	else
		ft_putstr_fd(" Terminated ", 2);
	signal_print(job->first_process->status);
	ft_putstr_fd(":	", 2);
	i ? ft_putstr_fd(job->command, 2) :
		ft_putstr_fd(job->first_process->cmd, 2);
	ft_putchar_fd('\n', 2);
	put_last_fg(put_last_stp(job, 2, 1), 1, 0);
}

t_job	*print_and_del(t_job *job, int i, int check)
{
	t_job		*save;

	save = job;
	if (i != 0 && i == check)
	{
		if (job->stop == 1 || job->fg == 0)
			if_stp(job, 1);
		save = delete_link(job->pgid);
		if (!save && g_jobcontrol.first_mail)
			save = job;
	}
	else if (job && job->fg == 1 && job->stop != 1)
	{
		print_jc_info(job);
		save = delete_link(job->pgid);
		if (!save && g_jobcontrol.first_mail)
			save = job;
	}
	return (save);
}

t_job	*check_bg_status(t_job *job)
{
	int			check;
	int			i;
	t_process	*p;

	i = 0;
	check = 0;
	p = job->first_process;
	while (p)
	{
		i++;
		if ((job->fg == 0 || job->stop == 1) && (p->status > 1
			|| p->status == -1))
			check++;
		p = p->next;
	}
	job = print_and_del(job, i, check);
	return (job);
}

void	status_builtin(t_process *pro)
{
	t_process *p;

	p = pro;
	while (pro && p)
	{
		if (p && p->lpid < 0)
			p->status = p->r_value;
		p = p->next;
	}
}

void	browse_process(t_process *pro, t_job *cpy)
{
	int		status;
	pid_t	pid;

	status = 0;
	pid = 0;
	while (pro)
	{
		if (pro->lpid > 0)
		{
			pid = waitpid(pro->lpid, &status, WUNTRACED
					| WNOHANG);
			if (pro && pro->lpid == pid)
			{
				process_status(pro->lpid, status, pro);
				if (pro->status == 1)
					check_if_stop(pro, cpy);
				break ;
			}
		}
		pro = pro->next;
	}
}
