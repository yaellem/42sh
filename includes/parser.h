/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:57:25 by mabayle           #+#    #+#             */
/*   Updated: 2020/02/03 06:18:41 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

/*
** parser.c
*/
t_lex				*next_token(t_lex *lex);
char				*check_tokenerror(t_lex *lex);
char				*value_env(char *input, int i);
int					ft_parse(t_lex **lex);
/*
********************************************************************************
*/

/*
** parser.c
*/
t_lex				*next_token(t_lex *lex);
char				*check_tokenerror(t_lex *lex);
t_lex				*check_heredoc(t_lex *lex);
int					ft_parse(t_lex **lex);

#endif
