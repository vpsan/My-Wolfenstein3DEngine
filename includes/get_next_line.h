/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:12:06 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/31 23:06:03 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define TRUE 1
# define FALSE 0
# define ERROR -1

int			get_next_line(int fd, char **line);
int			gnl_check_or_creat_buf(int fd, char **buf);
int			gnl_read_line(int fd, char **buf, char **line);
char		*ft_leftjoin_sep(char *s1, char *s2, int value);
char		*ft_rewrite_str(char *s, int value);
//char		*ft_strchr(const char *str, int value);
//size_t		ft_strlen_sep(const char *str, int value);
//int			ft_free_str(char **s);

#endif
