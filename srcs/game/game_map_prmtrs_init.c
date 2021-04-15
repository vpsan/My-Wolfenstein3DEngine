/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map_prmtrs_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:58:44 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/15 12:57:28 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		game_map_prmtrs_init(t_game *cube)
{
	cube->map_prmtrs.win_width = 0;
	cube->map_prmtrs.win_height = 0;
	cube->map_prmtrs.no_path = NULL;
	cube->map_prmtrs.so_path = NULL;
	cube->map_prmtrs.we_path = NULL;
	cube->map_prmtrs.ea_path = NULL;
	cube->map_prmtrs.clr_flr = 0;
	cube->map_prmtrs.clr_clng = 0;
	cube->map_prmtrs.sprts_path = NULL;
	return (0);
}
