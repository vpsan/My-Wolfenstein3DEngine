/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_frame_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhatches <bhatches@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:58:01 by bhatches          #+#    #+#             */
/*   Updated: 2021/04/20 16:20:26 by bhatches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	game_frame_init(t_cube3D *cube)
{
	cube->frame.img_ptr = mlx_new_image(cube->mlx_ptr,
			cube->map_prmtrs.win_width, cube->map_prmtrs.win_height);
	cube->frame.addr_ptr = mlx_get_data_addr(cube->frame.img_ptr,
			&cube->frame.bits_per_pixel, &cube->frame.size_line,
			&cube->frame.endian);
	return (0);
}
