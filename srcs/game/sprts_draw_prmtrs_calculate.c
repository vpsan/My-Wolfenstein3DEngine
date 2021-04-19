/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprts_draw_prmtrs_calculate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:47:38 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 11:11:50 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int 	sprts_draw_prmtrs_calculate(t_game *cube)
{
	cube->sprts.draw_start_y = -cube->sprts.sprite_height / 2
			+ cube->map_prmtrs.win_height / 2;
	if (cube->sprts.draw_start_y < 0)
		cube->sprts.draw_start_y = 0;
	cube->sprts.draw_end_y = cube->sprts.sprite_height / 2
			+ cube->map_prmtrs.win_height / 2;
	if (cube->sprts.draw_end_y >= cube->map_prmtrs.win_height)
		cube->sprts.draw_end_y = cube->map_prmtrs.win_height - 1;
	cube->sprts.draw_start_x = -cube->sprts.sprite_width / 2
			+ cube->sprts.sprite_screen_x;
	if (cube->sprts.draw_start_x < 0)
		cube->sprts.draw_start_x = 0;
	cube->sprts.draw_end_x = cube->sprts.sprite_width / 2
			+ cube->sprts.sprite_screen_x;
	if (cube->sprts.draw_end_x >= cube->map_prmtrs.win_width)
		cube->sprts.draw_end_x = cube->map_prmtrs.win_width - 1;
	return (0);
}
