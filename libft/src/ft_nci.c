/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nci.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:24:21 by frameton          #+#    #+#             */
/*   Updated: 2020/03/02 23:02:32 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nci(int n)
{
	int c;

	c = 1;
	if (n < 0)
		c++;
	while (n / 10)
	{
		n = n / 10;
		c++;
	}
	return (c);
}