/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:58:08 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/12 19:00:31 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		game_sprites_init(t_game *cube)
{
	cube->sprts.num_sprites = 1;
	cube->sprts.sprite_x = -1.0;
	cube->sprts.sprite_y = -1.0;
	cube->sprts.inv_det = -1.0;
	cube->sprts.transform_x = -1.0;
	cube->sprts.transform_y = -1.0;
	cube->sprts.sprite_screen_x = -1;
	cube->sprts.sprite_height = -1;
	cube->sprts.sprite_width = -1;
	cube->sprts.draw_start_y = -1;
	cube->sprts.draw_end_y = -1;
	cube->sprts.draw_start_x = -1;
	cube->sprts.draw_end_x = -1;
	return (0);
}

int		game_init(t_game *cube)
{
	game_window_init(cube);
	game_frame_init(cube);
	game_player_init(cube);
	game_keys_init(cube);
	game_textures_init(cube);
	game_raycasting_init(cube);
	game_sprites_init(cube);
	return (0);
}
