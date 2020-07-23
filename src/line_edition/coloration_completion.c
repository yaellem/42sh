/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloration_completion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:17:53 by frameton          #+#    #+#             */
/*   Updated: 2020/02/16 02:16:50 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

int		check_executable(struct stat s)
{
	if ((S_ISUID & s.st_mode) && (S_IXUSR & s.st_mode))
		return (1);
	if ((S_ISGID & s.st_mode) && (S_IXGRP & s.st_mode))
		return (1);
	if ((S_ISVTX & s.st_mode) && (S_IXOTH & s.st_mode))
		return (1);
	if ((S_ISUID & s.st_mode) && !(S_IXUSR & s.st_mode))
		return (1);
	if ((S_ISGID & s.st_mode) && !(S_IXGRP & s.st_mode))
		return (1);
	if ((S_ISVTX & s.st_mode) && !(S_IXOTH & s.st_mode))
		return (1);
	if ((s.st_mode & S_IXUSR))
		return (1);
	if ((s.st_mode & S_IXGRP))
		return (1);
	if ((s.st_mode & S_IXOTH))
		return (1);
	return (0);
}

void	check_clr(t_comp *cmp)
{
	if (!cmp->clr)
		ft_putstr(WHITE);
	if (cmp->clr == 1)
		ft_putstr(CYAN);
	if (cmp->clr == 2)
		ft_putstr(BYELLOW);
	if (cmp->clr == 3)
		ft_putstr(BCYAN);
	if (cmp->clr == 4)
		ft_putstr(YELLOW);
	if (cmp->clr == 5)
		ft_putstr(MAGENTA);
	if (cmp->clr == 6)
		ft_putstr(GREEN);
	if (cmp->clr == 7)
		ft_putstr(FRED);
}

int		clr_cmp(t_comp *cmp, char *path)
{
	struct stat	s;
	char		*p;

	p = NULL;
	if ((p = ft_strjoin(path, cmp->name)) == NULL)
		return (0);
	if (lstat(p, &s) == -1)
		return (sec_free(&p, 0));
	if (S_ISDIR(s.st_mode))
		return (sec_free(&p, 1));
	if (S_ISCHR(s.st_mode))
		return (sec_free(&p, 2));
	if (S_ISBLK(s.st_mode))
		return (sec_free(&p, 3));
	if (S_ISFIFO(s.st_mode))
		return (sec_free(&p, 4));
	if (S_ISLNK(s.st_mode))
		return (sec_free(&p, 5));
	if (S_ISSOCK(s.st_mode))
		return (sec_free(&p, 6));
	if (check_executable(s) == 1)
		return (sec_free(&p, 7));
	return (sec_free(&p, 0));
}
