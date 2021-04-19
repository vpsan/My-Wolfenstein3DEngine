/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcstng.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:00:24 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 16:27:59 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int 	rcstng(t_cube3D *cube)
{
	int		x;

	x = 0;
	while (x < cube->map_prmtrs.win_width)
	{
		rcstng_init_1(cube, x);
		rcstng_init_2(cube);
		rcstng_while_hit_not_zero(cube);
		rcstng_calculate_distance(cube);
		rcstng_get_wall_tex(cube);
		rcstng_calculate_wallx(cube);
		rcstng_draw_wall(cube, x);
		cube->rcstng_sprts_zbuffer[x] = cube->rcstg.perp_wall_dist;
		x++;
	}
	return (0);
}
