/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frameton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:44:04 by frameton          #+#    #+#             */
/*   Updated: 2020/03/11 19:44:45 by frameton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/projectinclude.h"

void	check_bslash(char **save)
{
	int		c;

	c = 0;
	while (**save && **save == '\\')
	{
		++c;
		(*save)++;
	}
	if (**save && (**save == '"' || **save == '\'') && (c % 2))
		(*save)++;
}