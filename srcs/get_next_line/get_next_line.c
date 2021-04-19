/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:12:10 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 16:28:30 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

/*
**	DESCRIPTION
**	get_next_line() reads line from a file descriptor
**	with defined buffer size (default 4096). Supports multiple files.
**	RETURN VALUES
**	1 : A line has been read
**	0 : EOF has been reached
**	-1 : An ERROR happend
*/

int	get_next_line(int fd, char **line)
{
	static char		*buf[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (ERROR);
	if (gnl_check_or_creat_buf(fd, buf) == ERROR)
		return (ERROR);
	*line = NULL;
	return (gnl_read_line(fd, buf, line));
}

int	gnl_check_or_creat_buf(int fd, char **buf)
{
	if (buf[fd] == NULL)
	{
		buf[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf[fd] == NULL)
		{
			return (ERROR);
		}
		buf[fd][0] = '\0';
	}
	return (TRUE);
}

int	gnl_read_line(int fd, char **buf, char **line)
{
	long long	bytes_rd;

	*line = ft_leftjoin_sep(*line, buf[fd], '\n');
	if (*line == NULL)
		return (ft_free_str(&(buf[fd])) - 1);
	while (ft_strchr(buf[fd], '\n') == NULL)
	{
		bytes_rd = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes_rd == 0 || bytes_rd == -1)
		{
			ft_free_str(&(buf[fd]));
			return ((int)bytes_rd);
		}
		buf[fd][bytes_rd] = '\0';
		*line = ft_leftjoin_sep(*line, buf[fd], '\n');
		if (*line == NULL)
			return (ft_free_str(&(buf[fd])) - 1);
	}
	buf[fd] = ft_rewrite_str(buf[fd], '\n');
	if (buf[fd] == NULL)
		return (ft_free_str(&(buf[fd])) - 1);
	return (1);
}
