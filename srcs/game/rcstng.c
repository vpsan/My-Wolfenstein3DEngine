/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcstng.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:00:24 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/02 13:13:12 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int 	rcstng(t_game *cube)
{
	int		x;

	x = 0;
	while (x < cube->map_prmtrs.win_width)
	{
		rcstng_init_1(cube, x);
		rcstng_init_2(cube);
		rcstng_while_hit_not_zero(cube);
		rcstng_calculate_distance(cube);
		rcstng_calculate_wallx(cube);
		rcstng_get_wall_tex(cube);
		rcstng_draw_wall(cube, x);
		x++;
	}
	return (0);
}
