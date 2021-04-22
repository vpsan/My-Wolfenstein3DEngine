/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldthn_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:32 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/22 19:47:48 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	vldthn_map_coordinates_space(t_cube3D *cube, size_t i, size_t j)
{
	if (i != 0 && j != 0 && j != ft_strlen(cube->map[i])
		&& cube->map[i + 1] != NULL)
	{
		if (cube->map[i + 1][j] == '0' && cube->map[i][j + 1] == '0')
		{
			my_exit(11);
		}
	}
	return (0);
}

int	vldthn_map_coordinates_02NSWE(t_cube3D *cube, size_t i, size_t j)
{
	if (i != 0 && j != 0 && j != (ft_strlen(cube->map[i]) - 1)
		&& cube->map[i + 1] != NULL)
	{
		if (ft_strlen(cube->map[i + 1]) < j
			|| ft_strlen(cube->map[i - 1]) < j)
			my_exit(11);
		if (cube->map[i + 1][j] != ' ' && cube->map[i][j + 1] != ' '
		&& cube->map[i][j + 1] != '\0')
			return (0);
		else
			my_exit(11);
	}
	else
	{
		my_exit(11);
	}
	return (0);
}

int	vldthn_map_coordinates(t_cube3D *cube, size_t i, size_t j)
{
	if (ft_memchr(" 120NSWE", cube->map[i][j], 9) == NULL)
		my_exit(11);
	if (ft_memchr("NSWE", cube->map[i][j], 5) != NULL)
		cube->map_prmtrs.num_player++;
	if (cube->map[i][j] == '0' || cube->map[i][j] == '2'
		|| cube->map[i][j] == 'N' || cube->map[i][j] == 'S'
		|| cube->map[i][j] == 'W' || cube->map[i][j] == 'E')
		vldthn_map_coordinates_02NSWE(cube, i, j);
	if (cube->map[i][j] == ' ')
		vldthn_map_coordinates_space(cube, i, j);
	return (0);
}

int	vldthn_map(t_cube3D *cube)
{
	size_t	i;
	size_t	j;

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
	if (cube->map_prmtrs.num_player != 1)
		my_exit(11);
	return (0);
}
