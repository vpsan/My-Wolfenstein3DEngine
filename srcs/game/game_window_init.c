/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:59:49 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 16:27:34 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_window_init(t_cube3D *cube)
{
	cube->mlx_ptr = mlx_init();
	if (cube->mlx_ptr == NULL)
	{
		ft_free_str_arr(&cube->map);
		my_errors_call(13);
		exit(13);
	}
	cube->win_ptr = mlx_new_window(cube->mlx_ptr,
			cube->map_prmtrs.win_width, cube->map_prmtrs.win_height,
			"Cub3D");
	if (cube->win_ptr == NULL)
	{
		ft_free_str_arr(&cube->map);
		free(cube->mlx_ptr);
		my_errors_call(13);
		exit(13);
	}
	return (0);
}
