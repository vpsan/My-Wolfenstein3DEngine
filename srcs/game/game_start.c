/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:59:21 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:48 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_free_double_ptr(double **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
	}
	*ptr = NULL;
	return (0);
}

int	hook_close_window(t_cube3D *cube)
{
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	ft_free_str_arr(&cube->map);
	ft_free_str(&cube->map_prmtrs.no_path);
	ft_free_str(&cube->map_prmtrs.so_path);
	ft_free_str(&cube->map_prmtrs.we_path);
	ft_free_str(&cube->map_prmtrs.ea_path);
	ft_free_str(&cube->map_prmtrs.sprts_path);
	ft_free_double_ptr(&cube->rcstng_sprts_zbuffer);
	exit(0);
	return (0);
}

int	hook_press_on_keys(int key_code, t_cube3D *cube)
{
	if (key_code == KEY_ESC)
		hook_close_window(cube);
	else if (key_code == KEY_W)
		cube->keys.w = 1;
	else if (key_code == KEY_S)
		cube->keys.s = 1;
	else if (key_code == KEY_A)
		cube->keys.a = 1;
	else if (key_code == KEY_D)
		cube->keys.d = 1;
	else if (key_code == KEY_LEFT)
		cube->keys.left = 1;
	else if (key_code == KEY_RIGHT)
		cube->keys.right = 1;
	return (0);
}

int	hook_press_off_keys(int key_code, t_cube3D *cube)
{
	if (key_code == KEY_W)
		cube->keys.w = 0;
	else if (key_code == KEY_S)
		cube->keys.s = 0;
	else if (key_code == KEY_A)
		cube->keys.a = 0;
	else if (key_code == KEY_D)
		cube->keys.d = 0;
	else if (key_code == KEY_LEFT)
		cube->keys.left = 0;
	else if (key_code == KEY_RIGHT)
		cube->keys.right = 0;
	return (0);
}

int	game_start(t_cube3D *cube)
{
	mlx_do_key_autorepeatoff(cube->mlx_ptr);
	mlx_hook(cube->win_ptr, 2, 0, hook_press_on_keys, cube);
	mlx_hook(cube->win_ptr, 3, 0, hook_press_off_keys, cube);
	mlx_hook(cube->win_ptr, 17, 0, hook_close_window, cube);
	mlx_loop_hook(cube->mlx_ptr, loop_hook_next_frame, cube);
	mlx_loop(cube->mlx_ptr);
	return (0);
}
