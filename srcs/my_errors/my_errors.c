/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:01:38 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/17 13:42:57 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errors.h"

void	my_errors_init(void)
{
	g_error_arr[0] = "Error\n Error without name.\n";
	g_error_arr[1] = "Error\n Invalid argc or argv.\n";
	g_error_arr[2] = "Error\n Parsing file error.\n";
	g_error_arr[3] = "Error\n Parsing file error. Resolution.\n";
	g_error_arr[4] = "Error\n Parsing file error. No_txtr.\n";
	g_error_arr[5] = "Error\n Parsing file error. So_txtr.\n";
	g_error_arr[6] = "Error\n Parsing file error. We_txtr.\n";
	g_error_arr[7] = "Error\n Parsing file error. Ea_txtr.\n";
	g_error_arr[8] = "Error\n Parsing file error. Sprite_txtr.\n";
	g_error_arr[9] = "Error\n Parsing file error. Color_flr.\n";
	g_error_arr[10] = "Error\n Parsing file error. Color_clng.\n";
	g_error_arr[11] = "Error\n Parsing file error. Map validathion.\n";
	g_error_arr[12] = "Error\n Parsing file error. Sprites validathion.\n";
	g_error_arr[13] = "Error\n game_window_init error.\n";
	g_error_arr[14] = "Error\n game_textures_init/rcstng_get_wall_tex error.\n";
	g_error_arr[15] = "Error\n Too many sprites in map.cub.\n";
	g_error_arr[19] = "Error\n screenshot() error.\n";
	return ;
}

void	my_errors_call(int number)
{
	write(2, g_error_arr[number], ft_strlen(g_error_arr[number]));
	return ;
}

void 	my_exit(int number)
{
	my_errors_call(number);
	exit(number);
	return ;
}
