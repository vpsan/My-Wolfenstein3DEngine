/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/12 23:05:06 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "libft.h"
#include "my_errors.h"
#include "prsng_vldtn.h"
#include "game.h"
#include "debug.h"

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

int 	check_argv2_extension(char *argv2)
{
	int argv2_len;

	argv2_len = ft_strlen(argv2);
	if (ft_strncmp(argv2, "--save", 6) == 0)
	{
		if (argv2_len == 6)
			return (true);
	}
	return (false);
}

int 	check_screenshot_flag(int argc, char **argv)
{
	if (argc != 3)
		return (false);
	if (check_argv2_extension(argv[2]) == false)
		my_exit(1);
	return (true);
}

int		main(int argc, char **argv)
{
	t_game	cube;

	my_errors_init();
	if (check_argcount_argv1_extension(argc, argv) == false)
		my_exit(1);
	game_map_init(&cube);
	game_map_prmtrs_init(&cube);
	printf("------------------------  Check.0 ------------------------\n");
	if (prsng_vldtn(argv[1], &cube) == ERROR)
		my_exit(2);
	debug_print_check_map(&cube);
	printf("------------------------  Check.1 ------------------------\n");
	if (check_screenshot_flag(argc, argv) == true)
		screenshot(&cube);
	game_init(&cube);
	game_start(&cube, argc);
	printf("------------------------  Check.2 ------------------------\n");
	return (0);
}
