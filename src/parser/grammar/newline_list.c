/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 00:57:02 by mabayle           #+#    #+#             */
/*   Updated: 2020/01/21 06:00:46 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projectinclude.h"

/*
** Purpose of the function : balancing function for all case (newline_list)
** Valeur de retour : return 1 if match | else return 0
*/

int		newline_list(t_lex *lex)
{
	if (newline_list1(lex) == 1)
		return (1);
	if (newline_list2(lex) == 1)
		return (1);
	else
		return (0);
}

/*
** Purpose of the function : check if lex->value == newline_list AND
**							lex->next->value == NEW_LINE
** Valeur de retour : return 1 if match | else return 0
*/

int		newline_list1(t_lex *lex)
{
	if (lex == NULL)
		return (0);
	if (lex->next != NULL
			&& (lex->token == NEW_LINE && lex->next->token == NEW_LINE))
		return (1);
	else
		return (0);
}

/*
** Purpose of the function : check if lex->value == NEW_LINE
** Valeur de retour : return 1 if match | else return 0
*/

int		newline_list2(t_lex *lex)
{
	if (lex == NULL)
		return (0);
	else
		return (lex->token == NEW_LINE ? 1 : 0);
}
