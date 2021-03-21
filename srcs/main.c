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
#include "my_errors.h"
#include "file_parse.h"
#include "game.h"
#include "debug_fun.h"

#include <stdbool.h>
#include <stdio.h>

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
//	if (file_main_parsing_function(argv[1], &cube) == ERROR)
//	{
//		my_errors_call(2);
//		exit(1);
//	}
	debug_fill_map_instead_parsing(&cube);
//	screenshot_function
	game_preparsing_init(&cube);
	debug_print_check_map(cube);
	printf("------------------------  Check.1 ------------------------\n");
	game_init(&cube);
	game_start(&cube, argc);
	printf("------------------------  Check.2 ------------------------\n");
	return (0);
}
