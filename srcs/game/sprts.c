/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:47:46 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/16 21:47:48 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		sprts(t_game *cube, double *zbuffer)
{
	int i;
	int j;

	sprts_casting(cube);
	i = 0;
	while (i < cube->sprts.num_sprites)
	{
		sprts_prmtrs_init(cube, i);
		sprts_draw_prmtrs_calculate(cube);
		sprts_stripes(cube, zbuffer);
		i++;
	}
	return (0);
}
