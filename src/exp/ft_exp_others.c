/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:29:55 by geargenc          #+#    #+#             */
/*   Updated: 2020/04/29 10:11:53 by geargenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

int			ft_exp_text(t_txtlist *txt)
{
	txt->data = ft_strsub(txt->data, txt->start, txt->len);
	return (0);
}

int			ft_exp_var(t_txtlist *txt)
{
	char	*var;

	if (txt->len == 1)
		return (ft_exp_text(txt));
	var = ft_strsub(txt->data, txt->start + 1, txt->len - 1);
	txt->data = ft_getvar(var);
	free(var);
	txt->data = txt->data ? ft_backslash_quotes(txt->data, txt->dquote)
		: ft_strdup("");
	return (0);
}

int			ft_ari_illegal_char(char *expr, char *illegal)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	ft_putstr_fd(expr, STDERR_FILENO);
	ft_putstr_fd(": illegal character: ", STDERR_FILENO);
	ft_putchar_fd(*illegal, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	free(expr);
	return (-1);
}

int			ft_exp_expr(t_txtlist *txt)
{
	long	res;
	char	*exp;

	txt->data = ft_strsub(txt->data, txt->start + 3, txt->len - 5);
	if ((exp = ft_strchr(txt->data, '\\')) ||
		(exp = ft_strchr(txt->data, '\'')))
		return (ft_ari_illegal_char(txt->data, exp));
	if (!(exp = ft_simple_expanse_free(txt->data)) ||
		ft_ari(exp, &res, 0))
	{
		if (exp)
			free(exp);
		return (-1);
	}
	free(exp);
	txt->data = ft_lgtoa(res);
	return (0);
}
