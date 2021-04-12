/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:58:56 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/12 23:00:33 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		set_dirx_diry(t_game *cube, double dirx, double diry)
{
	cube->plr.dir_x = dirx;
	cube->plr.dir_y = diry;
	return (0);
}

int		set_planex_planey(t_game *cube, double planex, double planey)
{
	cube->plr.plane_x = planex;
	cube->plr.plane_y = planey;
	return (0);
}

int		set_player_prmtrs(t_game *cube, char plr_dir)
{
	if (plr_dir == 'N')
	{
		set_dirx_diry(cube, 0, -1);
		set_planex_planey(cube, -0.66, 0);
	}
	if (plr_dir == 'S')
	{
		set_dirx_diry(cube, 0, 1);
		set_planex_planey(cube, 0.66, 0);
	}
	if (plr_dir == 'E')
	{
		set_dirx_diry(cube, 1, 0);
		set_planex_planey(cube, 0, -0.66);
	}
	if (plr_dir == 'W')
	{
		set_dirx_diry(cube, -1, 0);
		set_planex_planey(cube, 0, 0.66);
	}
	return (0);
}

int		game_player_init(t_game *cube)
{
	int		i;
	int		j;

	i = 0;
	while (cube->map[i] != NULL)
	{
		j = 0;
		while (cube->map[i][j] != '\0')
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'S' ||
				cube->map[i][j] == 'E' || cube->map[i][j] == 'W')
			{
				cube->plr.pos_x = i;
				cube->plr.pos_y = j;
				set_player_prmtrs(cube, cube->map[i][j]);
				cube->map[i][j] = '0';
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
