/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprts_stripes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:47:43 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/20 18:29:22 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	sprts_stripes_draw(t_cube3D *cube)
{
	cube->sprts.d = (cube->sprts.y) * 256 - cube->map_prmtrs.win_height * 128
		+ cube->sprts.sprite_height * 128;
	cube->sprts.tex_y = ((cube->sprts.d * cube->sprts_txtr.height)
			/ cube->sprts.sprite_height) / 256;
	cube->sprts.color = ((int *)cube->sprts_txtr.addr_ptr)
	[cube->sprts_txtr.width * cube->sprts.tex_y + cube->sprts.tex_x];
	if ((cube->sprts.color & 0x00FFFFFF) != FORBIDDEN_COLOR)
		color_pixel_fill(&cube->frame, cube->sprts.stripe,
			cube->sprts.y, cube->sprts.color);
	return (0);
}

int	sprts_stripes(t_cube3D *cube)
{
	cube->sprts.stripe = cube->sprts.draw_start_x;
	while (cube->sprts.stripe < cube->sprts.draw_end_x)
	{
		cube->sprts.tex_x = (int)(256 * (cube->sprts.stripe - (-cube->sprts
						.sprite_width / 2 +cube->sprts.sprite_screen_x))
				* cube->sprts_txtr.width / cube->sprts.sprite_width) / 256;
		if (cube->sprts.transform_y > 0 && cube->sprts.stripe > 0
			&& cube->sprts.stripe < cube->map_prmtrs.win_width
			&& cube->sprts.transform_y
			        < cube->rcstng_sprts_zbuffer[cube->sprts.stripe])
		{
			cube->sprts.y = cube->sprts.draw_start_y;
			while (cube->sprts.y < cube->sprts.draw_end_y)
			{
				sprts_stripes_draw(cube);
				cube->sprts.y++;
			}
		}
		cube->sprts.stripe++;
	}
	return (0);
}
