/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frameton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:32:46 by frameton          #+#    #+#             */
/*   Updated: 2020/02/25 02:55:40 by frameton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

int			ft_myisascii(int c)
{
	if (c >= 32 && c <= 0177)
		return (1);
	return (0);
}

static int	check_op_4_b2(char **av)
{
	if (!ft_strcmp(av[2], "="))
	{
		if (!ft_strcmp(av[1], av[3]))
			return (0);
		return (1);
	}
	if (!ft_strcmp(av[2], "!="))
	{
		if (ft_strcmp(av[1], av[3]))
			return (0);
		return (1);
	}
	ft_eputstr("test: unknown condition: ");
	ft_eputendl(av[2]);
	return (1);
}

static int	check_op_4_b(char **av, int n1, int n2)
{
	if (!ft_strcmp(av[2], "-le"))
	{
		if (n1 <= n2)
			return (0);
		return (1);
	}
	if (!ft_strcmp(av[2], "-gt"))
	{
		if (n1 > n2)
			return (0);
		return (1);
	}
	if (!ft_strcmp(av[2], "-ge"))
	{
		if (n1 >= n2)
			return (0);
		return (1);
	}
	return (check_op_4_b2(av));
}

int			check_op_4(char **av, int n1, int n2)
{
	if (!ft_strcmp(av[2], "-eq"))
	{
		if (n1 == n2)
			return (0);
		return (1);
	}
	if (!ft_strcmp(av[2], "-ne"))
	{
		if (n1 != n2)
			return (0);
		return (1);
	}
	if (!ft_strcmp(av[2], "-lt"))
	{
		if (n1 < n2)
			return (0);
		return (1);
	}
	return (check_op_4_b(av, n1, n2));
}
