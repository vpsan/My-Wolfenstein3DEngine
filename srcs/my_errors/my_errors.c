/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:01:38 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/06 12:44:23 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errors.h"

void	my_errors_init(void)
{
	g_error_arr[0] = "Error\n Error without name.\n";
	g_error_arr[1] = "Error\n Invalid argc or argv.\n";
	g_error_arr[2] = "Error\n Parsing file error.\n";
	g_error_arr[3] = "Error\n game_window_init error.\n";
	g_error_arr[4] = "Error\n game_textures_init error.\n";
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
