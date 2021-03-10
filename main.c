/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/10 15:30:27 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strct.h"
#include "get_next_line.h"
#include "map_parser.h"
#include "mlx.h"

#include <stdbool.h>
#include <fcntl.h>
//#include <stdio.h>

int		check_argcount_argv1_extension(int argc, char **argv)
{
	int argv1_len;
	
	if (argc < 2 || argc > 3)
		return (false);
	argv1_len = ft_strlen(argv[1]);
	while (argv1_len-- != 0)
	{
		if (argv[1][argv1_len] == '.')
		{
			if (ft_strncmp(argv[1] + argv1_len, ".cub", 4) == 0)
				return (true);
		}
	}
	return (false);
}

void	write_error_exit(void)
{
	write(2, "ERROR!", 6*sizeof(char));
	exit(0);
}

int		main(int argc, char **argv)
{
	t_game	cube;
	int		fd;

	if (check_argcount_argv1_extension(argc, argv) == false)
		write_error_exit();
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		write_error_exit();
	//game_init(&cube);
	map_parser(fd, &cube);
	close(fd);
	return (0);
}
