/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcstng_calculate_distance.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:00:38 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 12:26:30 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	rcstng_calculate_distance(t_cube3D *cube)
{
	if (cube->rcstg.side == 0)
		cube->rcstg.perp_wall_dist = (cube->rcstg.map_x - cube->plr.pos_x
				+ (1 - cube->rcstg.step_x) / 2) / cube->rcstg.ray_dir_x;
	else
		cube->rcstg.perp_wall_dist = (cube->rcstg.map_y - cube->plr.pos_y
				+ (1 - cube->rcstg.step_y) / 2) / cube->rcstg.ray_dir_y;
	cube->rcstg.line_height = (int)(cube->map_prmtrs.win_height
			/ cube->rcstg.perp_wall_dist);
	cube->rcstg.draw_start = -cube->rcstg.line_height / 2
		+ cube->map_prmtrs.win_height / 2;
	if (cube->rcstg.draw_start < 0)
		cube->rcstg.draw_start = 0;
	cube->rcstg.draw_end = cube->rcstg.line_height / 2
		+ cube->map_prmtrs.win_height / 2;
	if (cube->rcstg.draw_end >= cube->map_prmtrs.win_height)
		cube->rcstg.draw_end = cube->map_prmtrs.win_height - 1;
	return (0);
}
