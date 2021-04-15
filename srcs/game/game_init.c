/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:58:08 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/15 15:38:05 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_init(t_game *cube)
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
