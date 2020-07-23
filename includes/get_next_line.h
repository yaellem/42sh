/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frameton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 23:34:26 by frameton          #+#    #+#             */
/*   Updated: 2020/04/22 15:55:19 by ymarcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 32

typedef struct	s_gnl
{
	char			a;
	int				fd;
	struct s_gnl	*next;
}				t_gnl;

void			ft_list_clear(t_gnl **begin_list, int ind);
int				ft_list_size(t_gnl *begin_list, int c);
t_gnl			*ft_lst_new(char c, t_gnl **lst, t_gnl *sa, int fd);
int				get_next_line(const int fd, char **line);
#endif
