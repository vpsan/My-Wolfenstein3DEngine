/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcstng_draw_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:00:55 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:48 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	rcstng_draw_wall(t_cube3D *cube, int x)
{
	int		y;
	int		pixel_color;

	y = cube->rcstg.draw_start;
	while (y < cube->rcstg.draw_end)
	{
		cube->rcstg.tex_y = (int)(cube->rcstg.tex_pos)
			& (cube->rcstg.tex->height - 1);
		cube->rcstg.tex_pos += cube->rcstg.tex_step;
		pixel_color = ((int *)cube->rcstg.tex->addr_ptr)
		[cube->rcstg.tex_y * cube->rcstg.tex->width + cube->rcstg.tex_x];
		if (cube->rcstg.side == 1)
			pixel_color = (pixel_color >> 1) & 0x7F7F7F;
		color_pixel_fill(&cube->frame, x, y, pixel_color);
		y++;
	}
	return (0);
}
