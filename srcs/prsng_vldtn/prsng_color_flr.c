/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prsng_color_flr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:48:04 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/19 12:26:30 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prsng_vldtn.h"

int	vldthn_color_flr_digits(char **arr_split_line, int exit_number)
{
	vldthn_chech_str_is_digits(arr_split_line[0], exit_number);
	vldthn_chech_str_is_digits(arr_split_line[1], exit_number);
	vldthn_chech_str_is_digits(arr_split_line[2], exit_number);
	return (0);
}

int	prsng_color_flr(char **arr_split_line, t_cube3D *cube)
{
	int		red;
	int		green;
	int		blue;
	char	**color_arr;

	if (cube->map_prmtrs.color_flr_flag == 1)
		my_exit(9);
	cube->map_prmtrs.color_flr_flag = 1;
	if (vldthn_count_arrsplitline(arr_split_line) != 2)
		my_exit(9);
	color_arr = ft_split(arr_split_line[1], ',');
	if (vldthn_count_arrsplitline(color_arr) != 3)
		my_exit(9);
	if (vldthn_count_points(arr_split_line[1]) != 2)
		my_exit(9);
	vldthn_color_flr_digits(color_arr, 9);
	red = ft_atoi(color_arr[0]);
	green = ft_atoi(color_arr[1]);
	blue = ft_atoi(color_arr[2]);
	vldthn_make_rgb(&cube->map_prmtrs.clr_flr, red, green, blue);
	ft_free_str_arr(&color_arr);
	return (0);
}
