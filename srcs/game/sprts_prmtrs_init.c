/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprts_prmtrs_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:47:40 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/20 18:29:22 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	sprts_prmtrs_init(t_cube3D *cube, int i)
{
	cube->sprts.sprite_x = cube->sprts.pos_x[cube->sprts.sprite_order[i]]
		- cube->plr.pos_x;
	cube->sprts.sprite_y = cube->sprts.pos_y[cube->sprts.sprite_order[i]]
		- cube->plr.pos_y;
	cube->sprts.inv_det = 1.0 / (cube->plr.plane_x * cube->plr.dir_y
			- cube->plr.dir_x * cube->plr.plane_y);
	cube->sprts.transform_x = cube->sprts.inv_det * (cube->plr.dir_y
			* cube->sprts.sprite_x - cube->plr.dir_x * cube->sprts.sprite_y);
	cube->sprts.transform_y = cube->sprts.inv_det * (-cube->plr.plane_y
			* cube->sprts.sprite_x + cube->plr.plane_x * cube->sprts.sprite_y);
	cube->sprts.sprite_screen_x = (int)(cube->map_prmtrs.win_width
			- cube->map_prmtrs.win_width / 2 * (1 + cube->sprts.transform_x
				/ cube->sprts.transform_y));
	cube->sprts.sprite_height = abs((int)(cube->map_prmtrs.win_height
				/ cube->sprts.transform_y));
	cube->sprts.sprite_width = abs((int)(cube->map_prmtrs.win_height
				/ cube->sprts.transform_y));
	return (0);
}
