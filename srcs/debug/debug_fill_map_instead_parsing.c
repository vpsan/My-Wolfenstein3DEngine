/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_fill_map_instead_parsing.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:57:22 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/12 23:00:33 by valery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_fill_map_instead_parsing(t_game *cube)
{
	g_new_map[0] = "11111\0";
	g_new_map[1] = "1N001\0";
	g_new_map[2] = "10001\0";
	g_new_map[3] = "11111\0";
	g_new_map[4] = NULL;
	cube->map = g_new_map;
	return ;
}
