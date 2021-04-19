/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprts_bubble_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:47:33 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 11:11:50 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	sprts_bubble_sort(t_game *cube)
{
	double	temp;
	int		i;
	int		j;

	i = 0;
	while (i < cube->sprts.num_sprites - 1)
	{
		j = cube->sprts.num_sprites - 1;
		while (j > i)
		{
			if (cube->sprts.sprite_dstnc[j - 1]
				< cube->sprts.sprite_dstnc[j])
			{
				temp = cube->sprts.sprite_dstnc[j - 1];
				cube->sprts.sprite_dstnc[j - 1] = cube->sprts.sprite_dstnc[j];
				cube->sprts.sprite_dstnc[j] = temp;
				temp = (double)cube->sprts.sprite_order[j - 1];
				cube->sprts.sprite_order[j - 1] = cube->sprts.sprite_order[j];
				cube->sprts.sprite_order[j] = (int)temp;
			}
			j--;
		}
		i++;
	}
	return (0);
}
