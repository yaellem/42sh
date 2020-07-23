/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:34:47 by geargenc          #+#    #+#             */
/*   Updated: 2020/04/22 15:19:36 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

char		**ft_exp_args_error(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	i++;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return (NULL);
}

char		**ft_expanse_args(char **args)
{
	char	*tmp;
	int		i;

	i = 0;
	while (args && args[i])
	{
		tmp = args[i];
		args[i] = ft_expanse_word(args[i]);
		free(tmp);
		if (!args[i])
			return (ft_exp_args_error(args));
		i++;
	}
	return (args);
}
