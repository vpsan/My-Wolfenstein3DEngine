/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:38:14 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/10 21:38:17 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "strct.h"
#include <stdio.h>

int		file_fill_game(char **arr_split_line, t_game *cube)
{
	if (ft_memcmp(arr_split_line[0], "\n", 1) == 0)
		printf("\n");   // fun__
	else if (ft_memcmp(arr_split_line[0], "R", 1) == 0)
		printf("R\n");  // fun_R
	else if (ft_memcmp(arr_split_line[0], "NO", 1) == 0)
		printf("NO\n"); // fun_NO
	else if (ft_memcmp(arr_split_line[0], "SO", 1) == 0)
		printf("SO\n"); // fun_SO
	else if (ft_memcmp(arr_split_line[0], "WE", 1) == 0)
		printf("WE\n"); // fun_WE
	else if (ft_memcmp(arr_split_line[0], "EA", 1) == 0)
		printf("EA\n"); // fun_EA
	else if (ft_memcmp(arr_split_line[0], "S", 1) == 0)
		printf("S\n");  // fun_S
	else if (ft_memcmp(arr_split_line[0], "F", 1) == 0)
		printf("F\n");  // fun_F
	else if (ft_memcmp(arr_split_line[0], "C", 1) == 0)
		printf("C\n");  // fun_C
	else
		printf("map\n");
	return (0);
}

int		file_parse_line(char *line, t_game cube)
{
	char	**arr_split_line;

	if ((arr_split_line = ft_split(line, ' ')) == NULL)
		exit(0); // ERROR
	file_fill_game(arr_split_line, &cube);
	ft_free_str_arr(&arr_split_line);
	return (0);
}

int		file_parse_file(int fd, t_game *cube)
{
	char 	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0) // better == 1 ?
	{
		file_parse_line(line, *cube);
		ft_free_str(&line);
	}
	if (ft_strlen(line) != 0) // We need to check it !
	{
		file_parse_line(line, *cube);
		ft_free_str(&line);
	}
	return (0);
}
