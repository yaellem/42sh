/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:34:39 by ymarcill          #+#    #+#             */
/*   Updated: 2020/04/29 19:20:15 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

size_t	number_size(int n)
{
	size_t	nb;

	nb = 1;
	while (n >= 10)
	{
		n = n / 10;
		nb++;
	}
	return (nb);
}

int		tab_size(char **s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	**tab_copy(char **tabl)
{
	int		i;
	int		j;
	char	**dst;

	i = 0;
	j = 0;
	if (!(dst = malloc(sizeof(char *) * (tab_size(tabl) + 1))))
		return (NULL);
	while (tabl[i])
	{
		dst[j] = ft_strdup(tabl[i++]);
		j++;
	}
	dst[j] = NULL;
	return (dst);
}
