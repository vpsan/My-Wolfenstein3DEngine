/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprts_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:47:36 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 16:28:11 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	sprts_casting(t_cube3D *cube)
{
	int	i;

	i = 0;
	while (i < cube->sprts.num_sprites)
	{
		cube->sprts.sprite_order[i] = i;
		cube->sprts.sprite_dstnc[i] = ((cube->plr.pos_x - cube->sprts.pos_x[i])
				* (cube->plr.pos_x - cube->sprts.pos_x[i])
				+ (cube->plr.pos_y - cube->sprts.pos_y[i])
				* (cube->plr.pos_y - cube->sprts.pos_y[i]));
		i++;
	}
	sprts_bubble_sort(cube);
	return (0);
}
