/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separator_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <mabayle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 23:45:56 by mabayle           #+#    #+#             */
/*   Updated: 2020/01/21 06:00:46 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projectinclude.h"

/*
** Purpose of the function : balancing function for all case (separator_op)
** Valeur de retour : return 1 if match | else return 0
*/

int		separator_op(t_lex *lex)
{
	if (separator_op1(lex) == 1)
		return (1);
	if (separator_op2(lex) == 1)
		return (1);
	else
		return (0);
}

/*
** Purpose of the function : check if lex->value == &
** Valeur de retour : return 1 if match | else return 0
*/

int		separator_op1(t_lex *lex)
{
	return (ft_strcmp(lex->value, "&") == 0 ? 1 : 0);
}

/*
** Purpose of the function : check if lex->value == ;
** Valeur de retour : return 1 if match | else return 0
*/

int		separator_op2(t_lex *lex)
{
	return (ft_strcmp(lex->value, ";") == 0 ? 1 : 0);
}
