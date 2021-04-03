/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcstng_while_hit_not_zero.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:01:22 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/03 12:14:10 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		rcstng_while_hit_not_zero(t_game *cube)
{
	while (cube->rcstg.hit == 0)
	{
		if (cube->rcstg.side_dist_x < cube->rcstg.side_dist_y)
		{
			cube->rcstg.side_dist_x += cube->rcstg.delta_dist_x;
			cube->rcstg.map_x += cube->rcstg.step_x;
			cube->rcstg.side = 0;
		}
		else
		{
			cube->rcstg.side_dist_y += cube->rcstg.delta_dist_y;
			cube->rcstg.map_y += cube->rcstg.step_y;
			cube->rcstg.side = 1;
		}
		if (cube->map[cube->rcstg.map_x][cube->rcstg.map_y] > '0')
			cube->rcstg.hit = 1;
	}
	return (0);
}