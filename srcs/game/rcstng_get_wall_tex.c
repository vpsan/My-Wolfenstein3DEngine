/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcstng_get_wall_tex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:01:04 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/12 19:00:32 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		rcstng_get_wall_tex(t_game *cube)
{
	if (cube->rcstg.side == 1)
	{
		if (cube->rcstg.step_y > 0)
			cube->rcstg.tex = &cube->no_txtr;
		if (cube->rcstg.step_y < 0)
			cube->rcstg.tex = &cube->so_txtr;
	}
	if (cube->rcstg.side == 0)
	{
		if (cube->rcstg.step_x > 0)
			cube->rcstg.tex = &cube->we_txtr;
		if (cube->rcstg.step_x < 0)
			cube->rcstg.tex = &cube->ea_txtr;
	}
//	if (cube->rcstg.tex == NULL)
//		exit(111);
	return (0);
}
