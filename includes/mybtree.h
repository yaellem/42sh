/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mybtree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 23:40:49 by mabayle           #+#    #+#             */
/*   Updated: 2020/03/19 01:22:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYBTREE_H
# define MYBTREE_H

# include "projectinclude.h"

/*
** ast.c
*/

void				join_job_line(t_ast *ast, int p_pos);
void				manage_pipe_bis(t_ast *ast);
void				manage_pipe(t_ast *ast);
void				simple_exec(t_ast *ast);
void				go_left_pipe(t_ast *ast, int p_pos);
void				go_right_pipe(t_ast *ast, int p_pos);
void				check_op(t_ast *ast);
void				browse_ast(t_ast *ast);
void				sub_split(t_ast *ast, int priority);
void				print_debug(t_ast *ast, int pad);
t_ast				*beta_ast(t_ast *ast, int priority);
int					build_ast(t_lex *lex, t_ast **ast);

/*
** ast_utils.c
*/
t_ast				*init_node(t_lex *lex, char *root);
void				init_priority(t_lex *lex);
t_ast				*no_root(t_lex *lex, t_ast *ast);

/*
** print_ast.c
*/
void				ft_print_value(t_ast *ast);
void				ft_print_node(t_ast *ast, char *side, int lvl);
void				ft_print_ast(t_ast *ast, char *side, int lvl);
void				ft_putast(t_ast *ast);

/*
** process_ast.c
*/
t_lex				*split_lex2(t_lex *lex, int stop);
t_lex				*split_lex3(t_lex *lex, int start);
t_ast				*create_ast2(
	t_ast *ast, t_lex *current, t_lex *right, t_lex *left);
t_ast				*create_ast(t_ast *ast, int priority);
/*
********************************************************************************
*/

/*
** ast.c
*/
void				sub_split(t_ast *ast, int priority);
int					is_in_lexer(t_lex *lex, int priority);
t_ast				*beta_ast(t_ast *ast, int priority);
void				do_to_ast(char ***tmp);
int					build_ast(t_lex *lex, t_ast **ast);

/*
** ast_utils.c
*/
t_ast				*init_node(t_lex *lex, char *root);
void				init_priority(t_lex *lex);
void				astdel(t_ast **ast);

/*
** print_ast.c
*/
void				ft_print_value(t_ast *ast);
void				ft_print_node(t_ast *ast, char *side, int lvl);
void				ft_print_ast(t_ast *ast, char *side, int lvl);
void				ft_putast(t_ast *ast);

/*
** process_ast.c
*/
t_lex				*split_lex2(t_lex *lex, int stop);
t_lex				*split_lex3(t_lex *lex, int start);
t_ast				*create_ast2(
	t_ast *ast, t_lex *current, t_lex *right, t_lex *left);
t_ast				*create_ast(t_ast *ast, int priority);

#endif
