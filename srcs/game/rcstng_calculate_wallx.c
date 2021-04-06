/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcstng_calculate_wallx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:00:45 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/06 12:44:23 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		rcstng_calculate_wallx(t_game *cube)
{
	if (cube->rcstg.side == 0)
		cube->rcstg.wall_x = cube->plr.pos_y + cube->rcstg.perp_wall_dist *
												cube->rcstg.ray_dir_y;
	else
		cube->rcstg.wall_x = cube->plr.pos_x + cube->rcstg.perp_wall_dist *
												cube->rcstg.ray_dir_x;
	cube->rcstg.wall_x = 1 - (cube->rcstg.wall_x - floor(cube->rcstg.wall_x));
	cube->rcstg.tex_x = (int)(cube->rcstg.wall_x * cube->rcstg.tex->width);
	if (cube->rcstg.side == 0 && cube->rcstg.ray_dir_x > 0)
		cube->rcstg.tex_x = cube->rcstg.tex->width - cube->rcstg.tex_x - 1;
	if (cube->rcstg.side == 1 && cube->rcstg.ray_dir_y < 0)
		cube->rcstg.tex_x = cube->rcstg.tex->width - cube->rcstg.tex_x - 1;
	cube->rcstg.tex_step =
		(double)(cube->rcstg.tex->height) / cube->rcstg.line_height;
	cube->rcstg.tex_pos =
		(cube->rcstg.draw_start - cube->map_prmtrs.win_height / 2
				+ cube->rcstg.line_height / 2) * cube->rcstg.tex_step;
	return (0);
}
