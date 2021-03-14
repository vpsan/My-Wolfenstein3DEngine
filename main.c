/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:29:03 by bhatches          #+#    #+#             */
/*   Updated: 2021/03/13 14:56:58 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strct.h"
#include "file_parse_file.h"
#include "mlx.h"

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

void	write_error_exit(void)
{
	write(2, "ERROR!", 6*sizeof(char));
	exit(0);
}

int		main(int argc, char **argv)
{
	t_game	cube;
//	int		*check_memory_leaks;
//	check_memory_leaks = (int*)malloc(1* sizeof(int*));

	if (check_argcount_argv1_extension(argc, argv) == false)
		write_error_exit();
	game_init(&cube);
	if (file_main_parsing_function(argv[1], &cube) == ERROR)
		write_error_exit();
	//screenshot_function
	game_start(&cube);

//	int i;
//	i = 0;
//	while (cube.map[i] != '\0')
//	{
//		printf("%s\n", cube.map[i]);
//		i++;
//	}
	return (0);
}
