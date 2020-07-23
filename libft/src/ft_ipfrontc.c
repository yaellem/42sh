/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipfrontc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:21:57 by frameton          #+#    #+#             */
/*   Updated: 2020/03/02 23:02:32 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ipfrontc(char *str, char c)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] == c)
			i++;
	}
	return (i);
}