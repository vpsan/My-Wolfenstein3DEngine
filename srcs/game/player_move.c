/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:00:10 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/20 18:29:22 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	move_w(t_cube3D *cube)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cube->plr.pos_x + cube->plr.dir_x * SPEEDMOVE;
	new_pos_y = cube->plr.pos_y + cube->plr.dir_y * SPEEDMOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int	move_s(t_cube3D *cube)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cube->plr.pos_x - cube->plr.dir_x * SPEEDMOVE;
	new_pos_y = cube->plr.pos_y - cube->plr.dir_y * SPEEDMOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int	move_d(t_cube3D *cube)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cube->plr.pos_x - cube->plr.dir_y * SPEEDMOVE;
	new_pos_y = cube->plr.pos_y + cube->plr.dir_x * SPEEDMOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}

int	move_a(t_cube3D *cube)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cube->plr.pos_x + cube->plr.dir_y * SPEEDMOVE;
	new_pos_y = cube->plr.pos_y - cube->plr.dir_x * SPEEDMOVE;
	if (cube->map[(int)new_pos_x][(int)cube->plr.pos_y] == '0')
		cube->plr.pos_x = new_pos_x;
	if (cube->map[(int)cube->plr.pos_x][(int)new_pos_y] == '0')
		cube->plr.pos_y = new_pos_y;
	return (0);
}
