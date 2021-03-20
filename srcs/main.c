/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/18 15:03:13 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "file_parse.h"
#include "my_errors.h"

#include <stdbool.h>
#include <stdio.h>

int 	print_check_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}

void 	my_preparsing_init(t_game *cube)
{
	cube->map_prmtrs.win_width = 1000;
	cube->map_prmtrs.win_height = 800;

	cube->map_prmtrs.no_path = "textures/marbface.xpm";
	cube->map_prmtrs.so_path = "textures/mountains.xpm";
	cube->map_prmtrs.we_path = "textures/metal.xpm";
	cube->map_prmtrs.ea_path = "textures/brick.xpm";
	cube->map_prmtrs.sprts_path = "textures/skeleton.xpm";

	cube->no_txtr.width = 64;
	cube->no_txtr.height = 64;

	cube->so_txtr.width = 64;
	cube->so_txtr.height = 64;

	cube->we_txtr.width = 64;
	cube->we_txtr.height = 64;

	cube->ea_txtr.width = 64;
	cube->ea_txtr.height = 64;

	cube->sprts_txtr.width = 64;
	cube->sprts_txtr.height = 64;


}

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

int		main(int argc, char **argv)
{
	t_game	cube;

	my_errors_init();
	if (check_argcount_argv1_extension(argc, argv) == false)
	{
		my_errors_call(1);
		exit(1);
	}
	game_map_init(&cube);
	if (file_main_parsing_function(argv[1], &cube) == ERROR)
	{
		my_errors_call(2);
		exit(1);
	}
//	print_check_map(cube.map);
//	screenshot_function
	my_preparsing_init(&cube);
	game_init(&cube);
//	game_start(&cube, argc);
	printf("------------------------  Check ------------------------\n");
	return (0);
}
