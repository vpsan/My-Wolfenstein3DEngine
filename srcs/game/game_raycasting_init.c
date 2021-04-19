/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_raycasting_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:59:11 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 11:11:50 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_raycasting_init(t_game *cube)
{
	cube->rcstg.camera_x = 0;
	cube->rcstg.ray_dir_x = 0;
	cube->rcstg.ray_dir_y = 0;
	cube->rcstg.map_x = 0;
	cube->rcstg.map_y = 0;
	cube->rcstg.side_dist_x = 0;
	cube->rcstg.side_dist_y = 0;
	cube->rcstg.delta_dist_x = 0;
	cube->rcstg.delta_dist_y = 0;
	cube->rcstg.perp_wall_dist = 0;
	cube->rcstg.step_x = 0;
	cube->rcstg.step_y = 0;
	cube->rcstg.hit = 0;
	cube->rcstg.side = 0;
	cube->rcstg.line_height = 0;
	cube->rcstg.draw_start = 0;
	cube->rcstg.draw_end = 0;
	return (0);
}
