/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldthn_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:32 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/17 14:16:01 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	vldthn_map_coordinates(t_game *cube, int i, int j)
{
	if (ft_memchr(" 120SNWE", cube->map[i][j], 9) == 0)
		my_exit(11);
	if (ft_memchr("NSWE", cube->map[i][j], 5) != 0)
		cube->map_prmtrs.num_player++;
	if (cube->map_prmtrs.num_player > 1)
		my_exit(11);

	return (0);
}

int	vldthn_map(t_game *cube)
{
	int	i;
	int	j;

	i = 0;
	while (cube->map[i] != NULL)
	{
		j = 0;
		while (cube->map[i][j] != '\0')
		{
			vldthn_map_coordinates(cube, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
