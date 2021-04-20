/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_next_frame.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:00:00 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/20 16:20:53 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	pre_rcstng_move_player(t_cube3D *cube)
{
	if (cube->keys.w == 1)
		move_w(cube);
	if (cube->keys.s == 1)
		move_s(cube);
	if (cube->keys.d == 1)
		move_d(cube);
	if (cube->keys.a == 1)
		move_a(cube);
	if (cube->keys.right == 1)
		turn_right(cube);
	if (cube->keys.left == 1)
		turn_left(cube);
	return (0);
}

int	pre_rcstng_draw_ceiling(t_cube3D *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < cube->map_prmtrs.win_height / 2)
	{
		x = 0;
		while (x < cube->map_prmtrs.win_width)
		{
			color_pixel_fill(&cube->frame, x, y, cube->map_prmtrs.clr_clng);
			x++;
		}
		y++;
	}
	return (0);
}

int	pre_rcstng_draw_floor(t_cube3D *cube)
{
	int	x;
	int	y;

	y = cube->map_prmtrs.win_height / 2;
	while (y < cube->map_prmtrs.win_height)
	{
		x = 0;
		while (x < cube->map_prmtrs.win_width)
		{
			color_pixel_fill(&cube->frame, x, y, cube->map_prmtrs.clr_flr);
			x++;
		}
		y++;
	}
	return (0);
}

int	pre_rcstng_malloc_zbuffer(t_cube3D *cube)
{
	if (cube->rcstng_sprts_zbuffer == NULL)
	{
		cube->rcstng_sprts_zbuffer = (double *)
			malloc(cube->map_prmtrs.win_width * sizeof(double));
	}
	return (0);
}

int	loop_hook_next_frame(t_cube3D *cube)
{
	pre_rcstng_move_player(cube);
	pre_rcstng_draw_ceiling(cube);
	pre_rcstng_draw_floor(cube);
	pre_rcstng_malloc_zbuffer(cube);
	rcstng(cube);
	sprts(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr,
		cube->frame.img_ptr, 0, 0);
	return (0);
}
