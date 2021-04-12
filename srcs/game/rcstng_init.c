/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcstng_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:01:13 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/12 19:00:31 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		rcstng_init_1(t_game *cube, int x_i)
{
	cube->rcstg.camera_x = 2 * (cube->map_prmtrs.win_width - x_i)
								/ (double)(cube->map_prmtrs.win_width) - 1;
	cube->rcstg.ray_dir_x =
			cube->plr.dir_x + cube->plr.plane_x * cube->rcstg.camera_x;
	cube->rcstg.ray_dir_y =
			cube->plr.dir_y + cube->plr.plane_y * cube->rcstg.camera_x;
	cube->rcstg.map_x = (int)cube->plr.pos_x;
	cube->rcstg.map_y = (int)cube->plr.pos_y;
	cube->rcstg.delta_dist_x = fabs(1 / cube->rcstg.ray_dir_x);
	cube->rcstg.delta_dist_y = fabs((1 / cube->rcstg.ray_dir_y));
	cube->rcstg.hit = 0;
	cube->rcstg.side = -1;//0
	return (0);
}

int		rcstng_init_2(t_game *cube)
{
	if (cube->rcstg.ray_dir_x < 0)
	{
		cube->rcstg.step_x = -1;
		cube->rcstg.side_dist_x =
		(cube->plr.pos_x - cube->rcstg.map_x) * cube->rcstg.delta_dist_x;
	}
	else
	{
		cube->rcstg.step_x = 1;
		cube->rcstg.side_dist_x =
		(cube->rcstg.map_x + 1.0 - cube->plr.pos_x) * cube->rcstg.delta_dist_x;
	}
	if (cube->rcstg.ray_dir_y < 0)
	{
		cube->rcstg.step_y = -1;
		cube->rcstg.side_dist_y =
		(cube->plr.pos_y - cube->rcstg.map_y) * cube->rcstg.delta_dist_y;
	}
	else
	{
		cube->rcstg.step_y = 1;
		cube->rcstg.side_dist_y =
		(cube->rcstg.map_y + 1.0 - cube->plr.pos_y) * cube->rcstg.delta_dist_y;
	}
	return (0);
}
