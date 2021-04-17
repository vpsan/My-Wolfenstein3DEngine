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
	{
		cube->map_prmtrs.num_player++;
	}
	if (cube->map_prmtrs.num_player > 1)
		my_exit(11);
	///////////////////////
	{
		if (cube->map[i][j] == '0' || cube->map[i][j] == '2'
		|| cube->map[i][j] == 'N' || cube->map[i][j] == 'S'
		|| cube->map[i][j] == 'W' || cube->map[i][j] == 'E')
		{
			if (i != 0 && j != 0 && j != (ft_strlen(cube->map[i]) - 1)
				&& cube->map[i + 1] != NULL)
			{
				if (ft_strlen(cube->map[i + 1]) < j ||
					ft_strlen(cube->map[i - 1]) < j)
					my_exit(2);
				if (cube->map[i + 1][j] != ' ' && cube->map[i][j + 1] != ' '
					&& cube->map[i][j + 1] != '\0')
					return (0);
				else
					my_exit(2);
			}
			else
				my_exit(2);
		}
		if (cube->map[i][j] == ' ')
		{
			if (i != 0 && j != 0 && j != ft_strlen(cube->map[i]) &&
			cube->map[i + 1] != NULL)
			{
				if (cube->map[i + 1][j] == '0' && cube->map[i][j + 1] == '0')
					my_exit(2);
			}
		}
	}
	///////////////////////
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
