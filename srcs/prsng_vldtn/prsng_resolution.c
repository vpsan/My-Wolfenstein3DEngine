/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:12 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/17 14:45:53 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"
#include "my_errors.h"

int	vldthn_resolution_maxmin(t_game *cube)
{
	if (cube->map_prmtrs.win_height < MIN_WIN_HIEGHT
		|| cube->map_prmtrs.win_width < MIN_WIN_WIDTH
		|| cube->map_prmtrs.win_height > MAX_WIN_HIEGHT
		|| cube->map_prmtrs.win_width > MAX_WIN_WIDTH)
	{
		cube->map_prmtrs.win_width = 980;
		cube->map_prmtrs.win_height = 720;
	}
	return (0);
}

int	vldthn_resolution_digits(char **arr_split_line, int exit_number)
{
	vldthn_chech_str_is_digits(arr_split_line[1], exit_number);
	vldthn_chech_str_is_digits(arr_split_line[2], exit_number);
	return (0);
}

int	prsng_resolution(char **arr_split_line, t_game *cube)
{
	if (cube->map_prmtrs.resolution_flag == 1)
		my_exit(3);
	cube->map_prmtrs.resolution_flag = 1;
	if (vldthn_count_arrsplitline(arr_split_line) != 3)
		my_exit(3);
	vldthn_resolution_digits(arr_split_line, 3);
	cube->map_prmtrs.win_width = ft_atoi(arr_split_line[1]);
	cube->map_prmtrs.win_height = ft_atoi(arr_split_line[2]);
	vldthn_resolution_maxmin(cube);
	return (0);
}
