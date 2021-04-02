/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_preparsing_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:57:29 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/02 13:13:12 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

int		debug_map_prmtrs_init(t_game *cube)
{
	cube->map_prmtrs.win_width = 1200;
	cube->map_prmtrs.win_height = 980;
	cube->map_prmtrs.no_path = "textures/WALL11.xpm";
	cube->map_prmtrs.so_path = "textures/WALL12.xpm";
	cube->map_prmtrs.we_path = "textures/WALL13.xpm";
	cube->map_prmtrs.ea_path = "textures/WALL14.xpm";
	cube->map_prmtrs.sprts_path = "textures/skeleton.xpm";
	cube->no_txtr.width = 64;
	cube->no_txtr.height = 64;
	cube->so_txtr.width = 64;
	cube->so_txtr.height = 64;
	cube->we_txtr.width = 64;
	cube->we_txtr.height = 64;
	cube->ea_txtr.width = 64;
	cube->ea_txtr.height = 64;
	cube->sprts_txtr.width = 64;
	cube->sprts_txtr.height = 64;
	cube->map_prmtrs.clr_flr = NAVI_CLR_FLR;
	cube->map_prmtrs.clr_clng = BLACK_CLR_CLNG;
	return (0);
}
