/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_prmtrs_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:58:44 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 12:26:30 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_map_prmtrs_init(t_cube3D *cube)
{
	cube->map_prmtrs.win_width = 0;
	cube->map_prmtrs.win_height = 0;
	cube->map_prmtrs.no_path = NULL;
	cube->map_prmtrs.so_path = NULL;
	cube->map_prmtrs.we_path = NULL;
	cube->map_prmtrs.ea_path = NULL;
	cube->map_prmtrs.sprts_path = NULL;
	cube->map_prmtrs.clr_flr = 0;
	cube->map_prmtrs.clr_clng = 0;
	cube->map_prmtrs.resolution_flag = 0;
	cube->map_prmtrs.no_txtr_flag = 0;
	cube->map_prmtrs.so_txtr_flag = 0;
	cube->map_prmtrs.we_txtr_flag = 0;
	cube->map_prmtrs.ea_txtr_flag = 0;
	cube->map_prmtrs.sprts_txtr_flag = 0;
	cube->map_prmtrs.color_flr_flag = 0;
	cube->map_prmtrs.color_clng_flag = 0;
	cube->map_prmtrs.num_player = 0;
	return (0);
}
