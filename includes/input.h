/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:03:32 by lubenard          #+#    #+#             */
/*   Updated: 2020/04/22 15:33:31 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <termios.h>
# include <sys/ioctl.h>
# include "projectinclude.h"

/*
** Termcaps structs
*/
typedef	struct		s_coord
{
	int				*coord;
	int				q_stat;
	int				i;
	int				j;
	int				k;
	int				r;
	int				t;
	int				x;
	int				y;
	int				c;
	int				cmax;
	int				*prompt;
	int				*pos;
	int				ret;
	char			*buf;
	char			*tmpy;
	char			*tmpx;
	char			*line;
	char			*tmp;
	char			**tmp1;
	char			**tmp2;
	int				mainindex;
}					t_coord;

typedef struct		s_norm
{
	int				quotes;
	char			c;
}					t_norm;

typedef	struct		s_getprompt_pos
{
	int				y;
	int				x;
	int				c;
	int				r;
	int				tmp;
	int				p;
	int				*coord;
	int				cmax;
}					t_getprompt_pos;

typedef	struct		s_w
{
	int				ws_col;
	int				ws_row;
}					t_w;

struct s_w			g_w;
char				*g_mainline;

char				*ft_strjoinfree(char *s1, char *s2);
/*
** Line edition
*/
int					ft_first_occ(char *str, char c);
int					none_asci(char *line, int check);
void				which_redir(t_coord *c);
char				**fill_with_quotes(t_coord *c, char *line, char **q_tab);
void				free_fornorme(int i, t_coord *c, char **arg_tab);
int					*tab_malloc(int *pos, int i);
int					i_is(int *prompt, int *coord);
void				clean_for_quotes(int *mainindex, int *prompt, int *pos);
char				*suppr_lastchar(char *line);
int					init(int *mainindex, int **prompt, t_coord *c);
char				*read_quit(int **prompt, int **pos, char d);
char				*heredoc(char *delim);
int					*ft_print_line(char *tmp, int **pos, int *mainindex,
	int **prompt);
int					*last_line_col(int *coord, int **prompt, char c);
int					singleton(int comp);
void				signalhandler(int signal);
void				ft_copy_paste(char *buf, int **prompt,
	int *mainindex, int **pos);
char				*copy_until(char *str, int i);
int					get_nb_line_quote(char *str);
void				left_arrow(int *mainindex, int *pos);
void				move_toword(char *buf, int *prompt, int *mainindex,
	int *pos);
int					get_row(int r, int i, int pc);
void				clean(int *prompt, int *mainindex, int *pos);
void				delete_c(int **pos, int *prompt, int *mainindex, int w);
int					go_last_row(int tmp, int maxc, int r);
void				go_first_char(int *mainindex, int *prompt, int *pos);
void				right_arrow(int *mainindex, int i, int *prompt);
void				go_last_char(int *mainindex, int i, int *prompt);
void				move_with_arrows(char *buf, int *prompt,
	int *mainindex, int *pos);
void				print_char(int *mainindex, char *buf,
	int **prompt, int **pos);
int					control_c(char *buf, int *prompt, int *coord, int r);
int					main_core(char *buf, int **prompt,
	int **pos, int *mainindex);
int					*get_coord(char *buf);
char				*get_cursor_position();
int					set_none_canon_mode(int fd);
int					reset_shell_attr(int fd);

#endif
