/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/17 20:31:34 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "file_parse_file.h"

#include <stdbool.h>
#include <stdio.h>

int 	print_check_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int		check_argcount_argv1_extension(int argc, char **argv, t_game *cube)
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

	if (check_argcount_argv1_extension(argc, argv, &cube) == false)
		write_error_exit();
	game_map_init(&cube);
	if (file_main_parsing_function(argv[1], &cube) == ERROR)
		write_error_exit();
	print_check_map(cube.map);
//	screenshot_function
//	game_init(&cube);
//	game_start(&cube, argc);

	return (0);
}
